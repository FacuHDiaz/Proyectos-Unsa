#include<iostream>
#include<math.h>

using namespace std;

//Declaracion de variables globales.
double x0[100];                 //vector solucion propuesta
double x1[100];                 //vector solucion
int n,imax;                     //Tamaño del sistema y cantidad maxima de iteraciones
double epsilon;                 //Error permitido
double Jacobiano[100][100];     //Matriz Jacobiano
double dx[100];                 //Vector delta x

void llenarVector()
{
    cout<<"\nIngrese la solucion inicial:";
    for(int i = 1;i<=n;i++)
    {
        cout<<"\nX"<<i<<": ";cin>>x0[i];
    }
}

void DatosDeEntrada()
{
    cout<<"Ingrese el tamaño del sistema: ";cin>>n;
    cout<<"Ingrese el error permitido: ";cin>>epsilon;
    cout<<"Ingrese el número máximo de iteraciones: ";cin>>imax;
    llenarVector();
}

double F1(double x[100])
{
    return (pow(x[1],2)+x[2]-37);
}

double D1F1(double x[100])
{
    return x[1]*2;
}

double D2F1(double x[100])
{
    return 1;
}

double D3F1(double x[100])
{
    return 0;
}

double F2(double x[100])
{
    return (x[1]-pow(x[2],2)-5);
}

double D1F2(double x[100])
{
    return 1;
}

double D2F2(double x[100])
{
    return -x[2]*2;
}

double D3F2(double x[100])
{
    return 0;
}

double F3(double x[100])
{
    return x[1] + x[2] + x[3]-3;
}

double D1F3(double x[100])
{
    return 1;
}

double D2F3(double x[100])
{
    return 1;
}

double D3F3(double x[100])
{
    return 1;
}

void Gauss(){
    //El metodo de gaus consiste en dos procedimientos
    //Triangulaxión o Eliminacion hacia delante.
    for(int k = 1;k<=n-1;k++)
    {
        for(int i=k+1;i<=n;i++)
        {
            double q = Jacobiano[i][k]/Jacobiano[k][k];
            Jacobiano[i][k]=0;
            for(int j = k+1; j <= n+1; j++)
            {
                Jacobiano[i][j] = Jacobiano[i][j] - q*Jacobiano[k][j];
            }
        }
    }

    //cout<<"\n----------Matriz escalonada---------- \n";
    //mostrarMatriz(Jacobiano,n);
   

    //Sustitucion Inversa o hacia atras
    
    dx[n] = Jacobiano[n][n+1]/Jacobiano[n][n];
    
    for(int i = n-1;i>=0;i--)
    {
        double s = 0;
        
        for(int j=i+1; j<=n; j++)
        {
            s=s+Jacobiano[i][j]*dx[j];
        }

        dx[i]=(Jacobiano[i][n+1]-s)/Jacobiano[i][i];


    }

}

void matrizJacobiano()
{
    Jacobiano[1][1]=D1F1(x0);
    Jacobiano[1][2]=D2F1(x0);
    Jacobiano[1][3]=D3F1(x0);
    Jacobiano[1][4]=-1*F1(x0);

    Jacobiano[2][1]=D1F2(x0);
    Jacobiano[2][2]=D2F2(x0);
    Jacobiano[2][3]=D3F2(x0);
    Jacobiano[2][4]=-1*F2(x0);

    Jacobiano[3][1]=D1F3(x0);
    Jacobiano[3][2]=D2F3(x0);
    Jacobiano[3][3]=D3F3(x0);
    Jacobiano[3][4]=-1*F3(x0);
}

void NewtonRaphsonSE()
{
    int k;
    double m;
    bool fin = false;

    k=1;

    while(k<=imax and fin == false)
    {
        matrizJacobiano();
        Gauss();

        for(int i=1; i<=n;i++)
        {
            x1[i]=x0[i]+dx[i];
        }
        
        if(dx[1]<epsilon and dx[2]<epsilon and dx[3]<epsilon)
        {
            cout<<"\nSolución encontrada en "<<k<<" iteraciones.";
            cout<<"\nLa solución es: ";
            for(int i=1; i<=n; i++)
            {
                cout<<"\nX"<<i<<": "<<x1[i];
            }

            fin = true;
        }
        else
        {
            k = k + 1;
            for(int i=1;i<=n;i++)
            {
                x0[i]=x1[i];
            }
        }

    } 

    if(k>imax)
    {
        cout<<"Cantidad de iteraciones insuficiente";
    }
}

int main(int argc, char const *argv[])
{
    
    DatosDeEntrada();
    NewtonRaphsonSE();

    return 0;
}


