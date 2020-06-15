#include<iostream>
#include<fstream>
using namespace std;
double lag(double *yk,int n,double t)

{ double fact=1;
for (int i=2;i<n;i++)
fact*=i;


int znak;
znak=(n%2==0)?1:-1;


double fi=1, ln=0;
double ln_xk;


for (int k=0;k<n;k++)
{ double S=1;
for (int i=0;i<n;i++) 
if (i!=k) S=S*(t-i);
ln_xk=yk[k]*S*fi;
ln=ln+ln_xk;
fi=fi*(-1)*(n-k-1)/(k+1);


}

return ln*znak/fact;
}

void main()
{

ifstream in("temp.txt");
double x,x_0,h;
int n;
cout<<" kolichestvo tochek";
cin>>n;
//n--;
cout<<"\n shag";
cin>>h;
cout<<"\n pervaya tochka=";
cin>>x_0;
cout<<"\n x=";
cin>>x;
double t=(x-x_0)/h;

double *yk=new double [n];
for(int i=0;i<n;i++)
in>>yk[i];
for(int i=0;i<n;i++)
cout<<"x["<<i<<"]="<<x_0+h*i<<" yk["<<i<<"]="<<yk[i]<<"\n";

cout<<" znachenie v tochke x= "<<x<<" sostovlyaet "<<-lag(yk,n,t);
delete [] yk;
system("pause");
}