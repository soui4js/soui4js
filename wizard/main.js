import * as soui4 from "soui4";
import * as utiles from "utils.dll"
import * as os from "os";
import * as std from "std";

var g_workDir="";

class MainDialog extends soui4.JsHostWnd{
	constructor(){
		super("layout:dlg_main");
		this.onEvt = this.onEvent;
		this.edit_folder=null;
	}

	onEvent(e){
		if(e.GetID()==soui4.EVT_INIT){//event_init
			this.init();
		}else if(e.GetID()==soui4.EVT_EXIT){
			this.uninit();
		}
		return false;
	}
	
	onBtnCreate(e){
		let strDest = this.edit_folder.GetWindowText(true);
		console.log("create a new soui4js project at "+strDest);
		if(strDest==""){
			soui4.SMessageBox(this.GetHwnd(),"请先选择项目路径!","提示",soui4.MB_OK|soui4.MB_ICONWARNING);
			return;
		}
		//*
		//copy template files
		if(!utiles.CopyDir(g_workDir+"\\template\\*.*",strDest)){
			soui4.SMessageBox(this.GetHwnd(),"复制向导文件失败,请检查目标位置写入权限!","提示",soui4.MB_OK|soui4.MB_ICONWARNING);
			return;			
		}
		//code node_modules
		utiles.CopyDir(g_workDir+"\\..\\node_modules",strDest);
		//*/
		//prepare task.json
		let pos = g_workDir.lastIndexOf("\\");
		let workDir = g_workDir.substring(0,pos);
		os.mkdir(strDest+"\\.vscode");
		{

		let soui4js_host = workDir+"/bin/soui4js-host.exe";
		let launch={
		    "version": "0.2.0",
		    "configurations": [
		        {
		            "name": "Launch QuickJS",
		            "type": "quickjs",
		            "request": "launch",
		            "program": "${workspaceFolder}",
		            "runtimeExecutable": soui4js_host,
		            "address": "localhost",
		            "port": 58585
		        }
		        ]
		    };

		let luanchStr = JSON.stringify(launch);
		let f = std.open(strDest+"\\.vscode\\launch.json", "w");
		f.puts(luanchStr);
		f.close();
		}
		//luanch vscode
		soui4.ShellExecute(this.GetHwnd(),"open","code.cmd", "-n --new-window "+strDest,strDest,soui4.SW_SHOWNORMAL);
	}

	onBtnPickFolder(e){
		let dir = soui4.PickFolder("");
		if(dir!=""){
			this.edit_folder.SetWindowText(dir);
		}
	}

	onBtnSetEnv(e){
		let code = soui4.RunAsAdmin(g_workDir,"set_env.js",true);
		if(code != 0)
		{
			soui4.SMessageBox(this.GetHwnd(),"设置环境变量失败","错误",soui4.MB_OK|soui4.MB_ICONERROR);
		}else{
			soui4.SMessageBox(this.GetHwnd(),"设置环境变量成功","提示",soui4.MB_OK|soui4.MB_ICONINFORMATION);
		}
	}

	init(){
		console.log("init");
		soui4.SConnect(this.FindIChildByName("btn_create"),soui4.EVT_CMD,this,this.onBtnCreate);
		soui4.SConnect(this.FindIChildByName("btn_pick_folder"),soui4.EVT_CMD,this,this.onBtnPickFolder);
		soui4.SConnect(this.FindIChildByName("btn_set_env"),soui4.EVT_CMD,this,this.onBtnSetEnv);
		this.edit_folder = this.FindIChildByName("edit_folder");
	}
	uninit(){
		//do uninit.
		console.log("uninit");
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
	hostWnd.ShowWindow(soui4.SW_SHOWNORMAL); 
	souiFac.Release();
	let ret= theApp.Run(hostWnd.GetHwnd());
	hostWnd=null;
	soui4.log("js quit");
	return ret;
}

globalThis.main=main;