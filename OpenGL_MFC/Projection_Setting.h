#pragma once


// Projection_Setting dialog

class Projection_Setting : public CDialogEx
{
	DECLARE_DYNAMIC(Projection_Setting)

public:
	Projection_Setting(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Projection_Setting();

	BOOL OnInitDialog();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTION_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


	float fovy;
	float aspect;
	float znear;
	float zfar;
	float ratio;

public:

	float get_fovy();
	float get_aspect();
	float get_znear();
	float get_zfar();

	
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CEdit edt_FOVY;
	CEdit edt_ASPECT;
	CEdit edt_zNear;
	CEdit edt_zFAR;
};
