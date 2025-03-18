import * as soui4 from "soui4";

function main(inst,workDir,args)
{
	soui4.log(workDir);
    if(!soui4.IsRunAsAdmin())
    {
        console.log("request admin previliage!");
        return 1;
    }
    let pos = workDir.lastIndexOf("\\");
    let soui4js = workDir.substring(0,pos);

    if(soui4.OsType()==1){
        //windows
        let ret = -1;
        let regKey = new soui4.SRegKey();
        if(regKey.Open(soui4.SKEY_MACHINE,"System\\CurrentControlSet\\Control\\Session Manager\\Environment",soui4.REG_WRITE)){
            regKey.SetStringValue("SOUI4JS_PATH",soui4js);
            regKey.Close();
            soui4.NotifySettingChange("Environment",5000);
            console.log("set env succeed!");
            ret = 0;
        }else{
            console.log("open reg failed");
        }
    }else{
        //linux.
        soui4.SMessageBox(0, "set SOUI4JS_PATH env to "+ soui4js,"Alert",soui4.MB_OK);
    }

	return ret;
}

globalThis.main=main;
