#include <iostream>
#include <fstream> 
using namespace std;

double funk(double x)
{
	return x;
}

double simpson(double a, double b, int m)
{
	double s1 = 0, s2 = 0, h = (b - a) / (2 * m);
	for (int k = 1; k <=( m - 1); k++)
	{
		s1 = s1 + funk(a + 2 * k*h);
	}
	for (int k = 1; k <= m; k++)
	{
		s2 = s2 + funk(a + (2 * k - 1)*h);
	}
	return h / 3 * (funk(a) + funk(b) + 2 * s1 + 4 * s2);
}

void main()
{
	double a, b;
	cout<<"vvedite nijniy i verhniy predeli integrirovaniya"<<endl;
	cin>>a>>b;
	double e;
	cout<<"vvedite tochnost' vichesleniy"<<endl;
	cin>>e;

	double m=3, I1 = simpson(a, b, m), k = 0, I2=simpson(a, b, 2*m) ;
	for (; fabs(I1 - I2) >= e;)
	{
	    I1=I2;
		m = 2 * m;
		I2= simpson(a, b, 2*m);

		
	}
	cout<<I2<<endl<<k<<endl;
	system("pause");
	
}
