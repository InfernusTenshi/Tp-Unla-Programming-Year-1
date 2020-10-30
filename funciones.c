#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "Juego.h"
#include "MetaJuego.h"
#include "Datos.h"


int aleatorioEntre(int mini, int maxi){

        //mini = 8, maxi = 20

        int resultado = 0;


        resultado  =  mini + rand()%(maxi - mini +1);


        return resultado;

}
int buscarEnMatriz(int m[][RENGLONES][COLUMNAS],int pos,int buscar)
{
	
	int retorno = -1;

        for ( int i = 0; i<RENGLONES; i++){
			for ( int j = 0; j < COLUMNAS;j++)
			{
				 if ( m[pos][i][j]==buscar){ //Lo encontre
	
	                retorno = 0;
	
	            }	
			}
           
        }

       //Bien menos
       // if ( pos == -1){ printf("No lo encontre");}


    return retorno;
	
}
void cargarMatrizAleatoria(int m[][RENGLONES][COLUMNAS],int pos){

	
     int numeroNuevo = 0;
     int resultadoBusqueda = 0 ;
	
	 for ( int i = 0; i<RENGLONES; i++){
			for ( int j = 0; j < COLUMNAS;j++)
				{
				
					do{
			        numeroNuevo = aleatorioEntre(0, 90);
			        resultadoBusqueda = buscarEnMatriz(m,pos,numeroNuevo); //nos da la posicion ---> -1
			        }while(resultadoBusqueda==0);
			
			        m[pos][i][j]= numeroNuevo;
	
	            }	
			}
           
    }


void lineas(char P,char L,char F,char T,int X)
{
if (X==1)
printf("%c",P);
else
printf("\n%c",P);
for(int I=1;I<=T;I++)
printf("%c",L);
printf("%c\n",F);
}

void Espacios(int X)
{
	for(int I=0;I<X;I++)
	{
		printf(" ");
	}
}

void vaciar(int Bola[91]){
    for(int i=0;i<91;i++)
    {
        Bola[i] = 0;
    }
}

void vaciarCarton(int carton[][RENGLONES][COLUMNAS],int cantidad){//se vacia el carton porque estaba 
//arrastrando mierda en la cargar de carton manual :)
	
	for (int M=0;M<cantidad;M++)
	{
		for( int F=0;F<RENGLONES;F++)
		{
			for(int C=0;C<COLUMNAS;C++)
			{
				carton[M][F][C] = 0;
			}
    	}
	}
}

