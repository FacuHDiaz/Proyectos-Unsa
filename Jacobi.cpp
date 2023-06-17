#include <iostream>
#include <math.h>

using namespace std;

//Variables globales
int n,imax,numIt;
double A[100][100],x0[100],x1[100],epsilon;

void mostrarMatriz()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1; j<=n+1; j++)
		{
			cout<<A[i][j]<<"\t";
		}

		cout<<"\n";
	}
}

void mostrarResultados()
{
	cout<<"\nLa solucipon del sistema se enconto en "<<numIt<<" iteraciones.\n";
	for(int i = 1; i<= n; i++)
	{
		cout<<x1[i]<<"\t";
	}
}

void llenarMatriz()
{
	double s=0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n+1; j++)
		{
			cout<<"\nIngrese el elemento ["<<i<<"]["<<j<<"] de la matriz: "; cin>>s;
			A[i][j]=s;
		}
	}
}

void solucionInicial()
{
	double s = 0;

	for(int i = 1; i <=n; i++)
	{
		cout<<"\nIngrese el elemento ["<<i<<"] de la solucion propuesta"; cin>>s;
		x0[i]=s;
	}
}

void DatosDeEntrada()
{
	cout<<"\n-----DATOS DE ENTRADA-----";
	
	cout<<"\nIngrese la cantidad de iteraciones: "; cin>>imax;
	cout<<"\nIngrese el error maximo: "; cin>>epsilon;
	cout<<"\nIngrese el tamaño del sistema: ";cin>>n;
	cout<<"\nMatriz Ampliada del sistema";
	llenarMatriz();
	cout<<"\nSolucion Propuesta";
	solucionInicial();
}

void Jacobi()
{
	bool fin = false;
	double s1,s2;
	int k = 1,i;

	while(k<=imax && fin == false)
	{
		for(int i=1;i<=n;i++)
		{
			s1=0;
			for(int j = 1; j <= i-1; j++)
			{
				s1 = s1 + A[i][j]*x0[j];
			}
			s2=0;
			for(int j = i+1; j <= n; j++)
			{
				s2 = s2 + A[i][j]*x0[j];
			}

			x1[i] = (A[i][n+1] - s1 - s2 )/A[i][i];
		}
		
		i = 1;

		while(i<=n && fabs(x1[i]-x0[i])<epsilon)
		{
			i=i+1;
		}

		if (i>n)
		{
			numIt = k;
			fin = true;
		}
		else
		{
			k=k+1;
			for (i=1;i<=n;i++)
			{
				x0[i] = x1[i];
			}
		}

		if(k > imax)
		{
			cout<<"\nCantidad de iteraciones insuficiente";
		}
	}
}

bool diagonalDominante()
{
	int me=0 ,ig=0;
	double suma;

	for (int i=1; i<=n;i++)
	{
		suma = 0;
		for(int j=1;j<=n;j++)
		{
			if(j!=i)
			{
				suma = suma + fabs(A[i][j]);
			}
		}

		if(suma < fabs(A[i][i]))
		{
			me = me + 1;

		}
		else
		{
			if(suma == fabs(A[i][i]))
			{
				ig = ig + 1;
			}
		}
	}

	if (me > 0 && ig == n-me)
	{return true;}
	else
	{return false;}
}


int main(int argc, char const *argv[])
{
	DatosDeEntrada();

	if(diagonalDominante() == true)
	{
		cout<<"\nEl sistema cumple con la condicion de convergencia";
		Jacobi();
		mostrarResultados();
	}
	else
	{
		cout<<"\nEl sistema no cumple con la condicion de convergencia.";
		cout<<"\nPor favor utilice otro metodo";
	}
	
	return 0;
}

