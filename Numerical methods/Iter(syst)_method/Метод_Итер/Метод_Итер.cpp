
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;


void syst_iter(double *x0, double **A, double *B, double eps, int n)
{
	double *x1 = new double[n];
	for (int i = 0; i < n; ++i) x1[i] = x0[i];

	//cout<<"syst"<<endl;
	double pogr;
	do
	{
		pogr = 0;
		for (int i = 0; i < n; ++i)
		{
			double s = 0;
			for (int j = 0; j < n; ++j)
				s = s + A[i][j] * x0[j];
			
			x1[i] = B[i] + s;
		}
		for (int k = 0; k<n; ++k)
		{
			pogr = pogr + fabs(x1[k] - x0[k]);
			x0[k] = x1[k];
		}
	} while (pogr>n*eps);
}

void matr1(double **A, double *B, int m)
{
	for (int i = 0; i < m; ++i)
	{
		double r = A[i][i];
		for (int j = 0; j < m; ++j)
		{
			if (j == i&&j == m - 1) break;
			else
			{
				if (j == i) ++j;
				A[i][j] = (-1)*(A[i][j] / r);
			}
		}
		
		B[i] = B[i] / A[i][i];
		A[i][i] = 0;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "n=4" << endl;
	cout << "0,68x1 + 0,05x2 - 0,11x3 + 0,08x4 = 2,15" << endl;
	cout << "0,11x1 - 0,84x2 - 0,28x3 - 0,06x4 = 0,83" << endl;
	cout << "0,08x1 - 0,15x2 - x3 + 0,12x4 = -1,14" << endl;
	cout << "0.21x1 - 0,13x2 + 0.27x3 + x4 = 0,44" << endl;
	
	int n = 4;
	ifstream in("input.txt");
	double **a = new double *[n];
	for (int i = 0; i < n; ++i) a[i] = new double[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) in >> a[i][j];
	}
	double **mat = new double *[n];
	for (int i = 0; i < n; ++i) mat[i] = new double[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) mat[i][j] = a[i][j];
	}
	
	double *b = new double[n];
	double *x = new double[n];
	for (int i = 0; i < n; ++i) in >> b[i];
	for (int i = 0; i < n; ++i) x[i] = b[i];
	matr1(a, b, n);
	for (int i = 0; i < n; ++i)
	{
		cout << endl; for (int j = 0; j < n; ++j) cout << a[i][j] << "  ";
	}
	cout << endl;
	syst_iter(x, a, b, 0.0001, 4);
	cout << endl;

	for (int i = 0; i < n; ++i)
		cout << " x = " << x[i] << endl;

	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		double s = 0;
		for (int j = 0; j < n; ++j)
		{
			s = s + mat[i][j] * x[j];
		}
		cout << "s" << s;
	}

	system("pause");
	delete[]x;
	for (int i = 0; i < n; ++i) delete[]a[i];
	delete[]a;
	in.close();
	return 0;
}