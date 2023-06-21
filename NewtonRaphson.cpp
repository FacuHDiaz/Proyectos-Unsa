#include<iostream>
#include<math.h>

//Declaracion de variables globales.
double x0,x1,epsilon;
int imax,k;
bool fin;

double F(double x)
{
	return( sin(x) + cos(pow(x,2)) - 1);
}

void NewtonRapson()
{
	
}

void Gauss(int n, double A[100][100],double B[100])
{}
