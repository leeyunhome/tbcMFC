
// AddDlgExample2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "AddDlgExample2.h"
#include "AddDlgExample2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddDlgExample2Dlg dialog



CAddDlgExample2Dlg::CAddDlgExample2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDDLGEXAMPLE2_DIALOG, pParent)
	, m_editStr1(_T("7"))
	, m_editStr2(_T("1024"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddDlgExample2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editStr1);
	DDX_Text(pDX, IDC_EDIT2, m_editStr2);
}

BEGIN_MESSAGE_MAP(CAddDlgExample2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CAddDlgExample2Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CAddDlgExample2Dlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CAddDlgExample2Dlg message handlers

BOOL CAddDlgExample2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	updateResultStaticTest();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAddDlgExample2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAddDlgExample2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAddDlgExample2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Event notification En
void CAddDlgExample2Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	UpdateData(TRUE);	// Control to Variable

	updateResultStaticTest();

}


void CAddDlgExample2Dlg::OnEnChangeEdit2()
{
	UpdateData(TRUE);
	// ...
	//m_editStr2 = 
	/*GetDlgItemText(IDC_RESULT_STATIC, m_editStr2);
	AfxMessageBox(m_editStr2);*/
	//SetDlgItemText(IDC_RESULT_STATIC, m_editStr2);
	updateResultStaticTest();
}

void CAddDlgExample2Dlg::updateResultStaticTest()
{
	long long num1 = _ttoll(m_editStr1);
	long long num2 = _ttoll(m_editStr2);
	CString sum;
	sum.Format(TEXT("Sum of Two Numbers = %lld"), num1 + num2);
	SetDlgItemText(IDC_RESULT_STATIC, sum);
}

