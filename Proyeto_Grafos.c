#include<stdio.h>
#include<stdlib.h>

void Graficas_No_Dirigidas()
{
    system("cls");
    int A[10][20],X[10][10],M[10][10],i,j,k,n,l,p,q,a,b,cont=0,ban=0,grado=0,gsg=0,gcd=0,gr=0;
    printf("\n Ingrese cuantos nodos tiene el grafo: ");
    scanf("%d",&n);
    printf("\n Ingrese cuantas lineas tiene el grafo: ");
    scanf("%d",&l);
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            A[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            X[i][j]=0;
            M[i][j]=0;
        }
    }
    for(j=0;j<l;j++)
    {
        printf(" \n\tQue elementos relacionan la linea %d (? ?): ",j+1);
        scanf("%d %d",&a,&b);
        A[a-1][j]=1;       /** Se llena la matriz de incidencia en la lectura de datos **/
        A[b-1][j]=1;
        X[a-1][b-1]=1;     /** Se llena la matriz de adyacencia en la lectura de datos **/
        X[b-1][a-1]=1;
    }
    printf("\n La matriz de incidencia es:\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n La matriz de adyacencia es:\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d ",X[i][j]);
            M[i][j]=X[i][j];
        }
        printf("\n");
    }
    printf("\n La matriz de accesibilidad es:\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(M[i][j]==1)
            {
                printf(" %c ",43);
            }
            else
            {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
    printf("\n");

    /** Ciclo para encontrar los bucles en la matriz de incidencia **/

     for(i=0;i<l;i++)
    {
        for(j=0;j<n;j++)
        {
           if(A[j][i]!=0)
           {
               cont++;  /** Contador  de bucles **/
           }
        }
        if(cont==1)
        {
            printf("\n La linea %d es un bucle\n",i+1);
            gsg=1;  /** Bandera para determinar si la gráfica es simple o general**/
        }
        cont=0;  /** Reinicio del contador para buscar un bucle en la siguiente columna **/
    }

    /** Ciclo para encontrar los vertices aislados en la matriz de incidencia **/

    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
           if (A[i][j]!=0)
           {
               ban=1; /** Bandera de vertices aislados **/
               grado++;
           }
        }
        if(ban==0)
        {
            printf("\n El vertice %d es aislado\n",i+1);
            gcd=1; /** Bandera para determinar si está conectada **/
        }
        else
        {
            if(grado==1)
            {
                printf("\n El vertice %d es colgante\n",i+1); /**  Impresion de vertices colgantes **/
                grado=0;
            }
            else
            {
                printf("\n El vertice %d es de grado %d\n",i+1,grado); /**  Impresion de los grados **/
                grado=0;
            }
        }
        ban=0;   /** Se desactiva la bandera para volver a buscar en caso de haber encontrado una coincidencia**/

    }


    /** Ciclo para encontrar las líneas paralelas **/

    cont=0;
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            for(k=0;k<n;k++)
            {
                if (A[k][i]==A[k][j])
                {
                    cont++;
                }
            }
            if(cont==n)
            {
                printf("\n La linea %d es paralela a la linea %d\n",i+1,j+1);
            }
            cont=0; /** Se reinicia el contador cuando se cambia de columna**/
        }
    }

    /** Ciclo para encontrar las líneas en serie **/

    cont=0;
    grado=0;
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            for(k=0;k<n;k++)
            {
                if (A[k][i]==A[k][j] && A[k][i]==1)
                {
                    cont++;
                    a=k;
                }
            }
            if(cont==1)
            {
                for(p=0;p<l;p++)
                {
                    if(A[a][p]!=0)
                    {
                        grado++;
                    }
                }
                if(grado==2)
                {
                    printf("\n La linea %d y la linea %d estan en serie \n",i+1,j+1);
                }
            }
            cont=0; /** Se reinicia el contador cuando se cambia de columna**/
            grado=0;
        }
    }

    /** Clasificación de gráficas **/

    if(gsg==0)
    {
        printf("\n Es una grafica simple\n");
    }
    else
    {
        printf("\n Es una grafica general\n");
    }

    if(gcd==0)
    {
        printf("\n La grafica esta conectada\n");
    }
    else
    {
        printf("\n La grafica esta desconectada\n");
    }
    grado=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            grado+=A[i][j];
        }
        if(i==0)
        {
            a=grado;
            grado=0;
        }
        else
        {
            if(grado!=a)
            {
                gr=1;
                break;
            }
            else
            {
                a=grado;
                grado=0;
            }
        }

    }
    if(gr==0)
    {
        printf("\n La grafica es regular");
    }

    printf("\n");
}

void Digraficas()
{
    system("cls");
    char M[10][10];
    int A[10][20],X[10][10],i,j,k,n,l,a,b,cont=0,ban=0,grado_ext=0,grado_int=0,gsg=0,gcd=0,gb=0;
    printf("\n Ingrese cuantos nodos tiene el grafo: ");
    scanf("%d",&n);
    printf("\n Ingrese cuantas lineas tiene el grafo: ");
    scanf("%d",&l);
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            A[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            X[i][j]=0;
            M[i][j]=0;
        }
    }
    for(j=0;j<l;j++)
    {
        printf(" \n\tQue elementos relacionan la linea %d (? ?): ",j+1);
        scanf("%d %d",&a,&b);
        A[a-1][j]=1;       /** Se llena la matriz de incidencia en la lectura de datos **/
        A[b-1][j]=-1;
        X[a-1][b-1]=1;     /** Se llena la matriz de adyacencia en la lectura de datos **/
        if(a==b)
        {
            A[a-1][j]=2; /** Bucles en la matriz de incidencia **/
        }
    }
    printf("\n La matriz de incidencia es:\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            if(A[i][j]==2)
            {
                printf(" %c1 ",241);
            }
            else
            {
                if(A[i][j]==0 || A[i][j]==1)
                {
                    printf("  %d ",A[i][j]);
                }
                else
                {
                    printf(" %d ",A[i][j]);
                }
            }
        }
        printf("\n");
    }
    printf("\n La matriz de adyacencia es:\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d ",X[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /** Ciclo para encontrar los bucles en la matriz de incidencia **/

     for(i=0;i<l;i++)
    {
        for(j=0;j<n;j++)
        {
           if(A[j][i]!=0)
           {
               cont++;  /** Contador  de bucles **/
           }
        }
        if(cont==1)
        {
            printf("\n La linea %d es un bucle\n",i+1);
            gsg=1;
        }
        cont=0;  /** Reinicio del contador para buscar un bucle en la siguiente columna **/
    }


    /** Ciclo para encontrar los vertices aislados en la matriz de incidencia **/

    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
           if (A[i][j]!=0)
           {
               ban=1; /** Bandera de vertices aislados **/
               if(A[i][j]==1)
               {
                   grado_ext++;
               }
               else
               {
                   grado_int++;
               }
           }
        }
        if(ban==0)
        {
            printf("\n El vertice %d es aislado\n",i+1);
            gcd=1;  /** Bandera para determinar si está conectada **/
        }
        else
        {
            printf("\n El vertice %d tiene grado externo %d y grado interno %d\n",i+1,grado_ext,grado_int);
            grado_ext=0;
            grado_int=0;
        }
        ban=0;   /** Se desactiva la bandera para volver a buscar en caso de haber encontrado una coincidencia**/

    }


    /** Ciclo para encontrar las líneas paralelas **/

    cont=0;
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            for(k=0;k<n;k++)
            {
                if (A[k][i]==A[k][j])
                {
                    cont++;
                }
            }
            if(cont==n)
            {
                printf("\n La linea %d es paralela a la linea %d\n",i+1,j+1);
            }
            cont=0; /** Se reinicia el contador cuando se cambia de columna**/
        }
    }

    /** Clasificación de gráficas **/

    if(gsg==0)
    {
        printf("\n Es una grafica simple\n");
    }
    else
    {
        printf("\n Es una grafica general\n");
    }

    if(gcd==0)
    {
        printf("\n La grafica esta conectada\n");
    }
    else
    {
        printf("\n La grafica esta desconectada\n");
    }

    grado_ext=0;
    grado_int=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<l;j++)
        {
            if(A[i][j]==1)
            {
                grado_ext++;
            }
            if(A[i][j]==-1)
            {
                grado_int++;
            }
        }
        if(grado_ext!=grado_int)
        {
            gb=1;
            break;
        }
        else
        {
            if(i==0)
            {
                a=grado_ext;
                b=grado_int;
                grado_ext=0;
                grado_int=0;
            }
            else
            {
                if(a!=grado_ext || b!=grado_int)
                {
                    gb=1;
                    break;
                }
                else
                {
                    a=grado_ext;
                    b=grado_int;
                    grado_ext=0;
                    grado_int=0;
                }
            }
        }

    }
    if(gb==0)
    {
        printf("\n La grafica es balanceada");
    }

    /** Arboles **/

    if(l==n-1)
    {
        if(gsg==0)
        {
            printf("\n La grafica es un arbol\n");
        }
    }

    printf("\n");
}

int main()
{
    int n,resp;
    while(resp)
    {
        system ("cls");
        printf("\n Que tipo de Grafica es 1.- No Dirigida 2.- Dirigida: ");
        scanf("%d",&n);
        if(n==1)
        {
            Graficas_No_Dirigidas();
        }
        else
        {
            Digraficas();
        }
        printf("\n Presione 0 para salir, 1 para regresar al Menu: ");
        scanf("%d",&resp);
    }
    return 0;
}
