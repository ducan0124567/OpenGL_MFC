// RotateSettingDlg.cpp : implementation file
//

#include "pch.h"
#include "OpenGL_MFC.h"
#include "RotateSettingDlg.h"
#include "afxdialogex.h"


// RotateSettingDlg dialog

IMPLEMENT_DYNAMIC(RotateSettingDlg, CDialogEx)

RotateSettingDlg::RotateSettingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ROTATEF_SETTING, pParent)
{

}

RotateSettingDlg::~RotateSettingDlg()
{
}

BOOL RotateSettingDlg::OnInitDialog()
{
	BOOL ret = CDialogEx::OnInitDialog();

	edt_adjust_aro.SetWindowText(_T("0.0"));
	edt_adjust_xro.SetWindowText(_T("0.0"));
	edt_adjust_yro.SetWindowText(_T("0.0"));
	edt_adjust_zro.SetWindowText(_T("0.0"));

	UpdateData(FALSE);
	return ret;
}

void RotateSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_BUTTON_XRO_DEC, xro_btn_dec);
	DDX_Control(pDX, ID_BUTTON_YRO_DEC, yro_btn_dec);
	DDX_Control(pDX, ID_BUTTON_ZRO_DEC, zro_btn_dec);
	DDX_Control(pDX, ID_BUTTON_ARO_DEC, aro_btn_dec);
	DDX_Control(pDX, ID_BUTTON_ARO_INC, aro_btn_inc);
	DDX_Control(pDX, ID_BUTTON_XRO_INC, xro_btn_inc);
	DDX_Control(pDX, ID_BUTTON_YRO_INC, yro_btn_inc);
	DDX_Control(pDX, ID_BUTTON_ZRO_INC, zro_btn_inc);
	DDX_Control(pDX, IDC_EDIT1, edt_adjust_aro);
	DDX_Control(pDX, IDC_EDIT2, edt_adjust_xro);
	DDX_Control(pDX, IDC_EDIT3, edt_adjust_yro);
	DDX_Control(pDX, IDC_EDIT4, edt_adjust_zro);
}


BEGIN_MESSAGE_MAP(RotateSettingDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_ARO_DEC, &RotateSettingDlg::OnBnClickedButtonAroDec)
	ON_BN_CLICKED(ID_BUTTON_ARO_INC, &RotateSettingDlg::OnBnClickedButtonAroInc)
	ON_BN_CLICKED(ID_BUTTON_XRO_DEC, &RotateSettingDlg::OnBnClickedButtonXroDec)
	ON_BN_CLICKED(ID_BUTTON_XRO_INC, &RotateSettingDlg::OnBnClickedButtonXroInc)
	ON_BN_CLICKED(ID_BUTTON_YRO_DEC, &RotateSettingDlg::OnBnClickedButtonYroDec)
	ON_BN_CLICKED(ID_BUTTON_YRO_INC, &RotateSettingDlg::OnBnClickedButtonYroInc)
	ON_BN_CLICKED(ID_BUTTON_ZRO_DEC, &RotateSettingDlg::OnBnClickedButtonZroDec)
	ON_BN_CLICKED(ID_BUTTON_ZRO_INC, &RotateSettingDlg::OnBnClickedButtonZroInc)
	ON_BN_CLICKED(IDOK, &RotateSettingDlg::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// RotateSettingDlg message handlers


void RotateSettingDlg::OnBnClickedButtonAroDec()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_aro.GetWindowText(currentVal);
	aro_adjust = _tstof(currentVal);
	aro_adjust -= 10.0;

	CString strVal;
	strVal.Format(_T("%f"), aro_adjust);
	edt_adjust_aro.SetWindowText(strVal);

	UpdateData(FALSE);
}


void RotateSettingDlg::OnBnClickedButtonAroInc()
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_aro.GetWindowText(currentVal);
	aro_adjust = _tstof(currentVal);
	aro_adjust += 10.0;

	CString strVal;
	strVal.Format(_T("%f"), aro_adjust);
	edt_adjust_aro.SetWindowText(strVal);

	UpdateData(FALSE);
}


void RotateSettingDlg::OnBnClickedButtonXroDec()
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_xro.GetWindowText(currentVal);
	xro_adjust = _tstof(currentVal);
	xro_adjust -= 1.0;

	CString strVal;
	strVal.Format(_T("%f"), xro_adjust);
	edt_adjust_xro.SetWindowText(strVal);

	UpdateData(FALSE);
}


void RotateSettingDlg::OnBnClickedButtonXroInc()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_xro.GetWindowText(currentVal);
	xro_adjust = _tstof(currentVal);
	xro_adjust += 1.0;

	CString strVal;
	strVal.Format(_T("%f"), xro_adjust);
	edt_adjust_xro.SetWindowText(strVal);

	UpdateData(FALSE);
}


void RotateSettingDlg::OnBnClickedButtonYroDec()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_yro.GetWindowText(currentVal);
	yro_adjust = _tstof(currentVal);
	yro_adjust -= 1.0;

	CString strVal;
	strVal.Format(_T("%f"), yro_adjust);
	edt_adjust_yro.SetWindowText(strVal);

	UpdateData(FALSE);
}


void RotateSettingDlg::OnBnClickedButtonYroInc()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_yro.GetWindowText(currentVal);
	yro_adjust = _tstof(currentVal);
	yro_adjust += 1.0;

	CString strVal;
	strVal.Format(_T("%f"), yro_adjust);
	edt_adjust_yro.SetWindowText(strVal);

	UpdateData(FALSE);

}


void RotateSettingDlg::OnBnClickedButtonZroDec()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_zro.GetWindowText(currentVal);
	zro_adjust = _tstof(currentVal);
	zro_adjust -= 1.0;

	CString strVal;
	strVal.Format(_T("%f"), zro_adjust);
	edt_adjust_zro.SetWindowText(strVal);

	UpdateData(FALSE);
}


void RotateSettingDlg::OnBnClickedButtonZroInc()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_zro.GetWindowText(currentVal);
	zro_adjust = _tstof(currentVal);
	zro_adjust += 1.0;

	CString strVal;
	strVal.Format(_T("%f"), zro_adjust);
	edt_adjust_zro.SetWindowText(strVal);

	UpdateData(FALSE);
}

float RotateSettingDlg::GetAdjustAro()
{
	return aro_adjust;
}

float RotateSettingDlg::GetAdjustXro()
{
	return xro_adjust;
}

float RotateSettingDlg::GetAdjustYro()
{
	return yro_adjust;
}

float RotateSettingDlg::GetAdjustZro()
{
	return zro_adjust;
}


void RotateSettingDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString currentVal;

	edt_adjust_aro.GetWindowText(currentVal);
	aro_adjust = _tstof(currentVal);

	edt_adjust_xro.GetWindowText(currentVal);
	xro_adjust = _tstof(currentVal);

	edt_adjust_yro.GetWindowText(currentVal);
	yro_adjust = _tstof(currentVal);

	edt_adjust_zro.GetWindowText(currentVal);
	zro_adjust = _tstof(currentVal);

	CDialogEx::OnOK();
}


void RotateSettingDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	aro_adjust = 0;
	xro_adjust = 0;
	yro_adjust = 0;
	zro_adjust = 0;
	CDialogEx::OnClose();
}
