
// IB3Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "IB3.h"
#include "IB3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CIB3Dlg



CIB3Dlg::CIB3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IB3_DIALOG, pParent)
	, number(_T(""))
	, cd(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIB3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, number);
	DDX_Text(pDX, IDC_EDIT2, cd);
}

BEGIN_MESSAGE_MAP(CIB3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CIB3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CIB3Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений CIB3Dlg

BOOL CIB3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CIB3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CIB3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIB3Dlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	int N;
	Sn = 0;
	Sch = 0;
	N = number.GetLength();
	for (int i = 1; i < N+1 ; i++) {// N если номер с контрольной цифрой,а N+1 если надо найти контрльную цифру
		num1[i] = (unsigned int)(number[i - 1]) - '0';
		if ((N+1) % 2== 0) {// N если номер с контрольной цифрой,а N+1 если надо найти контрльную цифру

			if (i % 2 != 0) {
				num1[i] = (num1[i] * 2) % 9;
				Sn += num1[i];
			}
			else {
				Sch += num1[i];
			}

		}
		else {
			if (i % 2 == 0) {
				num1[i] = (num1[i] * 2) % 9;
				Sn += num1[i];
			}
			else {
				Sch += num1[i];
			}
		}
	}
	cd = (10 - ((Sn + Sch) % 10)) % 10;
	UpdateData(FALSE);
	
}


void CIB3Dlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	int N;
	Sn = 0;
	Sch = 0;
	N = number.GetLength();
	for (int i = 1; i < N + 1; i++) {// N если номер с контрольной цифрой,а N+1 если надо найти контрльную цифру
		num1[i] = (unsigned int)(number[i - 1]) - '0';
		if (N % 2 == 0) {// N если номер с контрольной цифрой,а N+1 если надо найти контрльную цифру

			if (i % 2 == 0) {
				num1[i] = num1[i] * 3;
				Sch += num1[i];
			}
			else {
				Sn += num1[i];
			}

		}
		else {
			if (i % 2 != 0) {
				num1[i] = num1[i] * 3;
				Sn += num1[i];
			}
			else {
				Sch += num1[i];
			}
		}
	}
	cd = (10 - ((Sn + Sch) % 10)) % 10;
	UpdateData(FALSE);
}
