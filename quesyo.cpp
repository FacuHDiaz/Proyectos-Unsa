//Declaración de librerías
#include <iostream> //cin y cout
#include <math.h> //Funciones matematicas
#include <iomanip> //Formato de Salida.
using namespace std;
//Declaración de variables globales
double Y[50]; //Vector de Yi
double X[50]; //Vector de Xi
int N; //Cantidad de puntos de la tabla
double xp; //Valor de interpolacion para evaluar el polinomio
double L; //Funciones de Lagrange Li.
double P; //Valor de xp evaluado en el polinomio encontrado.
//Funcion para cargar datos.
void IngresarDatos()
{
//variables locales
int i;//Indice
cout<<"Ingrese valor interpolacion:";
cin>>xp;
cout<<"Ingrese cantidad de datos :";
cin>>N;
for(i=0; i<=N; i++)
{
cout<<"X["<<i<<"]:";
cin>>X[i];
cout<<"Y["<<i<<"]:";
cin>>Y[i];
}
}
void Lagrange()
{
//Variables Globales
int i,j; //Indice
P=0;
for(i=0; i<=N; i++)
{
L=1;
for(j=0; j<=i-1; j++)
{
L=L*((xp-X[j])/(X[i]-X[j]));
}
for(j=i+1; j<=N;j++)
{
L=L*((xp-X[j])/(X[i]-X[j]));
}
P=P+(Y[i]*L);
}
}
void Mostrar_Resultados()
{
cout<<"Polinomio de grado :"<<N<<" \n";
cout<<"Valor de interpolacion:"<<xp<<" \n ";

cout<<"P("<<xp<<")= "<<P;
}
int main() {
IngresarDatos();
Lagrange();
Mostrar_Resultados();
return 0;
}