#include<iostream>
#include<math.h>

using namespace std;

//Declaracion de variables globales
double y[100],x[100];   //vectores de los pares de datos de entrada
int n;                  //cantidad de pares de datos ingresados
double valor;           //cantidad a interpolar

void armarVector(double vector[100])
{
    
    double q;

    for(int i = 1; i <= n; i++)
    {
        cout<<"Ingrese el valor ["<<i<<"]: "; cin>>q;
        vector[i]=q;
    }
}

void EntradaDeDatos()
{
    cout<<"-----ENTRADA DE DATOS-----"<<endl;
    cout<<"Ingrese la cantidad de pares de datos a introducir: ";cin>>n;
    cout<<"Ingrese los valores de x: "<<endl;
    armarVector(x);
    cout<<endl;
    cout<<"Ingrese los valores de y: "<<endl;
    armarVector(y);
    cout<<endl;
    cout<<"Ingrese el valor que desea realizar la interpolacion: ";cin>>valor;
    
}

double L(int m)
{
    //Li(x)
    //definicion de productorio: Π[(x-xj)/(xi-xj)]=[(x-x1)/(x2-x1)]*[(x-x3)/(x2-x3)]*[(x-x4)/(x2-x4)]*...*[(x-xn)/(x2-xn)]
    double acumulador = 1;
    int i = 1; 

    while(i<=n)
    {
        if(i != m)
        {
            acumulador *= (valor - x[i])/(x[m]-x[i]);
        }
        else
        {
            acumulador+=0;
        }
        i++;
    }

    return acumulador;
}

void InterpolacionLagrange()
{
    double acumulador = 0;

    for(int i = 1; i <= n; i++)
    {
        acumulador += y[i]*L(i);
        //cout<<acumulador<<"     ";
    }

    cout<<"-----RESULTADOS-----"<<endl;
    cout<<"Para x = "<<valor<<", y = "<<acumulador<<endl;
}

int main(int argc, char const *argv[])
{
    EntradaDeDatos();
    InterpolacionLagrange();


    return 0;
}
