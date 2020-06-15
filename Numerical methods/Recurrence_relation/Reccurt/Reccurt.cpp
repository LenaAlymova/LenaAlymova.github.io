// recurruentnie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int func (int n);
int power(double INPUT); 
void chekc(char *a_1);
double skleika(char *a_1);
bool power_1 (int n);
double progressia(double b1,int n, double q);
int C=2;
int k1=-2, k2=7;

void main()
{

setlocale( LC_CTYPE, ".1251" );
	int n=0;
	cout<<"Enter N \n";

	//!!!!!!!!!!!!!!!!!!! проверка на корректность ввод
	
	char a_1[256];
		cin>>a_1;
	
		// проверка на символы 

		chekc(a_1);

		// склейка в число 

		n=skleika(a_1);


	//определяем является ли степенью двойки
	int priznak;
	int n1=n;
	do 
	{
		if (n1==1) break;
		priznak=n1%2;
		n1=n1/2;

		
		if (priznak!=0)
		{
			cout<<"Введенное число не является степенью двойки, попробуй другое \n";
			cin>>a_1;
			chekc(a_1); 
			n=skleika(a_1);
		}
	}
	while (n1>1);
	

	//считаем в цикле 
	double C0,C1;
	if (n==1) C1=1;
	C0=C;
	for (int k=1;k<n;k=k*2)
	{
		C1=(k1*C0)+k2;
		C0=C1;
	}

	cout<<endl<<" C[n]= (в цикле) ="<<C1<<endl;


	//считаем в формуле
	double C2=0.0;
	double C_2=k1*C+k2;
	double C_3=k1*C_2+k2;
	double X1=C_3-C_2;
	double X2=C_2-C;
	double koef=X1/X2;
	//cout<<"\n C_2 = "<<C_2<<" C_3 = "<<C_3<<" koef = "<<koef<<" n= "<<power(n);
	cout<<endl<<" C[n]= (в формуле) ="<<C+progressia(C_2-C,power(n),koef)<<endl; 
	

	//считаем в функции
	 int C3;
	 C3=func(n);
	 cout<<endl<<" C[n]= (в функции) ="<<C3<<endl;

	
	
	system("pause");
}

double progressia(double b1,int n, double q)
{
	return (b1*(1-pow(q,n)))/(1-q);
}

int power(double INPUT)
{
	int n1=INPUT;
	int count=0;
	do 
	{
		if (n1==1) break;
		n1=n1/2;
		count++;
	}
	while (n1>1);
	return count;

}

void chekc(char *a_1)
{
	// проверка на символы 

		 for (int k=0;;k++)
		{
			int count=0;
	
			for (int p=0;p<strlen(a_1);p++)
			{
				int a_11=static_cast<int>(a_1[p]);
				if (static_cast<int>(a_1[0])<48 || static_cast<int>(a_1[0])>57 ) count=1;
				if ( a_11<48 || a_11>57 ) count=1;
			}
			if (count ==1 ) 
			{
				cout<<"Введено некорректно, попробуй еще "<<endl;
				cin>>a_1; 
			}
			else break;
		}
}

double skleika(char *a_1)
{
	int n=0;
	for (int i=0;i<strlen(a_1);i++)
		{
			double power=(strlen(a_1)-(i+1));
			n=n+(static_cast<int>(a_1[i])- 48)*pow(10,power);
		}
	return n;
}



int func (int n)
{
	
	if (power_1(n)==1) C=(k1*C)+k2;
	//cout<<"\n"<<power_1(n)<<" \n";
	//cout<<" \n C= "<<C<<" \n";
	n--;
	if (n==1) return C;
	func(n);
	return C;
}

bool power_1 (int n)
{
	int count=0;
	int priznak;
	int n1=n;
	do 
	{
		if (n1==1) break;
		priznak=n1%2;
		n1=n1/2;

		
		if (priznak!=0)
		{
			count=1;
		}
	}
	while (n1>1);
	if (count ==1 ) return false;
	else return true;
}

