// ScaleSettingDlg.cpp : implementation file
//

#include "pch.h"
#include "OpenGL_MFC.h"
#include "ScaleSettingDlg.h"
#include "afxdialogex.h"


// ScaleSettingDlg dialog

IMPLEMENT_DYNAMIC(ScaleSettingDlg, CDialogEx)

ScaleSettingDlg::ScaleSettingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCALEF_SETTING, pParent)
{

}

ScaleSettingDlg::~ScaleSettingDlg()
{
}

void ScaleSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ScaleSettingDlg, CDialogEx)
END_MESSAGE_MAP()


// ScaleSettingDlg message handlers
