


using namespace std;

void massiw(double *&hi, double **zapasik, int qi, int ki, int n2)
{
	for (int p = qi; p < n2; p++)
		hi[p] = zapasik[qi][p] * (-zapasik[ki][qi] / zapasik[qi][qi]);
}

double  det(double **arr, int n1,int n2)
{


	double determinant = arr[0][0];
	
		for (int p = 0; p < n1-1; p++)
		{
			 determinant *= arr[p+1][p+1];
		}
		cout << "determinant " <<determinant ;
		cout << endl;
		return determinant;
	
}



void gauss(double **xi, double **zapasi, int n1, int n2, double *arrRootNumber)
{
	for (int k = 0; k < n1; k++)
	for (int p = 0; p < n2; p++)
		zapasi[k][p] = xi[k][p];
	double *zapas_1 = new double[n2];
	for (int q = 0; q < n1 - 1; q++)
	for (int k = q + 1; k < n1; k++)
	{
		massiw(zapas_1, zapasi, q, k, n2);
		for (int p = q; p<n2; p++)
			zapasi[k][p] = zapasi[k][p] + zapas_1[p];
	}
	double *rez = new double[n1];
	rez[n1 - 1] = zapasi[n1 - 1][n1] / zapasi[n1 - 1][n1 - 1];
	for (int k = n1 - 2; k >= 0; k--)
	{
		double s = zapasi[k][n1];
		for (int p = n1 - 1; p>k; p--)
		{
			s = s - zapasi[k][p] * rez[p];
			if ((p - k) == 1) s = s / zapasi[k][k], rez[k] = s;
		}
	}

	det(zapasi,n1,n2);

	for (int k = 0; k < n1; k++)
	{	cout<<"x"<<k + 1<<"= "<< rez[k]<<endl;
			arrRootNumber[k] = rez[k];
	
	}


	double *pr = new double[n1];
	for (int k = 0; k < n1; k++)
	{
		double s = 0; int asd = 0;
		for (int p = 0; p < n1; p++)
		{
			asd = asd + 1; s = s + xi[k][p] * rez[p];
			if (asd == n1) pr[k] = s;
		}
	}
//	for (int k = 0; k < n1; k++)
//cout<<"proverka "<<pr[k]<<endl;
	delete[]pr;
	

	//	cout << "matrix reduced to triangular form"<<endl;	
//for (int k = 0; k < n1; k++)
//	{
//	for (int p = 0; p < n2; p++)
//		{
//	cout << zapasi[k][p] << " ";
	//	}
	//cout << endl;
//	}

		

	 

}








