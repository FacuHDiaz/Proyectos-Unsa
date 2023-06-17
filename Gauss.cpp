#include<iostream>

using namespace std;

void mostrarMatriz(double A[100][100],int n)
{
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<A[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
}

void mostrarVector(double B[100],int n)
{
    for(int i=1;i<=n;i++)
	{
		cout<<B[i]<<"\t";
	}
	
}

void mostrarMatrizInversa(double A[100][100],int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=n+2;j<=2*n+1;j++)
		{
			cout<<A[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void mostrarResultados(double A[100][100],int n)
{
	for(int i=0; i<=n;i++)
	{
		cout<<A[i][n+1]<<"\t";
	}
}

void armarMatriz(double A[100][100],int n)
{
    double s;
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"\nIngrese el valor de A["<<i<<"]["<<j<<"]: ";cin>>s;
            		A[i][j]=s;
		}
	}
}


void armarVector(double B[100],int n)
{
    double m;
    for (int i = 1; i <= n; i++)
    {
        cout<<"\nIngrese el ["<<i<<"]° termino idependiente: ";cin>>m;
        B[i]=m;
    }
}

// Metodo de Gauss

void Gauss(int n, double A[100][100],double B[100]){
    //El metodo de gaus consiste en dos procedimientos
    double x[n];
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

    cout<<"\n----------Matriz escalonada---------- \n";
    mostrarMatriz(A,n);
   

    //Sustitucion Inversa o hacia atras
    
    x[n] = B[n]/A[n][n];
    
    for(int i = n-1;i>=0;i--)
    {
        double s = 0;
        
        for(int j=i+1; j<=n; j++)
        {
            s=s+A[i][j]*x[j];
        }

        x[i]=(B[i]-s)/A[i][i];


    }
    cout<<"----------Resultados----------"
    for(int i = 0; i <= n; i++)
    {
        cout<<"X["<<i<<"]"<<x[i]<<"\t";
    }

}

void MatrizAmpliada(double A[100][100], double B[100],int n)
{
	for(int i=1; i<=n;i++)
	{
		A[i][n+1]=B[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n+2; j<=2*n+1;j++)
		{
			if(i=j-n-1)
			{
				A[i][j]=1;
			}
			else
			{
				A[i][j]=0;
			}
		}
	}
}

void GaussJordan(double A[100][100],double B[100], int n)
{
	MatrizAmpliada(A,B,n);

	for(int k = 1 ; k <= n ;k++)
	{
		for(int i = 1; i <= n;i++)
		{
			if(i!=k)
			{
				double q = A[i][k]/A[k][k];
				A[i][k]=0;
				for(int j=k+1;j <= (2*n)+1; j++)
				{
					A[i][j]=A[i][j] - (q*A[k][j]);
				}
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		double diag = A[i][i];
		for(int j=1;j<=2*(n)+2;j++)
		{
			A[i][j] = A[i][j]/diag;
		}
	}

	cout<<"---------------Matriz Inversa----------"<<"\n";
	mostrarMatrizInversa(A,n);
	cout<<"---------------Mostrar Resultados---------------"<<"\n";
	mostrarResultados(A,n);

}

int main(int argc, char const *argv[])
{
    int tamanioSistema;
    double matrizCoeficientes[100][100],termIndependientes[100];

    cout<<"Ingrese el tamaño del sistema: ";cin>>tamanioSistema;


    armarMatriz(matrizCoeficientes, tamanioSistema);
    mostrarMatriz(matrizCoeficientes,tamanioSistema);

    armarVector(termIndependientes, tamanioSistema);
    mostrarVector(termIndependientes, tamanioSistema);

    //Gauss(tamanioSistema,matrizCoeficientes,termIndependientes);

    GaussJordan(matrizCoeficientes,termIndependientes,tamanioSistema);



    
    return 0;
}
