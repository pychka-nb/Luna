
// IB3Dlg.h: файл заголовка
//

#pragma once
#include <vector>
using namespace std;
// Диалоговое окно CIB3Dlg
class CIB3Dlg : public CDialogEx
{
// Создание
public:
	CIB3Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IB3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int Sn, Sch;
	afx_msg void OnBnClickedButton1();
	CString number;
	int num;
	int num1[50];
	int cd;
	afx_msg void OnBnClickedButton2();
};
