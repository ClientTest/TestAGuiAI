
// TestAGuiAI.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestAGuiAIApp:
// �йش����ʵ�֣������ TestAGuiAI.cpp
//

class CTestAGuiAIApp : public CWinApp
{
public:
	CTestAGuiAIApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestAGuiAIApp theApp;