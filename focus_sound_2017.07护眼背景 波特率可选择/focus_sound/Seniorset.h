#pragma once


// CSeniorset �Ի���

class CSeniorset : public CDialog
{
	DECLARE_DYNAMIC(CSeniorset)

public:
	CSeniorset(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSeniorset();

// �Ի�������
	enum { IDD = IDD_DIALOG_Advanced };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_senior_password;
	afx_msg void OnEnChangeEdit1();
};
