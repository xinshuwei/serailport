// PasswordDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "focus_sound.h"
#include "PasswordDialog.h"
#include "afxmsg_.h"


// CPasswordDialog 对话框

IMPLEMENT_DYNAMIC(CPasswordDialog, CDialog)

CPasswordDialog::CPasswordDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDialog::IDD, pParent)
	, m_paasWord(_T(""))
{

}

CPasswordDialog::~CPasswordDialog()
{
}

void CPasswordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_paasWord);
}


BEGIN_MESSAGE_MAP(CPasswordDialog, CDialog)
ON_BN_CLICKED(IDCANCEL, &CPasswordDialog::OnBnClickedCancel)
ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CPasswordDialog::OnEnChangeEditPassword)
END_MESSAGE_MAP()


// CPasswordDialog 消息处理程序

//void CPasswordDialog::OnBnClickedOk()
//{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
//}

void CPasswordDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

void CPasswordDialog::OnEnChangeEditPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
