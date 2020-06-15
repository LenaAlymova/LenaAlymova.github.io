// ����� ������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "math.h"
using namespace std;

double func(double x, double y)
{	return -2*x*y;}

double fi(double x, double y)
{	return func(x,y);}

double funcExter(double x, double *y,int l,double h)
{	return h/24*(55*fi(x+3*h,y[l])-59*fi(x+2*h,y[l-1])+37*fi(x+h,y[l-2])-9*fi(x,y[l-3]));}

double funcInter(double x, double *y, double yi,int l, double h)
{	return h/24*(9*fi(x+4*h,yi)+19*fi(x+3*h,y[l])-5*fi(x+2*h,y[l-1])+fi(x+h,y[l-2]));}

double runngeKut(double h,double x, double y)
{	return func(x+h/2,y+h/2*func(x,y));}

// �����-���� ��� ���������� 4� ���������� ��������
void runngeKut2 (double a, double b,int d, int n, double *y)// ������� ��������
{
	double h = (b-a)/n / d;//d=���������� n � � ����
	double yy=y[0], x=a;
	int l = 1;
	for (int i = 1; x <= b ;++i)
	{
		yy = yy + h*runngeKut(h,x, yy);
		x = x + h;
		if (i%d == 0)
			y[l] = yy,++l;
	}

}

void Adams (double a, double b, int d, int l, double *y, int n, double eps)				
{


	double h = (b-a)/n ,
		x=a;
	int m=4;
	double y_e, //��� 2 ��� ����������� �-��
		y_i,//��� 3 ��� ���������� �_i+1_1=yi+delta_yi_e
		y_i1;// ��� 4
	
	for(int i=4; i<=n;i++)
	{
		l=i;
		do
		{
			h=h/d; // ���������� ��
			d=d*2;
			x=a+i*h;

			y_e = funcExter(x,y,l,h);
			y_i= y[i]+y_e;
			y_i1= funcInter(x,y,y_i,l,h);	
		} while(fabs(y_i1-y_e)>eps);//��������

		y_i=y[i]+y_i1;
		y_i1=funcInter(x,y,y_i,l,h);
		y_i=y[i]+y_i1;
		
		if (i%d==0)
		{
			y[m]=y_i;
			++m;
		}
	} 
}

void main()
{

	setlocale(LC_ALL, "Russian");
	int  n;
	double a,b;
	double y0 = 1;


	double eps;
	
	
	cout << "������� a = "; 
	cin >> a; 
	cout << "������� b = ";
	cin >> b;
	
	cout << "������� n = ";
	cin >> n;

	cout << "������� eps = ";
	cin >> eps;

	double *yi = new double [n + 1];
	double *y1 = new double [n + 1];
	double h=(b-a)/n;
	yi[0] = y0;
	y1[0] = y0;

	
	double *x = new double[n + 1];
	x[0]=a;
	for (int i = 1; i<=n ; i++)
	{
		x[i] = x[0] + i*h;
	}

	// ��������� �
	int d = 1, i=1;
	do
	{
		//������ eps-��������
		// ��������� ��� ����������� � 
		++i;
		runngeKut2(a, b, d, n, yi);
		d = d * 2;
		runngeKut2(a, b, d, n, yi);
		
	} while ( (fabs(y1[n] - yi[n])>eps) && (i>3));

	//�������� ������� ������ ���������� �
	
	for (int i=4; i<=n; i++)
	{
		Adams (a,b,1,i,yi,n,eps);
	}

	for (int i = 0; i <= n; i++)
	{
		cout << " x[" << i << "] = " << x[i] << "	y[" << i << "] = " << yi[i] <<"    ������ ������� y(x) =" << exp(-x[i]*x[i])<<endl;
	}
	
		}
