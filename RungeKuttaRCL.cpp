#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

//Declaracion de variables globales.

double t, i3, i2;       // Valores Iniciales del SEDO.
double tf;              // Valor final.
double h;               // Valor del Paso.
const double R = 45000;
const double C = 0.0000000303;
const double L = 0.0068;

void mostrar()
{
    setprecision(12);
    cout<<t<<"\t\t"<<i2<<"\t\t"<<i3<<endl;
}

void EntradaDeDatos()
{
    cout<<"Ingrese el valor inicial de t: ";cin>>t;
    cout<<"Ingrese el valor fianl de t: ";cin>>tf;
    cout<<"Ingrese el valor inicial de i3: ";cin>>i3;
    cout<<"Ingrese el valor inicial de i2: ";cin>>i2;
    cout<<"Ingrese el el valor del paso: ";cin>>h;
}

double f1(double t, double i3, double i2)
{
    return (i3/(R*C));
}

double f2(double t, double i3, double i2)
{
    return (-(i3/(R*C))-(i2*R/L)+220*cos(100*t));
}

void RungeKutta()
{
    double k1,k2,k3,k4,m1,m2,m3,m4;

    while(t<tf)
    {
        k1 = f1(t,i3,i2);
        m1 = f2(t,i3,i2);
        k2 = f1(t + h/2, i3 + k1*h/2, i2 + m1*h/2);
        m2 = f2(t + h/2, i3 + k1*h/2, i2 + m1*h/2);
        k3 = f1(t + h/2, i3 + k2*h/2, i2 + m2*h/2);
        m3 = f2(t + h/2, i3 + k2*h/2, i2 + m2*h/2);
        k4 = f1(t + h, i3 + k3*h, i2 + m3*h);
        m4 = f2(t + h, i3 + k3*h, i2 + m3*h);
        
        i3 = i3 + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
        i2 = i2 + (h/6)*(m1 + 2*m2 + 2*m3 + m4);

        t += h;

        mostrar();

    }
}

int main(int argc, char const *argv[])
{
    EntradaDeDatos();
    RungeKutta();

    return 0;
}
