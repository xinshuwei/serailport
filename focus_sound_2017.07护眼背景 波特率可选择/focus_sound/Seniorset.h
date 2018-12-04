#pragma once


// CSeniorset 对话框

class CSeniorset : public CDialog
{
	DECLARE_DYNAMIC(CSeniorset)

public:
	CSeniorset(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSeniorset();

// 对话框数据
	enum { IDD = IDD_DIALOG_Advanced };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_senior_password;
	afx_msg void OnEnChangeEdit1();
};
