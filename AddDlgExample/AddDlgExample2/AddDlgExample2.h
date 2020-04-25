
// AddDlgExample2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAddDlgExample2App:
// See AddDlgExample2.cpp for the implementation of this class
//

class CAddDlgExample2App : public CWinApp
{
public:
	CAddDlgExample2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAddDlgExample2App theApp;
