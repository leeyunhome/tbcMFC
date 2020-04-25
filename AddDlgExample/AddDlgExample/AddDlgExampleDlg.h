
// AddDlgExampleDlg.h : header file
//

#pragma once


// CAddDlgExampleDlg dialog
class CAddDlgExampleDlg : public CDialogEx
{
// Construction
public:
	CAddDlgExampleDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDDLGEXAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_editStr1;
	afx_msg void OnEnChangeEdit1();
	CString m_editStr2;
	afx_msg void OnEnChangeEdit2();
	
	void updateResultStaticText();
};
