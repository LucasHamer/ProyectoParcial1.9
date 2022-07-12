#include <stdio.h>
#include <stdlib.h>

int validar(int ,int ,int );
void ordenar(int [],int [],int );
void minimo(int [][15],int ,int );
void mayor(int [],int);

int main()
{
    int espectadores=0,i,x,vsala[15]={0},vfuncion[6]={0},nsala,nfuncion,cantespec,mfuncionsala[6][15]={{0}},vnsala[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},vprom[15]={0};

    printf("Ingrese numero de sala: ");
    nsala=validar(0,15,1);
    while(nsala!=0)
    {
        printf("Ingrese numero de funcion: ");
        nfuncion=validar(1,6,2);
        printf("Ingrese cantidad de espectadores: ");
        scanf("%d",&cantespec);
        espectadores++;
        printf("\n");

        vprom[nsala-1]+=cantespec/espectadores;

        mfuncionsala[nfuncion-1][nsala-1]+=cantespec;
        vsala[nsala-1]+=cantespec;
        vfuncion[nfuncion-1]+=cantespec;

        printf("Ingrese numero de sala: ");
        nsala=validar(0,15,1);
    }
    printf("Espectadores totales por funcion: \n");
    for(x=0;x<6;x++)
        printf("Funcion %d: %d\n",x+1,vfuncion[x]);//punto 4

    for(i=0;i<15;i++)
    {
        if(vsala[i]==0)
            printf("La sala %d no tuvo espectadores\n",i+1);//punto 3
    }

    minimo(mfuncionsala,6,15);//punto 1

    ordenar(vsala,vnsala,15);
    printf("La sala a la que asistio la mayor cantidad de espectadores es: %d\n",vnsala[0]);//punto 2

    ordenar(vprom,vnsala,15);
    printf("Numero de sala              Promedio de espectadores: \n");
    for(x=0;x<15;x++)
        printf("%d                      %d\n",vsala[x],vprom[x]);//punto 5

    return 0;
}
int validar(int min,int max,int cual)
{
    int dato;

    do{
        scanf("%d",&dato);
    }while(dato<min||dato>max);

    return dato;
};
void ordenar(int v[],int v2[],int cant)
{
    int aux,aux2,x,sen=0;

    while(sen==0)
    {
        sen=1;
        for(x=0;x<cant-1;x++)
        {
            if(v[x]<v[x+1])
            {
            aux=v[x];
            v[x]=v[x+1];
            v[x+1]=aux;
            aux2=v2[x];
            v2[x]=v2[x+1];
            v2[x+1]=aux2;
            sen=0;
            }
        }
        cant=cant-1;
    }
};
void minimo(int m[][15],int f,int c)
{
    int min,x,z,a,b;

    min=m[0][0];
    for(x=0;x<f;x++)
    {
        for(z=0;z<c;z++)
        {
            if(min!=0)
            {
                if(m[x][z]<min)
                {
                    min=m[x][z];
                    a=x+1;
                    b=z+1;
                }
            }
            else
                min=m[x][z];
        }
    }
    printf("La sala %d,funcion %d, tuvieron la menor cantidad de espectadores: %d\n",b,a,min);
};
