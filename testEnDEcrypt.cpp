#include "StdAfx.h"
#include "testEnDEcrypt.h"
#include "AGuiAI/EnDeCrypt/IEnDecrypt.h"
#include "AGuiLOG/IAGuiLOG.h"

testEnDEcrypt* testEnDEcrypt::instance=NULL;

testEnDEcrypt* testEnDEcrypt::GetInstance()
{
	if(instance==NULL)
	{
		instance = new testEnDEcrypt;
	}
	return instance;
}

testEnDEcrypt::testEnDEcrypt(void)
{
}


testEnDEcrypt::~testEnDEcrypt(void)
{
	if(instance!=NULL)
	{
		delete instance;
		instance = NULL;
	}
}

void testEnDEcrypt::TestMain()
{
	GetInstance()->TestDES();
	GetInstance()->TestMD5();
}

void testEnDEcrypt::TestDES()
{
	CString strDebug="";
	const int nLen = 256;
	char key[nLen] = "adf12345"; //密钥
	char buf[nLen]; //缓冲数组
	char str[nLen] ="whg12你好，hello world 3456"; //要加密的字符串

	memset(buf, 0, sizeof(buf)); //设置缓冲区为一个指定的字符
	strcpy(buf, str); 
	strDebug.Format("加密前的字符串: %s",buf);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);
	

	AGuiAI::DoDES(buf, buf, sizeof(buf), key, sizeof(key), ENCRYPT); 
	strDebug.Format("加密后的字符串: %s",buf);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);
	
	AGuiAI::DoDES(buf, buf, sizeof(buf), key, sizeof(key), DECRYPT); 
	strDebug.Format("解密后的字符串: %s",buf);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);

	CString strText,strKey,strRes="";
	strText="你好are you";
	strKey="12345678";
	for(int i=1;i<MAX_DATA_LENGTH-11;i++)
	{
		CString strTemmm="";
		strTemmm.Format("%d",i%2);
		strText+=strTemmm;
	}

	strRes=AGuiAI::EncryptByDES(strText,strKey);
	AGuiObj::AGuiLog()->AppendMsg(strRes);

	strRes=AGuiAI::DecryptByDES(strRes,strKey);
	AGuiObj::AGuiLog()->AppendMsg(strRes);
}

void testEnDEcrypt::TestMD5()
{
	CString strPass=_T("azSXd中国cfv");
	AGuiObj::AGuiLog()->AppendMsg("原字符串："+strPass);
	CString strPassMD5 = AGuiAI::EncryptByMD5(strPass);
	AGuiObj::AGuiLog()->AppendMsg("MD5加密为："+strPassMD5);

	CString strMD5Base64 = AGuiAI::EncryptByMD5Base64(strPass);
	AGuiObj::AGuiLog()->AppendMsg("MD5Base64加密为："+strMD5Base64);

	CString strMD5Base64De = AGuiAI::DecryptByMD5Base64(strMD5Base64);
	AGuiObj::AGuiLog()->AppendMsg("MD5Base64解密为："+strMD5Base64De);
		
}

