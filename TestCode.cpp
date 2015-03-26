#include "StdAfx.h"
#include "TestCode.h"
#include "AGuiAI/Code/ICode.h"
#include "AGuiLOG/IAGuiLOG.h"

TestCode* TestCode::instance=NULL;

TestCode* TestCode::GetInstance()
{
	if(instance==NULL)
	{
		instance = new TestCode;
	}
	return instance;
}

TestCode::TestCode(void)
{
}


TestCode::~TestCode(void)
{
	if(instance!=NULL)
	{
		delete instance;
		instance = NULL;
	}
}

void TestCode::TestMain()
{
	GetInstance()->TestCodeConv();
}

void TestCode::TestCodeConv()
{
	CString strFilePath = "F:\\Stdcode\\VS2010\\MFC\\bin\\debug\\";
	AGuiObj::AGuiLog()->AppendMsg(strFilePath);
	char dbpathUTF8[256];
	AGuiAI::ConvGB2312ToUTF8(dbpathUTF8,256,strFilePath,0);

	CString strDebug="";
	strDebug.Format("UTF8±àÂë: %s",dbpathUTF8);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);

	char dbpathGB2312[256];
	AGuiAI::ConvGB2312ToUTF8(dbpathGB2312,256,dbpathUTF8,0);
	strDebug.Format("GB2312±àÂë: %s",dbpathGB2312);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);

	strFilePath = "F:\\Stdcode\\VS2010\\MFC\\bin\\debug\\helloÎÒ";
	strDebug = AGuiAI::ConvGB2312ToUTF8(strFilePath);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);

	strDebug = AGuiAI::ConvUTF8ToGB2312(strDebug);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);
}
