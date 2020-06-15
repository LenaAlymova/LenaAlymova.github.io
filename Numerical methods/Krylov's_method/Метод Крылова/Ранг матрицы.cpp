using namespace std;

void rang (double **vectorC1, double **zapasi, int n1, int n2,double *arrRootNumber)
{
	n2=n2-1;
	n1 = n1-1;
	gauss(vectorC1,zapasi,n1,n2,arrRootNumber);
	cout <<" Happy end " <<endl;
}