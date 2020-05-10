#include "pch.h"
#include "framework.h"
#include "MyClass.h"
#include "math.h"


CMyClass::CMyClass()
{
}
CMyClass::~CMyClass()
{
}
void CMyClass::ReadWorkpiece() 
{
	X[1] = -20;  Y[1] = 20;   C[1] = 1;
	X[2] = -20;  Y[2] = 80;   C[2] = 1;
	X[3] = -40;  Y[3] = 60;   C[3] = 1;
	X[4] = -60;  Y[4] = 80;   C[4] = 1;
	X[5] = -60;  Y[5] = 20;   C[5] = 1;
	X[6] = -25;  Y[6] = 20;   C[6] = 1;
	X[7] = -25;  Y[7] = 70;   C[7] = 1;
	X[8] = -40;  Y[8] = 50;   C[8] = 1;
	X[9] = -55;  Y[9] = 70;   C[9] = 1;
	X[10] = -55; Y[10] = 20;  C[10] = 1;
}
void CMyClass::Calculate(array2d B)
{
	ReadWorkpiece();
	for (int i = 1; i <= 10; ++i)
	{
		XT[i] = X[i] * B[1][1] + Y[i] * B[2][1] + C[i] * B[3][1];
		YT[i] = X[i] * B[1][2] + Y[i] * B[2][2] + C[i] * B[3][2];
	}
}

void CMyClass::Display()
{
	CFrameWnd* pWnd = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
	CDC* pdc = pWnd->GetActiveView()->GetDC();
	CRect rr;
	::GetClientRect(pWnd->GetActiveView()->m_hWnd, rr); 
	DrawView(pdc, rr);
	pWnd->GetActiveView()->ReleaseDC(pdc);
}

void CMyClass::DrawView(CDC* pdc, CRect rr)
{
	int color = RGB(0, 0, 255);
	CPen pen1(PS_SOLID, 1, color);
	pdc->SelectObject(&pen1);
	xx = rr.right / 2;
	yy = rr.bottom / 2;
	Calculate(A1); 
	moveto(xx - XT[1], yy - YT[1], pdc);
	lineto(xx - XT[2], yy - YT[2], pdc);
	lineto(xx - XT[3], yy - YT[3], pdc);
	lineto(xx - XT[4], yy - YT[4], pdc);
	lineto(xx - XT[5], yy - YT[5], pdc);
	lineto(xx - XT[10], yy - YT[10], pdc);
	lineto(xx - XT[9], yy - YT[9], pdc);
	lineto(xx - XT[8], yy - YT[8], pdc);
	lineto(xx - XT[7], yy - YT[7], pdc);
	lineto(xx - XT[6], yy - YT[6], pdc);
	lineto(xx - XT[1], yy - YT[1], pdc);

	color = RGB(0, 255, 0);
	CPen pen2(PS_SOLID, 1, color);
	pdc->SelectObject(&pen2);


	
	moveto(xx - 200, yy, pdc);
	lineto(xx + 200, yy, pdc);
	moveto(xx, yy - 200, pdc);
	lineto(xx, yy + 200, pdc);

	color = RGB(255, 0, 0);
	CPen pen3(PS_SOLID, 1, color);
	pdc->SelectObject(&pen3);

	Calculate(A); 
	moveto(xx - XT[1], yy - YT[1], pdc);
	lineto(xx - XT[2], yy - YT[2], pdc);
	lineto(xx - XT[3], yy - YT[3], pdc);
	lineto(xx - XT[4], yy - YT[4], pdc);
	lineto(xx - XT[5], yy - YT[5], pdc);
	lineto(xx - XT[10], yy - YT[10], pdc);
	lineto(xx - XT[9], yy - YT[9], pdc);
	lineto(xx - XT[8], yy - YT[8], pdc);
	lineto(xx - XT[7], yy - YT[7], pdc);
	lineto(xx - XT[6], yy - YT[6], pdc);
	lineto(xx - XT[1], yy - YT[1], pdc);
}


void CMyClass::moveto(double x, double y, CDC* pdc)
{
	pdc->MoveTo((int)x, (int)y);
}

void CMyClass::lineto(double x, double y, CDC* pdc)
{
	pdc->LineTo((int)x, (int)y);
}
