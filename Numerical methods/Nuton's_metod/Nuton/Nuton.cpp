#include <iostream>
#include <fstream>
#include <math.h>
using namespace std; 
double *f;

double fct(int n)

{ if (n==0) return 1;
	double nt=1;
for (int i=1;i<=n;i++) nt=nt*i;
return nt;
}


double fc(int k,int m)
{ double s=0.0;
if (m==1) s=f[k+1]-f[k];
if (m==0) s=f[k];
else s=fc(k+1,m-1)-fc(k,m-1);
return s;
}


double newton (int n,double t)
{double sum=0.0, tk=t;
int k;
for (k=1;k<=n;k++)
{ sum=sum+tk*fc(0,k);
tk=tk*(t-k)/fct(k+1);
}
return f[0]+sum;
}

void main()
{ 
ifstream fcin("temp.txt");
int n;
double x,x0,h;
cout<<"kol-vo uzlov= ";
cin>>n;
cout<<"pervaya tochka= ";
cin>>x0;
cout<<"shag= ";
cin>>h;
cout<<"vvedite x";
cin>>x;
double t=(x-x0)/h;
f=new double [n];
for (int k=0;k<n;k++)
fcin>>f[k];
for (int k=0;k<n;k++) cout<<"x["<<x0+k*h<<"] "<<" y["<<f[k]<<"]"<<endl; 
cout<<newton(n,t);
system("pause");
}