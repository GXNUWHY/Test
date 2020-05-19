#pragma once


typedef  double   array2d[5][5];
typedef  double   array[24];

class CMyClass 
{
public:
	int       xx, yy;
	array     X, Y, Z, C, XT, YT;
	array2d   A1, A;
public:
	CMyClass();
	virtual ~CMyClass();
	void ReadWorkpiece();
	void Calculate(array2d B);
	void Display();
	void DrawView(CDC* pdc, CRect rr);
	void moveto(double x, double y, CDC* pdc);
	void lineto(double x, double y, CDC* pdc);
};


