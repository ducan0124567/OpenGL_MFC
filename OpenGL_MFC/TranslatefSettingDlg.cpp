// TranslatefSettingDlg.cpp : implementation file
//

#include "pch.h"
#include "OpenGL_MFC.h"
#include "TranslatefSettingDlg.h"
#include "afxdialogex.h"


// TranslatefSettingDlg dialog

IMPLEMENT_DYNAMIC(TranslatefSettingDlg, CDialogEx)

TranslatefSettingDlg::TranslatefSettingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRANSLATEF_SETTING, pParent)
{

	xtr_adjust = 0.0;
}

TranslatefSettingDlg::~TranslatefSettingDlg()
{
}

BOOL TranslatefSettingDlg::OnInitDialog()
{
	BOOL ret = CDialogEx::OnInitDialog();

	edt_adjust_xtr.SetWindowText(_T("0.0"));
	edt_adjust_ytr.SetWindowText(_T("0.0"));
	edt_adjust_ztr.SetWindowText(_T("0.0"));

	UpdateData(FALSE);
	return ret;
}

void TranslatefSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_BUTTON_XTR_DEC, xtr_btn_dec);
	DDX_Control(pDX, IDC_EDIT1, edt_adjust_xtr);
	DDX_Control(pDX, ID_BUTTON_XTR_INC, xtr_btn_inc);
	DDX_Control(pDX, ID_BUTTON_YTR_DEC, ytr_btn_dec);
	DDX_Control(pDX, ID_BUTTON_ZTR_DEC, ztr_btn_dec);
	DDX_Control(pDX, ID_BUTTON_YTR_INC, ytr_btn_inc);
	DDX_Control(pDX, ID_BUTTON_ZTR_INC, ztr_btn_inc);
	DDX_Control(pDX, IDC_EDIT2, edt_adjust_ytr);
	DDX_Control(pDX, IDC_EDIT3, edt_adjust_ztr);
}


BEGIN_MESSAGE_MAP(TranslatefSettingDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_XTR_DEC, &TranslatefSettingDlg::OnBnClickedButtonXtrDec)
	ON_BN_CLICKED(ID_BUTTON_XTR_INC, &TranslatefSettingDlg::OnBnClickedButtonXtrInc)
	ON_BN_CLICKED(IDOK, &TranslatefSettingDlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_BUTTON_YTR_DEC, &TranslatefSettingDlg::OnBnClickedButtonYtrDec)
	ON_BN_CLICKED(ID_BUTTON_YTR_INC, &TranslatefSettingDlg::OnBnClickedButtonYtrInc)
	ON_BN_CLICKED(ID_BUTTON_ZTR_DEC, &TranslatefSettingDlg::OnBnClickedButtonZtrDec)
	ON_BN_CLICKED(ID_BUTTON_ZTR_INC, &TranslatefSettingDlg::OnBnClickedButtonZtrInc)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// TranslatefSettingDlg message handlers


void TranslatefSettingDlg::OnBnClickedButtonXtrDec()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_xtr.GetWindowText(currentVal);
	xtr_adjust = _tstof(currentVal);
	xtr_adjust -= 1.0;

	CString strVal;
	strVal.Format(_T("%f"), xtr_adjust);
	edt_adjust_xtr.SetWindowText(strVal);

	UpdateData(FALSE);
}


void TranslatefSettingDlg::OnBnClickedButtonXtrInc()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_xtr.GetWindowText(currentVal);
	xtr_adjust = _tstof(currentVal);
	xtr_adjust += 1.0;

	CString strVal;
	strVal.Format(_T("%f"), xtr_adjust);
	edt_adjust_xtr.SetWindowText(strVal);

	UpdateData(FALSE);
}

void TranslatefSettingDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_xtr.GetWindowText(currentVal);
	xtr_adjust = _tstof(currentVal);

	edt_adjust_ytr.GetWindowText(currentVal);
	ytr_adjust = _tstof(currentVal);

	edt_adjust_ztr.GetWindowText(currentVal);
	ztr_adjust = _tstof(currentVal);

	CDialogEx::OnOK();
}


void TranslatefSettingDlg::OnBnClickedButtonYtrDec()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_ytr.GetWindowText(currentVal);
	ytr_adjust = _tstof(currentVal);
	ytr_adjust -= 1.0;

	CString strVal;
	strVal.Format(_T("%f"), ytr_adjust);
	edt_adjust_ytr.SetWindowText(strVal);

	UpdateData(FALSE);
}


void TranslatefSettingDlg::OnBnClickedButtonYtrInc()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_ytr.GetWindowText(currentVal);
	ytr_adjust = _tstof(currentVal);
	ytr_adjust += 1.0;

	CString strVal;
	strVal.Format(_T("%f"), ytr_adjust);
	edt_adjust_ytr.SetWindowText(strVal);

	UpdateData(FALSE);
}


void TranslatefSettingDlg::OnBnClickedButtonZtrDec()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_ztr.GetWindowText(currentVal);
	ztr_adjust = _tstof(currentVal);
	ztr_adjust -= 1.0;

	CString strVal;
	strVal.Format(_T("%f"), ztr_adjust);
	edt_adjust_ztr.SetWindowText(strVal);

	UpdateData(FALSE);
}


void TranslatefSettingDlg::OnBnClickedButtonZtrInc()
{
	// TODO: Add your control notification handler code here
	CString currentVal;
	edt_adjust_ztr.GetWindowText(currentVal);
	ztr_adjust = _tstof(currentVal);
	ztr_adjust += 1.0;

	CString strVal;
	strVal.Format(_T("%f"), ztr_adjust);
	edt_adjust_ztr.SetWindowText(strVal);

	UpdateData(FALSE);
}

float TranslatefSettingDlg::GetAdjustXtr()
{
	return xtr_adjust;
}

float TranslatefSettingDlg::GetAdjustYtr()
{
	return ytr_adjust;
}

float TranslatefSettingDlg::GetAdjustZtr()
{
	return ztr_adjust;
}

void TranslatefSettingDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	xtr_adjust = 0;
	ytr_adjust = 0;
	ztr_adjust = 0;
	CDialogEx::OnClose();
}
