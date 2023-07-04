#include<iostream>
#include<math.h>

using namespace std;

//Declaracion de variables globales
double y[100],x[100];       //Vectores de ordenadas y abcisas.
double matriz[100][100];    //Matriz de procesamiento.
double a[100];              //venctor de coeficientes.
double F[100];              //vector de funciones.
int cantidadDeCoef;         //cantidad de coeficientes a calcular.
int cantidadDeDatos;        //cantidad de datos a ingresar.


void armarVector(double A[100])
{
    double s;

    for (int i=1;i<=cantidadDeDatos;i++)
    {
        cout<<"Ingrese el ["<<i<<"] valor: "; cin>>s;
        A[i]=s;

    }
}

void mostrarMatriz(double matriz[100][100])
{
    for(int i = 1;i<=cantidadDeCoef;i++)
    {
        for(int j = 1; j<=cantidadDeCoef; j++)
        {
            cout<<matriz[i][j]<<"\t";
		}

		cout<<"\n";
    }
}

void EntradaDeDatos()
{
    cout<<"Ingrese la cantidad de coeficientes: ";cin>>cantidadDeCoef;
    cout<<"Ingrese la cantidad de datos: ";cin>>cantidadDeDatos;
    cout<<"\nIngrese los datos de x: \n";
    armarVector(x);
    cout<<"\nIngrese los datos de y: \n";
    armarVector(y);
}

double f0(double m)
{
    return 1;
}

double f1(double m)
{
    return m;
}

double f2(double m)
{
    return pow(m,2);
}

double Funciones(int f,double m)
{
    switch (f)
    {
        case 1:return(f0(m));
        break;
        case 2:return(f1(m));
        break;
        case 3:return(f2(m));
        break;
        default:cout<<"Sin funciones diponibles";
    }
}

void Gauss(int n, double A[100][100],double B[100]){
    //El metodo de gaus consiste en dos procedimientos
    //double x[100];
    //Triangulaxión o Eliminacion hacia delante.
    for(int k = 1;k<=n-1;k++)
    {
        for(int i=k+1;i<=n;i++)
        {
            double q = A[i][k]/A[k][k];
            A[i][k]=0;
            B[i] = B[i] - q*B[k];
            for(int j = k+1; j <= n; j++)
            {
                A[i][j] = A[i][j] - q*A[k][j];
            }
        }
    }


    //Sustitucion Inversa o hacia atras
    
    a[n] = B[n]/A[n][n];
    
    for(int i = n-1;i>0;i--)
    {
        double s = 0;
        
        for(int j=i+1; j<=n; j++)
        {
            s=s+A[i][j]*a[j];
        }

        a[i]=(B[i]-s)/A[i][i];


    }
    cout<<"----------Resultados----------";
    
	for(int i = 1; i <= n; i++)
    {
        cout<<"\na["<<i-1<<"]: "<<a[i]<<"\t";
    }

}

void CalculoDeError()
{
    //calculo del error del modelo propuesto
    double sCuadrado = 0;

    switch (cantidadDeCoef)
    {
    case 2:
        for(int i = 1; i<=cantidadDeDatos; i++)
        {
            sCuadrado += pow((y[i]-(a[1]+a[2]*x[i])),2);   
        }
        break;
    case 3:
        for(int i = 1; i<=cantidadDeDatos; i++)
        {
            sCuadrado = sCuadrado + pow((y[i]-(a[1]+a[2]*x[i]+a[3]*pow(x[i],2))),2);   
        }
        break;
    default:
        break;
    }
        

    double s = sqrt(sCuadrado);
    cout<<"\nEl error S es de: "<< s;


}

void RegresionLineal()
{

    double yporf[100];
    //Se arma la matriz de la sumatoria del producto de las funciones

    for(int j = 1; j <= cantidadDeCoef ; j++)
    {    
        for(int k = 1; k<=cantidadDeCoef ;k++)
        {    
            double acumulador = 0;

            for(int i = 1; i <= cantidadDeDatos; i++)
            {
                acumulador += Funciones(j,x[i])*Funciones(k,x[i]);
            }
            matriz[j][k] = acumulador;


        }
    }    

    //mostrarMatriz(matriz);
    
    for(int j = 1;j<=cantidadDeCoef;j++)
    {
        double acumulador = 0;
        for(int i = 1; i <= cantidadDeDatos; i++)
        {
            acumulador += y[i]*Funciones(j,x[i]);
        }
        yporf[j]=acumulador;
    }       
    //Se invoca a la funcion de gauss para el calculo de los coeficientes.
    Gauss(cantidadDeCoef,matriz,yporf);

}

// Metodo de Gauss


//void RegresionLineal()
//{
//    
//}

int main(int argc, char const *argv[])
{
    
    EntradaDeDatos();
    RegresionLineal();
    CalculoDeError();

    return 0;
}
