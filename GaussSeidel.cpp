#include<iostream>
#include<math.h>

using namespace std;

//Declaracion de variables globales.
double A[100][100],X[100],epsilon,s;
int n, imax,k;
bool fin;

void armarMatriz()
{
	double s = 0;

	for(int i = 0; i<=n;i++)
	{
		for(int j = 0;j <= (n+1); j++)
		{
			cout<<"Ingrese el valor ["<<i<<"]["<<j<<"]: "; cin>>s;
			A[i][j]=s
		}
	}
}

void GaussSeidel()
{
 	fin = 0;
	K=0;

	while(k<=0 and fin == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			s = 0;
			for(int j = 0; j <= (i-1); i++ )
			{
				s = s + A[i][j]*X[j];
			}
			for(int j = i+1; j <= n; j++ )
			{
				s = s + A[i][j]*X[j]
			}
		}

		for()
		{}
	}
}

int main(int argc, char const *argv[])
{

}

