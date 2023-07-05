//---------- DECLARACION DE LIBRERIAS --------------------
#include <iostream> //cin y cout.
#include <math.h> //Funciones matemáticas.
#include <iomanip> //Formato de salida.
#include <locale.h> //Idioma de salida.
using namespace std;
//---------- DECLARACION DE VARIABLES GLOBALES. ----------
double X, Y, XF, H; //Valor de X e Y iniciales, valor de x final, paso.
//----------DECLARACION DE FUNCIONES Y PROCEDIMIENTOS.----
double f(double x, double y)
{
    return (exp(x-y)/2);
}

double fa(double x)
{
    return log(0.5*exp(x)+exp(1)/2);
}
void Nombre() //Titulo del programa.
{ 
     cout<<"\n\n";
     cout<<"------------------ RESOLUCIÓN POR MÉTODO DE RUNGE-KUTTA ------------------\n\n\n";
}
void IngresarDatos() //Ingreso de los datos del sistema de ecuaciones
{cout<<" + Ingrese intervalo en el que se desea obtener los valores de y: \n\n"; 
cout<<" - Cota inferior: "; cin>>X;
cout<<" - Cota superior: "; cin>>XF;
cout<<"\n";
cout<<" + Ingrese paso (h): " ; cin>>H;
cout<<" + Ingrese valor inicial de Y: " ; cin>>Y;
cout<<"\n\n";
}
void RungeKutta()
{
    double ya; //Solución analítica
    double er; //Error relativo
    double k1, k2, k3, k4; //Evaluaciones de f(x,y)
    while(X<XF)
    {
        cout<<fixed<<setprecision(8);
        k1=f(X,Y);
        k2=f(X+H/2, Y+k1*H/2);
        k3=f(X+H/2, Y+k2*H/2);
        k4=f(X+H, Y+k3*H);
        Y=Y+(H/6)*(k1+2*k2+2*k3+k4); //Solución numérica.
        ya=fa(X); //Solución analítica.
        X=X+H; //Cálculo de x.
        er=(100*fabs(Y-ya))/ya; //%Error relativo
        cout<<"("<<X<<" , "<<Y<<") \t - Solución analitica: "<<ya<<"\t -Error relativo: "<<er;
        cout<<"\n";
    }
}
        
int main()
{   
    Nombre();
    IngresarDatos();
    RungeKutta();
    return 0;
}