#include "������� ���������� ���������.cpp"

using namespace std;

void FindingEigenValues(double *arrRootNumber,int n,int n2, double **initialMatrix,double **vectorC1)
{
	double *x = new double[n];
	double trA = 0.0;//����� ������� ���������

	for(int i = 0;  i < n2; i++)
	{
	 trA += initialMatrix[i][i];//����������� ������� 
	}
	cout << "trA= " << trA <<endl;

	for(int j = 0; j < n; j++)
	{
		x[n-(j+1)]  = arrRootNumber[j];
	cout << "x[ "<<n-(j+1) <<" ] = "  <<x[n-(j+1)]<<endl;
	}
	cout << "voy" <<endl;
	


	for(int o = 0; o < n; o++)
	{
	cout <<"x=  " <<  x[ o ] << endl ;
	
	}
	if(n == 2)
	{
		metodKasatelnyh(x,n,trA,vectorC1);
	}
if(n == 3)
	{
		metodKasatelnyh(x,n,trA,vectorC1);
	}



		delete[]x;
}

