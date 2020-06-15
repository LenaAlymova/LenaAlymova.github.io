//http://www.mathprofi.ru/differencialnye_uravnenija_primery_reshenii.html пример 4
#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;


double f(double x,double y){
	return (y*y-y)/x;
}


void Eyler(double  b, double a, int n,int n1,double *mas){

		
		double h;
		h = (b - a)/ n;

				double *x = new double[n];
			double *y =  new double[n];
		double *delta =  new double[n];
	
		
		x[0] = a;
		y[0]  = 0.5;
		

	for(int i=1;i<n;i++){
	
		x[i] = x[0]+i*h;	
		}

	 
	for(int i=0;i<n-1;i++){
		delta[i] = 
			
			((h*f(x[i],y[i])) + 
			
			(4* h* f(x[i]+h/2, y[i]+h/2)) + 
			
			(h*f(x[i]+h, y[i] - (h*f(x[i],y[i])) +    2*h*f(x[i]+h/2,  y[i]+h/2) )))/6;

		y[i+1] = y[i]+delta[i];

			
	}

		if(n!=n1){
		for(int i=0;i<n;i=i+2){
			cout << y[i] << " " << 1/(1+x[i])<<endl ; 
	}
	}
	else {
	for(int i=0;i<n;i++){
			cout << y[i] << " " << 1/(1+x[i])<<endl ; 
	}
	}
	


	mas[0] = y[0];
	mas[1] =y[n/2];
	mas[2] =y[n];
	

	delete[]delta;
	delete[]x;
	delete[]y;
}


int main(){

	setlocale(LC_ALL, "Rus" );
	double  a,b;
	int n;
	cout <<"b";
	cin >> b;
	cout << " а " ;
	cin >> a ;
	cout << "n" ;
	cin >> n;
	int n1;
	n1 = n;

		double eps;
		cout <<"eps: " ;
		cin >> eps;
		cout <<endl;
		
	for(;;){
				
		double *mas1 = new double[3];
	
	Eyler(b,  a,  n, n1, mas1 )  ;
	
	cout << endl;
	cout << "Пересчет при n*2 " <<endl;
	cout << endl;
		double *mas2 = new double[3];
		
	Eyler(b,  a,  n*2, n1, mas2) ;
	


	if (fabs((mas1[0]-mas2[0]))<eps  && fabs((mas1[1]-mas2[1]))<eps && fabs((mas1[2]-mas2[2]) )<eps)  
		{

			
				
			break;
		}
		else {
			
			n=n*2;
			}
		
		cout << endl;


			delete []mas1;
		   delete []mas2;
		
		}


	

		cout << endl;

	
	}