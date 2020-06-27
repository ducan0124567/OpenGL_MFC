#pragma once


// RotateSettingDlg dialog

class RotateSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RotateSettingDlg)

public:
	RotateSettingDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~RotateSettingDlg();

	BOOL OnInitDialog();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROTATEF_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CButton xro_btn_dec;
	CButton yro_btn_dec;
	CButton zro_btn_dec;
	CButton aro_btn_dec;
	CButton aro_btn_inc;
	CButton xro_btn_inc;
	CButton yro_btn_inc;
	CButton zro_btn_inc;
	CEdit edt_adjust_aro;
	CEdit edt_adjust_xro;
	CEdit edt_adjust_yro;
	CEdit edt_adjust_zro;

	float aro_adjust;
	float xro_adjust;
	float yro_adjust;
	float zro_adjust;
public:
	afx_msg void OnBnClickedButtonAroDec();
	afx_msg void OnBnClickedButtonAroInc();
	afx_msg void OnBnClickedButtonXroDec();
	afx_msg void OnBnClickedButtonXroInc();
	afx_msg void OnBnClickedButtonYroDec();
	afx_msg void OnBnClickedButtonYroInc();
	afx_msg void OnBnClickedButtonZroDec();
	afx_msg void OnBnClickedButtonZroInc();
	float GetAdjustAro();
	float GetAdjustXro();
	float GetAdjustYro();
	float GetAdjustZro();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
};
