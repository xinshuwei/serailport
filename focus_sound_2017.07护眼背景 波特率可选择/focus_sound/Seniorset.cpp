// Seniorset.cpp : 实现文件
//

#include "stdafx.h"
#include "focus_sound.h"
#include "Seniorset.h"


// CSeniorset 对话框

IMPLEMENT_DYNAMIC(CSeniorset, CDialog)

CSeniorset::CSeniorset(CWnd* pParent /*=NULL*/)
	: CDialog(CSeniorset::IDD, pParent)
	, m_senior_password(_T(""))
{

}

CSeniorset::~CSeniorset()
{
}

void CSeniorset::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_senior_password);
	DDV_MaxChars(pDX, m_senior_password, 50);
}


BEGIN_MESSAGE_MAP(CSeniorset, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CSeniorset::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CSeniorset 消息处理程序

void CSeniorset::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
}
