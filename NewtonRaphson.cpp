#include<iostream>
#include<math.h>

using namespace std;

//Declaracion de variables globales.
double x0,x1,epsilon;
int imax,k;
bool fin;

double F(double x)
{
	return( sin(x) + cos(1 + pow(x,2)) - 1);
}

double DF(double x)
{
	return( cos(x) - sin(1 + pow(x,2))*2*x);
}


void NewtonRapson()
{
	fin = false;
	k=1;

	while(k <= imax and fin == false)
	{
		x1= x0 - (F(x0)/DF(x0));

		if(fabs(x0 - x1) < epsilon)
		{
			fin = true;
			cout<<"\nLa solucion se encontro en "<<k<<" iteraciones";
			cout<<"\nLa solucion es: X = "<<x1;
		}
		else
		{
			k = k+1;
			x0=x1;
		}
	}

	if(k > imax)
	{
		cout<<"\nCantidad de iteraciones insuficientes";
	}
}

int main(int argc, char const *argv[])
{
	//Entrada de datos
	cout<<"Ingrese un valor inicial: "; cin>>x0;
	cout<<"Ingrese el error permitido: "; cin>>epsilon;
	cout<<"Ingrese la cantidad maxima de iteraciones: "; cin>>imax;

	NewtonRapson();

	return 0;
}