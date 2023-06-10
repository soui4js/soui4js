import * as soui4 from "soui4";
import * as os from "os";
import * as std from "std";

var g_workDir="";
const g_isX64=soui4.IsX64();

class AppLvAdapter extends soui4.SLvAdapter{
	constructor(mainDlg){
		super();
		this.mainDlg = mainDlg;
		this.onGetView= this.getView;
		this.onGetCount = this.getCount;
		this.appList = []; //prepare a app list.
	}

	getView(pos,pItem,pTemplate){
		if(pItem.GetChildrenCount()==0){
			pItem.InitFromXml(pTemplate);
		}
		let appInfo = this.appList[pos];
		let wndName = pItem.FindIChildByName("txt_name");
		if(appInfo.alias=="")
			wndName.SetWindowText(appInfo.name);
		else
			wndName.SetWindowText(appInfo.alias);
		let wndVer = pItem.FindIChildByName("txt_ver");
		wndVer.SetWindowText(appInfo.ver);
		let wndMd5 = pItem.FindIChildByName("txt_md5");
		wndMd5.SetWindowText(appInfo.md5);
		let wndDesc = pItem.FindIChildByName("txt_desc");
		wndDesc.SetWindowText(appInfo.desc);
		let wndSize = pItem.FindIChildByName("txt_size");
		wndSize.SetWindowText(appInfo.size);
		if(appInfo.img!=null){
			let wndImg = pItem.FindIChildByName("img_icon");
			let imgApi = soui4.QiIImageWnd(wndImg);
			imgApi.SetImage(appInfo.img,1);
			imgApi.Release();
		}
		soui4.SConnect(pItem,10000+11,this,this.OnItemDblClick);
	}

	OnItemDblClick(e){
		let pItem = soui4.toSWindow(e.Sender());
		let pItemPanel = soui4.QiIItemPanel(pItem);
		let iApp = pItemPanel.GetItemIndex();
		pItemPanel.Release();
		let appInfo = this.appList[iApp];
		this.mainDlg.onRunApp(appInfo);
	}

	getCount(){
		return this.appList.length;
	}

	LoadFromUrl(url){
		this.httpReq = new soui4.HttpRequest(url,"get");
		this.httpReq.cbHandler = this;
		this.httpReq.onResp = this.onAppInfoResp;
		this.httpReq.onError = this.onAppInfoError;
		this.httpReq.Execute();
	}

	onAppInfoResp(ctx,code,resp){
		let xml = new soui4.SXmlDoc();
		let res = xml.LoadString(resp,116);//116=parse_default
		if(res!=0){
			let xmlApp = xml.Root().FirstChild().FirstChild();
			while(!xmlApp.IsEmpty()){
				let name = xmlApp.Name();
				let alias="";
				let attrName = xmlApp.Attribute("name",false);
				if(!attrName.IsEmpty()){
					alias = attrName.Value();
				}
				let attrPlatform = xmlApp.Attribute("platform",false);
				let bValidPlatform = true;
				if(!attrPlatform.IsEmpty()){
					let strPlatform = attrPlatform.Value();
					if(g_isX64 && strPlatform.indexOf("x64")==-1)
						bValidPlatform = false;
					else if(!g_isX64 && strPlatform.indexOf("x86")==-1)
						bValidPlatform = false;
				}
				if(bValidPlatform){
					let url = xmlApp.Attribute("url",false).Value();
					let ver = xmlApp.Attribute("ver",false).Value();
					let icon = xmlApp.Attribute("icon",false).Value();
					let md5 = xmlApp.Attribute("md5",false).Value();
					let desc = xmlApp.Attribute("desc",false).Value();
					let size = xmlApp.Attribute("size",false).Value();
					let appInfo = {"name":name,"alias":alias,"url":url,"ver":ver,"icon":icon,"md5":md5,"desc":desc,"img":null,"size":size};
					this.appList.push(appInfo);
				}else{
					console.log("disable app",name,"for isX64",g_isX64);
				}
				xmlApp = xmlApp.NextSibling();
			}
			this.notifyDataSetChanged();
			this.loadAppIcon(0);
		}
	}

	onIconResp(ctx,code,resp){
		let iApp = ctx;
		let appInfo = this.appList[iApp];
		let theApp = soui4.GetApp();
		let localUrl = g_workDir + "\\cache\\app_"+iApp+".png";
		let img = theApp.LoadImage("file:"+localUrl);
		if(img!=0){
			appInfo.img = img;
			this.notifyItemDataChanged(iApp);
		}
		this.loadAppIcon(iApp+1);//load next icon.
	}
	onIconError(ctx,errCode){
		soui4.log("download icon:"+ctx+" failed!");
		this.loadAppIcon(ctx+1);//load next icon.
	}

	loadAppIcon(iApp){
		if(iApp==this.appList.length)
			return;
		let appInfo = this.appList[iApp];
		if(this.reqIcon != undefined){
			this.reqIcon.cbHandler = 0;
			this.reqIcon = null;
		}
		this.reqIcon = new soui4.HttpRequest(appInfo.icon,"get");
		this.reqIcon.SetTimeout(5000,5000,5000);
		this.reqIcon.SetOpaque(iApp);
		this.reqIcon.cbHandler = this;
		this.reqIcon.onResp = this.onIconResp;
		this.reqIcon.onError = this.onIconError;
		os.mkdir(g_workDir + "\\cache");
		let localUrl = g_workDir + "\\cache\\app_"+iApp+".png";
		this.reqIcon.DownloadFile(localUrl);
	}

	onAppInfoError(ctx,errCode){
		soui4.log("download applist failed");
		soui4.SMessageBox(soui4.GetActiveWindow(),"download applist failed","error",0);
	}

	uninit(){
		if(this.httpReq != undefined){
			this.httpReq.cbHandler = 0;
			this.httpReq = null;
		}
		if(this.reqIcon != undefined){
			this.reqIcon.cbHandler = 0;
			this.reqIcon = null;
		}
		for(let i=0;i<this.appList.length;i++){
			let appInfo=this.appList[i];
			if(appInfo.img!=null){
				appInfo.img.Release();
				appInfo.img=null;
			}
		}
	}
};

class MainDialog extends soui4.JsHostWnd{
	constructor(){
		super("layout:dlg_main");
		this.onEvt = this.onEvent;
		this.isLoading = false;
	}

	onInit(){
		let lv_applist=this.FindIChildByName("lv_applist");
		let lvapi = soui4.QiIListView(lv_applist);
		this.lvAdapter = new AppLvAdapter(this);
		lvapi.SetAdapter(this.lvAdapter);
		lvapi.Release();
		this.lvAdapter.LoadFromUrl("https://soui4js.com/applist.xml");
	}

	onUnit(){
		if(this.isLoading){
			//cancel
			this.download.Cancel();
		}
		let lv_applist=this.FindIChildByName("lv_applist");
		let lvapi = soui4.QiIListView(lv_applist);
		lvapi.SetAdapter(0);
		lvapi.Release();
		this.lvAdapter.uninit();
		this.lvAdapter= null;

		if(this.download != undefined){
			this.download.cbHandler = 0;
			this.download = null;
		}
		if(this.extractor != undefined){
			this.extractor.cbHandler = 0;
			this.extractor = null;
		}
	}

	onEvent(e){
		if(e.GetID()==soui4.EVT_INIT){//event_init
			this.onInit();
		}else if(e.GetID()==soui4.EVT_EXIT)//event_exit
		{
			this.onUnit();
		}else if(e.GetID()==soui4.EVT_CMD && e.Sender().GetID()==10){
			this.DestroyWindow();
			this.onEvt = 0;
		}
		return false;
	}


	onRunApp(appInfo){
		if(this.isLoading)
		{
			soui4.SMessageBox(this.GetHwnd(),"程序加载中...","错误",0);
			return;
		}
		let infoPath=g_workDir + "\\"+appInfo.name+"\\appInfo.json";
		let bDownNow=true;
		try{
			let strAppInfo = std.loadFile(infoPath);
			soui4.log("appInfo:"+strAppInfo);
			let appInfoLocal = JSON.parse(strAppInfo);
			if(appInfo.md5==appInfoLocal.md5)
			{
				bDownNow=false;
			}else{
				//remove cache
				soui4.DelDir(g_workDir + "\\"+appInfo.name);
			}
		}catch(e){
			soui4.log("load file failed,err="+e.toString());
		}
		if(!bDownNow){
			//open app directly.
			let localPath = "\""+g_workDir + "\\"+appInfo.name+"\"";
			soui4.Fork(localPath);
		}else{
			this.isLoading = true;
			this.download = new soui4.HttpRequest(appInfo.url,"get");
			this.download.SetTimeout(5000,5000,5000);
			this.download.cbHandler = this;
			this.download.onProg = this.onDownloadProg;
			this.download.onResp = this.onDownloadResp;
			this.download.onError = this.onDownloadError;
			this.download.SetOpaque(100);
			os.mkdir(g_workDir+"\\cache");
			this.appInfo = appInfo;
			this.localFile = g_workDir + "\\cache\\"+appInfo.name+".zip";
			this.download.DownloadFile(this.localFile);
		}
	}

	onDownloadResp(ctx,code,resp){
		soui4.log("onDownloadResp, code="+code);
	}
	onDownloadError(ctx,errCode){
		soui4.log("onDownloadResp, errCode="+errCode);
	}

	doExtractor(){
		this.extractor = new soui4.SZipExtractor();
			if(this.extractor.Open(true,this.localFile,""))
			{
				this.extractor.cbHandler = this;
				this.extractor.onMsg = this.onExtractMsg;
				let destDir = g_workDir+"\\"+this.appInfo.name;
				os.mkdir(destDir);
				this.extractor.ExtractTo(destDir);
			}else{
				soui4.log("open zip failed!");
			}

	}

	onDownloadProg(ctx,state,szAll,szLoaded){
		let progWnd = this.FindIChildByName("prog_download");
		let iprog = soui4.QiIProgress(progWnd);
		if(state == 0)//start
		{
			iprog.SetRange(0,szAll);
			iprog.SetValue(0);
		}else if(state == 1)//loading
		{
			iprog.SetValue(szLoaded);
		}else if(state == 2)//finish
		{//extract zip to dir.
			this.doExtractor();
			this.isLoading = false;
		}else{
			this.isLoading = false;
			soui4.SMessageBox(this.GetHwnd(),"download file failed","error",0);
		}
		iprog.Release();
	}

	onExtractMsg(state,p1,p2){
		let progWnd = this.FindIChildByName("prog_extract");
		let iprog = soui4.QiIProgress(progWnd);
		if(state==0){
			//get file count
			iprog.SetRange(0,p1);
		}else if(state==1){
			//prog
			iprog.SetValue(p1);
		}else if(state==2){
			soui4.log("onExtractMsg, Result="+p1);
			if(p1==1){
				//try to open.
				let strAppInfo = JSON.stringify(this.appInfo);
				let localAppInfo = g_workDir + "\\"+this.appInfo.name+"\\appInfo.json";
				let f = std.open(localAppInfo, "w");
				f.puts(strAppInfo);
				f.close();

				let localPath = "\""+g_workDir + "\\"+this.appInfo.name+"\"";
				soui4.Fork(localPath);
			}else{
				soui4.SMessageBox(this.GetHwnd(),"extract failed!","error",0);
			}
		}
		iprog.Release();
	}
};


function main(inst,workDir,args)
{
	soui4.log(workDir);
	g_workDir = workDir;
	let theApp = soui4.GetApp();
	let souiFac = soui4.CreateSouiFactory();
	//*
	let resProvider = souiFac.CreateResProvider(1);
	soui4.InitFileResProvider(resProvider,workDir + "\\uires");
	//*/
	/*
	// show how to load resource from a zip file
	let resProvider = soui4.CreateZipResProvider(theApp,workDir +"\\uires.zip","souizip");
	if(resProvider === 0){
		soui4.log("load res from uires.zip failed");
		return -1;
	}
	//*/
	let resMgr = theApp.GetResProviderMgr();
	resMgr.AddResProvider(resProvider,"uidef:xml_init");
	resProvider.Release();
	let hwnd = soui4.GetActiveWindow();
	let hostWnd = new MainDialog();
	hostWnd.Create(hwnd,0,0,0,0);
	hostWnd.SendMessage(0x110,0,0);//send init dialog message.
	hostWnd.ShowWindow(1); //1==SW_SHOWNORMAL
	souiFac.Release();
	let ret= theApp.Run(hostWnd.GetHwnd());
	hostWnd=null;
	soui4.log("js quit");
	return ret;
}

globalThis.main=main;