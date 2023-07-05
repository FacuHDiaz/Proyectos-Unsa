#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

//Declaracion de variables globales.

double t, z1,z2,q;      // Valores Iniciales del EDO.
double tf;              // Valor final.
double h;               // Valor del Paso.
double errorPorcen;     // Error del metodo RK 


//Declaracion de constantes globales.

const double R = 1;
const double C = 0.5;
const double L = 2;
const double Pi = 3.14159265358979323846;

void mostrar()
{
    cout<<setprecision(7)<<t<<"\t\t\t|"<<z1<<"\t\t\t|"<<z2<<"\t\t\t|"<<q<<"\t\t\t|"<<errorPorcen<<endl;
}

void EntradaDeDatos()
{
    cout<<"-----ENTRADA DE DATOS-----"<<endl;
    cout<<"Ingrese el valor inicial de t    : ";cin>>t;
    cout<<"Ingrese el valor final de t      : ";cin>>tf;
    cout<<"Ingrese el valor inicial de q    : ";cin>>z1;
    cout<<"Ingrese el valor inicial de i    : ";cin>>z1;
    cout<<"Ingrese el el valor del paso     : ";cin>>h;
}

double f1(double t, double z1, double z2)
{
    return (z2);
}

double f2(double t, double z1, double z2)
{
    return (-(z1)-(z2*0.5)+(2.5)*cos(50*Pi*t));
}

double qanalitica(double t)
{

    double numerador = (1.0 / 6.0) * (375 * Pi * sin(50 * Pi * t) 
                        - 15 * cos(50 * Pi * t) * (2500 * Pi * Pi - 1) + (15 * cos(0.25 * sqrt(15) * t) * (2500 * Pi * Pi - 1) 
                        - sqrt(15) * (2500 * Pi * Pi + 1) * sin(0.25 * sqrt(15) * t)) * exp(-0.25 * t));

    double denominador = (6250000 * Pi * Pi * Pi * Pi - 4375 * Pi * Pi + 1);

    return numerador / denominador;


}

void RungeKutta()
{
    double k1,k2,k3,k4,m1,m2,m3,m4;

    cout<<"-----TABLA DE RESULTADOS----"<<endl;
    cout<<"t"<<"\t\t\t"<<"|q"<<"\t\t\t\t"<<"|q'"<<"\t\t\t\t"<<"|qan"<<"\t\t\t\t|Error(%)"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    
    while(t<tf)
    {
        k1 = f1(t,z1,z2);
        m1 = f2(t,z1,z2);
        k2 = f1(t + h/2, z1 + k1*h/2, z2 + m1*h/2);
        m2 = f2(t + h/2, z1 + k1*h/2, z2 + m1*h/2);
        k3 = f1(t + h/2, z1 + k2*h/2, z2 + m2*h/2);
        m3 = f2(t + h/2, z1 + k2*h/2, z2 + m2*h/2);
        k4 = f1(t + h, z1 + k3*h, z2 + m3*h);
        m4 = f2(t + h, z1 + k3*h, z2 + m3*h);
        
        z1 = z1 + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
        z2 = z2 + (h/6)*(m1 + 2*m2 + 2*m3 + m4);
        q=qanalitica(t+h);

        errorPorcen = fabs((z1-q)/q)*100;

        t = t+h;

        

        mostrar();

    }
}

int main(int argc, char const *argv[])
{
    cout<<endl;

    EntradaDeDatos();
    RungeKutta();
    
    
    cout<<endl;
    return 0;
}
