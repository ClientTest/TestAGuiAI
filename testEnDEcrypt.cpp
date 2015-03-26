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
	char key[nLen] = "adf12345"; //��Կ
	char buf[nLen]; //��������
	char str[nLen] ="whg12��ã�hello world 3456"; //Ҫ���ܵ��ַ���

	memset(buf, 0, sizeof(buf)); //���û�����Ϊһ��ָ�����ַ�
	strcpy(buf, str); 
	strDebug.Format("����ǰ���ַ���: %s",buf);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);
	

	AGuiAI::DoDES(buf, buf, sizeof(buf), key, sizeof(key), ENCRYPT); 
	strDebug.Format("���ܺ���ַ���: %s",buf);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);
	
	AGuiAI::DoDES(buf, buf, sizeof(buf), key, sizeof(key), DECRYPT); 
	strDebug.Format("���ܺ���ַ���: %s",buf);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);

	CString strText,strKey,strRes="";
	strText="���are you";
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
	CString strPass=_T("azSXd�й�cfv");
	AGuiObj::AGuiLog()->AppendMsg("ԭ�ַ�����"+strPass);
	CString strPassMD5 = AGuiAI::EncryptByMD5(strPass);
	AGuiObj::AGuiLog()->AppendMsg("MD5����Ϊ��"+strPassMD5);

	CString strMD5Base64 = AGuiAI::EncryptByMD5Base64(strPass);
	AGuiObj::AGuiLog()->AppendMsg("MD5Base64����Ϊ��"+strMD5Base64);

	CString strMD5Base64De = AGuiAI::DecryptByMD5Base64(strMD5Base64);
	AGuiObj::AGuiLog()->AppendMsg("MD5Base64����Ϊ��"+strMD5Base64De);
		
}

