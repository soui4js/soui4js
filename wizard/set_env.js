import * as soui4 from "soui4";

function main(inst,workDir,args)
{
	soui4.log(workDir);
    if(!soui4.IsRunAsAdmin())
    {
        console.log("request admin previliage!");
        return 1;
    }
    let ret = -1;
    let regKey = new soui4.SRegKey();
    if(regKey.Open(soui4.SKEY_MACHINE,"System\\CurrentControlSet\\Control\\Session Manager\\Environment",soui4.REG_WRITE)){
        let pos = workDir.lastIndexOf("\\");
        let soui4js = workDir.substring(0,pos);
        regKey.SetStringValue("SOUI4JS_PATH",soui4js);
        regKey.Close();
        console.log("set env succeed!");
        ret = 0;
    }else{
        console.log("open reg failed");
    }
	return ret;
}

globalThis.main=main;
