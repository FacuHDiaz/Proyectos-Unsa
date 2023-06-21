#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//Variables globales. Datos y resultados.
double x0;        //solucion inicial.
double epsilon;   //epsilon. cota de error.
int imax;         //Cant.de iteraciones.

double x1;        //raiz de la f(x).
int k;            //cant. de iteraciones.  

double F(double x)
{
	return x-exp(-1*x);
}

double Fp(double x)
{
	return 1+exp(-1*x);
}

void CargarDatos()
{
	cout<<"Escriba un valor inicial    : "; cin>>x0;
	cout<<"Escriba epsilon             : "; cin>>epsilon;
    cout<<"cantidad max. de iteraciones: "; cin>>imax;
}

void NR()
{
	bool fin;
	
	k=1;
	fin=false;
	while(k<=imax and fin==false)
	{
		//Metodo.
		//x1 = G(x0);		
		x1 = x0 - (F(x0)/Fp(x0));
		
		if(fabs(x0-x1) < epsilon)
		{
			fin=true;
			cout<<fixed<<setprecision(10);
			cout<<"\nSolucion en "<<k<<" iteraciones";
			cout<<"\nx = "<<x1;			
		}
		else
		{
			//Nos preparamos para la pr�xima iteraci�n.
			k=k+1;
			x0=x1;
		}		
	}
	
	if(k > imax)
	{
		cout<<"La cant. de iteraciones es insuficiente";
	}	
}


int main()
{
	CargarDatos();
	NR();

	cout<<"\n\n\n";
	return 0;
}

