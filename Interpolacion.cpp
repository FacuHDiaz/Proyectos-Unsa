#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

//Variables globales
double xa,xb;   // Extremos del intervalo
double xm;      // Punto medio del intervalo
double epsilon; // Error permitido
int imax,k;     // Cantidad maxima de iteraciones

double F(double x)
{
    return ((pow(x,2)/4) - sin(x));
}

void ingresarDatos()
{
    cout<<"Ingrese el extremo inferior del intervalo: "; cin>>xa;
    cout<<"Ingrese el extremo superior del intervalo: "; cin>>xb;
    cout<<"Ingrese el error permitido: "; cin>>epsilon;
    cout<<"Ingrese la cantidad maxima de iteraciones: "; cin>>imax;

}

void Interpolacion()
{
    bool fin = false;
    k=1;

    while(k<=imax and fin == false)
    {
        xm = ((xb*F(xa)-xa*F(xb))/(F(xa)-F(xb)));
        
        if(fabs(xa-xb)<epsilon and fabs(F(xm))<epsilon)
        {
            fin = true;
            cout<<fixed<<setprecision(10);
            cout<<"\nLa solucion se encontro en "<<k<<" iteraciones";
            cout<<"\nLa solucion es: x = "<<xm;

        }
        else
        {
            k = k+1;

            if((F(xm)/fabs(F(xm))) == (F(xa)/fabs(F(xa))))
            {
                xa = xm;
            }
            else if ((F(xm)/fabs(F(xm))) == (F(xb)/fabs(F(xb))))
            {
                xb = xm;
            }

        }
        
    }

    if(k>imax)
    {
        cout<<"Iteraciones Insuficientes";
    }
    
}

int main(int argc, char const *argv[])
{
    ingresarDatos();

    Interpolacion();

    return 0;
}
