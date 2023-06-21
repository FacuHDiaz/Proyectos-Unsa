void Biseccion()
{
    bool fin = false;
    k=1;

    while(k<=imax and fin == false)
    {
        xm = (xb + xa)/2;
        
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
            else
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
