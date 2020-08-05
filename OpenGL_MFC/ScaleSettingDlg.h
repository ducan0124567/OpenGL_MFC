#pragma once


// ScaleSettingDlg dialog

class ScaleSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ScaleSettingDlg)

public:
	ScaleSettingDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ScaleSettingDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCALEF_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
