// Умножение матрицы на вектор.cpp : Defines the entry point for the console application.
//



using namespace std;

void multiply_matrix_by_vector(double **matrixA,double **vectorC, int n1,int n2, double *vector )
{
	for(int g = 0; g < n1; g++)
		{
		vectorC[0][g] = vector[g];
		}
	
	for(int k = 0; k < n1-1 ;k++)
	{	
		for(int i = 0; i < n1; i++)
		{	
			double number=0.0;
			for(int j =0; j < n1; j++)
			{
				number += matrixA[i][j]*vector[j];
			
			}
			vectorC[k+1][i] = number;
		}
		
		for(int p = 0; p < n1;p++)
		{
			vector[p] = vectorC[k+1][p];
		}
	}
	
	cout <<endl;

	for(int i = 0; i < n1; i++)
	{ 
		double numb = 0.0;
		
		for(int j=0; j < n1; j++)
		{
	numb += matrixA[i][j]*vector[j];
	
		}
		vectorC[n1][i] = numb;
		
	}
	
	
}
