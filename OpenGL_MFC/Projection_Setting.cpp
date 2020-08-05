// Projection_Setting.cpp : implementation file
//

#include "pch.h"
#include "OpenGL_MFC.h"
#include "Projection_Setting.h"
#include "afxdialogex.h"


// Projection_Setting dialog

IMPLEMENT_DYNAMIC(Projection_Setting, CDialogEx)

Projection_Setting::Projection_Setting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECTION_SETTING, pParent)
{

}

Projection_Setting::~Projection_Setting()
{
}



void Projection_Setting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, edt_FOVY);
	DDX_Control(pDX, IDC_EDIT1, edt_ASPECT);
	DDX_Control(pDX, IDC_EDIT3, edt_zNear);
	DDX_Control(pDX, IDC_EDIT5, edt_zFAR);
}


BEGIN_MESSAGE_MAP(Projection_Setting, CDialogEx)
	ON_BN_CLICKED(IDOK, &Projection_Setting::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Projection_Setting::OnBnClickedCancel)
END_MESSAGE_MAP()


// Projection_Setting message handlers

BOOL Projection_Setting::OnInitDialog()
{
	BOOL ret = CDialogEx::OnInitDialog();
	CRect rect;
	GetClientRect(rect);
	float w = (float)rect.Width();
	float h = (float)rect.Height();
	ratio = w / h;
	CString strVal;
	strVal.Format(_T("%f"), ratio);

	edt_FOVY.SetWindowText(_T("45.0"));
	edt_ASPECT.SetWindowText(strVal);
	edt_zNear.SetWindowText(_T("1.0"));
	edt_zFAR.SetWindowText(_T("100.0"));

	return ret;
}

void Projection_Setting::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString currentVal;

	edt_FOVY.GetWindowText(currentVal);
	fovy = _tstof(currentVal);

	edt_ASPECT.GetWindowText(currentVal);
	aspect = _tstof(currentVal);

	edt_zNear.GetWindowText(currentVal);
	znear = _tstof(currentVal);

	edt_zFAR.GetWindowText(currentVal);
	zfar = _tstof(currentVal);


	CDialogEx::OnOK();
}


void Projection_Setting::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here

	fovy = 45;
	aspect = ratio;
	znear = 1;
	zfar = 100;

	CDialogEx::OnCancel();
}



float Projection_Setting::get_fovy()
{
	return fovy;
}

float Projection_Setting::get_aspect()
{
	return aspect;
}

float Projection_Setting::get_znear()
{
	return znear;
}

float Projection_Setting::get_zfar()
{
	return zfar;
}