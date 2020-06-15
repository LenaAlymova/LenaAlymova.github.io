

using namespace std;

void FindingSobstbenVector(double *masSobsChisel, int n,double *masKoef,double **vectorC1)
{


double**beta=new double *[n];
	for (int k=0;k<n;k++) beta[k]=new double[n];

	//находим сами бетта
	for (int j=0;j<n-1;j++)
	{
		for (int i=0;i<n;i++)
		{
			beta[0][i]=1.0;
			beta[j+1][i]=(masSobsChisel[i]*beta[j][i])-masKoef[j];
		}
	}

	//матрица где буду храниться собственніе векторы
	double **vectors=new double *[n];
	for (int k=0;k<n;k++) vectors[k]=new double[n];


	//находим собственные векторы
	for (int i=0;i<n;i++)
	{

		for (int j=0;j<n;j++)
		{
			vectors[i][j]=vectorC1[j][2]+beta[n-2][i]*vectorC1[j][1]+beta[n-1][i]*vectorC1[j][0];
			
		}
		
	} 
	

	//выводим собственные векторы
	for (int i=0;i<n;i++)
	{
		cout<<"sob_vector ["<<i+1<<"] = ";

		for (int j=0;j<n;j++)
		{
			cout<<vectors[i][j]<<" ";
		}
		cout<<endl;
	} 


	//Проверка 

//void (  double **vectors,double **A, int n, double * sobstChisla)
//{
	double ** proverka = new double*[n];
	for(int i =0; i <n;i++)
	proverka[i] = new double [n];

	
	ifstream inMatrix ("input_matrix.txt");
	
	double **A = new double *[n];
	for(int i = 0; i < n;i++)
		A[i] =new double[n];
	cout << endl;
			cout << "matrix A  " << endl;
	for(int i = 0 ; i < n; i++)
	{ for(int j = 0 ; j < n; j++)
		{inMatrix  >> A[i][j];
		cout << A[i][j] << "  ";
	}
	cout << endl;
	}
	
	cout << endl;
	cout << "proverka"<< " A*x " <<endl; 
for(int k=0;k<n;k++)
{
for(int p=0;p<n;p++)
{
double s=0.0;
for(int j=0;j<n;j++) s=s+A[k][j]*vectors[p][j];
proverka[k][p]=s;
}
}

cout <<endl;
	for(int i =0; i < n;i++)
	{
	for(int j = 0; j<n; j++)
	{
	cout << proverka[i][j] << " ";
	}
	cout << endl;
	}
	

	cout << "lamda * x" <<endl;
	double **prov2 = new double*[n];
		for (int i=0;i<n;i++)
prov2[i] = new double [n];


	for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
{
	prov2[i][j]=vectors[j][i]*masSobsChisel[j];
}
}


	//cout << "matrix 2  "<< endl;
		for(int i =0; i < n;i++)
	{
	for(int j = 0; j<n; j++)
	{
	cout << prov2[i][j] << " ";
	}
	cout << endl;
	}


}	

//Собственные вектора
void  nahoshdenieSobstvenyhChisel(double a,double b,double c, double d,int n,double tr, double *x,double **vectorC1)
{

	double nachaloOtrezka,konetsOtrezka;
	//Первое что делаем так это находим (аналитически)отрезок  на котором существуют корни.
	cout << "nachalo: ";
	cin >> nachaloOtrezka;
	cout << "konets: ";
	cin >> konetsOtrezka;
	cout <<endl;
	
	double  lamda;
	double  solve;
	double *masSobsChisel = new double[n+1];
		int g = 0;
		for(int i = nachaloOtrezka; i <= konetsOtrezka ; i++)
		{
			if(n ==2)	solve  =  a*i*i*i + b*i*i - c*i - d;
			if(n ==3) 	solve  =  a*i*i*i - b*i*i - c*i - d;
		
		
//	cout << a << " * " << i << "^3 " << " - " << b << " * " << i <<"^2 " << " - " << c << " * " << i << " - " << d << " = " << solve << endl;
//cout << solve << " " ;
//		cout << i << " " ;
			if(  solve == 0)
			{
				lamda = i ;
				//cout << lamda << " ";
			for(;;g++)
			{
			masSobsChisel[g] = i;
			break;
			}
			g++;
			cout << "lamda= " << lamda <<endl;
			}
		}

	//cout <<"mas" <<endl;
		if(n == 2)
		{
	double sumLamda = 0.0,endLamda;
		
				for(int a = 0; a <n;a++)
				{
					sumLamda +=masSobsChisel[a];
				}
		//		cout <<"sum Lamda: "  << sumLamda << endl;
			//	cout << "tr: " <<tr << endl;
			endLamda =  tr - sumLamda;
			n++;
			masSobsChisel[n-1] = endLamda; 
		}
		


		cout <<"Sobstvenue znacheniya: ";
		for(int f =0; f < n; f++)
		{
			cout << masSobsChisel[f] <<" " ;
		}
		cout << endl;
	 
		//Находим собственные вектора
 FindingSobstbenVector(masSobsChisel,n,x,vectorC1);



		delete []masSobsChisel;
}

//Нахождение коэффициентов при лямда
void metodKasatelnyh(double *x,int n,double tr,double **vectorC1)
{
	//Если ранг понижен тогда коэффицики будут такими.
	double A,B,C,D;
	if(n == 2){
	A = 0;
	B = 1;
	C = x[ 0 ];
	D = x[ 1 ];
	nahoshdenieSobstvenyhChisel(A,B,C,D,n,tr,x,vectorC1);
	}
	

	//Если матрица такого же размера как и была(без понижения ранга) то кофики  такие
	
	if(n == 3){
	A = 1;
	B = x[ 0 ];
	C = x[ 1 ];
	D = x[ 2 ];
		
	nahoshdenieSobstvenyhChisel(A,B,C,D,n,tr,x,vectorC1);
	

	
	}
	
}
