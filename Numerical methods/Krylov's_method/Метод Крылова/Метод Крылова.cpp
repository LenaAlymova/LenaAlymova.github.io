// ���������� ������ �������.cpp 

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "��������� ������� �� ������.cpp"
#include "����� ������.cpp"
#include "������������ �������.cpp"
#include "���� �������.cpp"
#include "���������� ����������� �����.cpp"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	

	ifstream inSizeMatrix ("input_sizeMatrix.txt");
	ifstream inMatrix ("input_matrix.txt");
	ifstream inVector ("input_vector.txt");
	
	int n1 ;
	inSizeMatrix >> n1;// ���-�� ����� 
	cout <<"size matrix = ";
	cout << n1;
	cout <<endl;
	int n2;
	n2 = n1 + 1;

	//��������� ������
	double **arrX = new double *[n1];
	for(int i = 0 ; i < n1; i++)
	 arrX[i] = new double[n2];
	
	cout << endl;
	cout <<"matrix "<<endl;
	 
	for(int i = 0 ; i < n1; i++)
	{ for(int j = 0 ; j < n1; j++)
		{inMatrix  >> arrX[i][j];}
	}
	

		for(int i = 0 ; i < n1; i++)
	{ for(int j = 0 ; j < n1; j++)
		{cout <<  arrX[i][j] << "  " ;}
		cout << endl;

	}

	double **vectorC = new double *[n2];
	for(int i = 0 ; i < n2; i++)
	 vectorC[i] = new double[n1];
	

		double **vectorC1 = new double *[n1];
	for(int i = 0 ; i < n1; i++)
	 vectorC1[i] = new double[n2];

	double **x = new double *[n1];
	for (int i = 0; i < n1; i++)
		x[i] = new double[n2];

	double **zapas = new double *[n1];
	for (int i = 0; i < n1; i++)
		zapas[i] = new double[n2];

	double *vector = new double [n1];
	cout << endl;
	cout << "vector "<<endl; 
	 
	for(int i = 0; i < n1;i++)
	{inVector >> vector[i];}
	
	for(int i = 0; i < n1;i++)
	{cout <<  vector[i]  << " ";}
	cout <<endl;
	
	double *arrRootNumber = new double[n1];

	for(int i=0;i<3;i++)
	// ���� ���� ����� � ������ ���� �� ����� ��� ������� ����� ���� ��� �����. ����� ��� ����������� ����� �� ������� ����� 
	//�� ��������� �������� ������ �0 � ��� ������ �����������  ��������� �������� ������ �0 
	//�� ������ ������, ��� ����������� ����� 3� ��� ��������� ������� ���� �� ���� ������  
	{
	//����� � ����� ������� "��������� ������� �� ������" 
	//�������� ������� � �� ������ � (�������� �1 �2 �3)
	multiply_matrix_by_vector( arrX,vectorC, n1,n2,vector);
	// ����� ������������ ������� 
	permutation(vectorC , vectorC1,  n1, n2);
	 cout << endl;
	 cout << endl;
	 cout << endl;
	 cout << "=) "<<endl;

	 //����� ������
	gauss(vectorC1, zapas, n1, n2,arrRootNumber);
	//	for(int t=0;t < n1; t++)
	//	{cout << " arrRootNumber ["<< t << "] =  " <<arrRootNumber[t] <<endl;   }

	//���� ��������� = 0 �������� ������ �0( ��� �������� ����� ���� ������� ������� ��������)
	if(det(zapas,n1,n2) == 0)
	{	cout << "izmeni c0 " ;
		for(int i=0;i < n1; i++)
		cin >> vector[i]; }
	else 	break;

	//��� ��������(��� ��������� ������ ��� 2�2 ��� ��� � ������ ��� �������)
		 if(i == 2)
 {
	//		cout << endl;
	//		cout <<"rang matrix "<< endl;
	//		cout << endl;
			rang(vectorC1,zapas,n1,n2,arrRootNumber) ;
			
			cout <<endl;
			cout <<endl;
			cout <<endl;
			cout <<endl;
			for(int j=0;j < n1-1; j++)
				cout << " arrRootNumber ["<< j << "] =  " <<arrRootNumber[j] <<endl;  
			//���������� ����������� �����.
			 FindingEigenValues(arrRootNumber,n1-1,n1,arrX,vectorC1);
		 }
		//���������� ����������� �����.
	cout << "last 2x2 " << endl;
	FindingEigenValues(arrRootNumber,n1-1,n1, arrX,vectorC1);
	
	}
	// ����� ��������

	//���������� ����������� �����. 
	if(det(zapas,n1,n2) != 0){
	cout <<"last 3x3 " <<endl;
	FindingEigenValues(arrRootNumber,n1,n1, arrX,vectorC1);
	}




	//�������� 
	for (int k = 0; k < n1; k++)
		delete[]x[k];
	delete[]x;

	for (int k = 0; k < n1; k++)
		delete[]zapas[k];
	delete[]zapas;

	
	for (int k = 0; k < n1; k++)
		delete[]arrX[k];
	delete[]arrX;

	delete []vector;

		for (int k = 0; k <= n1; k++)
		delete[]vectorC[k];
	delete[]vectorC;

	for (int k = 0; k < n1; k++)
		delete[]vectorC1[k];
	delete[]vectorC1;
	
	delete[]arrRootNumber;
}