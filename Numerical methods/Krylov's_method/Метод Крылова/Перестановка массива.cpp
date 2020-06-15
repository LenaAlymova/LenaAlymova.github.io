// Перестановка массива.cpp : Defines the entry point for the console application.
//
using namespace std;

void permutation(double **vectorC,double **vectorC1, int n1,int n2)
{
	
		cout<< "c0   c1   c2   c3" << endl; 
	for(int i = 0; i < n1;i++)
	{
		for(int j = 0; j < n2; j++)
			{
				vectorC1[i][j] = vectorC[j][i];
			
			}
	}
		  for (int k = 0; k < n1; k++)
	  {
		 for (int p = 0; p < n2; p++)
			{
			cout << vectorC1[k][p] << "    ";
			}
		cout << endl;
	  }

  

}
