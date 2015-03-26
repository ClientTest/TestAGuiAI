
// TestAGuiAI.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "TestAGuiAI.h"
#include "TestAGuiAIDlg.h"
//#include "CrashCatch/CrashCatch.h"
#include "MfcLib/AGuiFun/AGuiPath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestAGuiAIApp

BEGIN_MESSAGE_MAP(CTestAGuiAIApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestAGuiAIApp ����

CTestAGuiAIApp::CTestAGuiAIApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTestAGuiAIApp ����

CTestAGuiAIApp theApp;

bool format_cmdline(char* pBuf,int len,const char* szModule,unsigned int uin,const char* szModuleExe,const char* szCmd)
{
	if(pBuf && szModule && szModuleExe && szCmd)
	{
		_snprintf(pBuf,len,"exception_cmd:module=%s&&uin=%u&&module_exe=%s&&cmd=%s",szModule,uin,szModuleExe,szCmd);
		return true;
	}
	return false;
}
// CTestAGuiAIApp ��ʼ��

BOOL CTestAGuiAIApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CString strPath = AGuiFun::GetModuleDir();

	//��������
//	LPSTR lpCMD="";
//	UINT  nUin = 10000;
//	LPSTR lpModule = "AGUI_AI_TEST";
//	char szParam[1024];
//	memset(szParam,0,1024);
//	CString	strExeName = AfxGetApp()->m_pszExeName;
//	strExeName += ".exe";
//	format_cmdline(szParam,1023,lpModule,nUin,strExeName,lpCMD);
////#ifndef _DEBUG
//	Init_CrashCatch(strPath+"ExceptionReporting.exe",szParam);
////#endif

	CTestAGuiAIDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

