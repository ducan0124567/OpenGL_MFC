#pragma once


// TranslatefSettingDlg dialog

class TranslatefSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TranslatefSettingDlg)

public:
	TranslatefSettingDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TranslatefSettingDlg();

	BOOL OnInitDialog();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANSLATEF_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CButton xtr_btn_dec;
	CEdit edt_adjust_xtr;
	CButton xtr_btn_inc;

	float xtr_adjust;
	float ytr_adjust;
	float ztr_adjust;
public:
	afx_msg void OnBnClickedButtonXtrDec();
	afx_msg void OnBnClickedButtonXtrInc();
	afx_msg void OnBnClickedOk();
	float GetAdjustXtr();
	float GetAdjustYtr();
	float GetAdjustZtr();
protected:
	CButton ytr_btn_dec;
	CButton ztr_btn_dec;
	CButton ytr_btn_inc;
	CButton ztr_btn_inc;
	CEdit edt_adjust_ytr;
public:
	CEdit edt_adjust_ztr;
	afx_msg void OnBnClickedButtonYtrDec();
	afx_msg void OnBnClickedButtonYtrInc();
	afx_msg void OnBnClickedButtonZtrDec();
	afx_msg void OnBnClickedButtonZtrInc();
	afx_msg void OnClose();
};
