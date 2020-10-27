#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "Juego.h"
#include "MetaJuego.h"
#include "Datos.h"

void cargarMatrizManual(int m[][RENGLONES][COLUMNAS],int pos){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char num[3]= " ";
	 bool rep = true;
     int numeroNuevo = 0;
     int resultadoBusqueda = 0 ;
	
	 for ( int i = 0; i<RENGLONES; i++){
			for ( int j = 0; j < COLUMNAS;j++)
				{
				
					do{
						
						rep = true;
						printf("Ingrese un numero...");
						printf("\n");
						SetConsoleTextAttribute (hConsole,4);
						printf("------->>> ");
						SetConsoleTextAttribute (hConsole,7);
			     		fflush(stdin);
			     		gets(num);
			     		if(isdigit(atoi(num))== 0){
						 numeroNuevo = atoi(num);
						 rep = false;
						 }
				        resultadoBusqueda = buscarEnMatriz(m,pos,numeroNuevo); //nos da la posicion ---> -1
				        if(rep == true)
						{
							printf("Error caracter no valido");
						}else if(resultadoBusqueda == 0)
				        {
				        	printf("Error numero repetido\n");
						}
						if(numeroNuevo>90)
						{
							printf("El numero no debe ser mayor a 90\n");
						}
						
			        }while(resultadoBusqueda==0 || numeroNuevo >90);
			
			        m[pos][i][j] = numeroNuevo;
	
	            }	
			}
           
    }
    
void MostrarCarton(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int NumActual,char Comp[2][3][RENGLONES][COLUMNAS],int Num)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole,8);	
	for (int M=0;M<cantidad;M++)
	{
			for( int F=0;F<RENGLONES;F++)
			{
				for(int C=0;C<COLUMNAS;C++)
				{
					if(Comp[Num][M][F][C] == 'L')
					{
						SetConsoleTextAttribute (hConsole,4);
					}else if(Comp[Num][M][F][C] == 'C')
					{
						SetConsoleTextAttribute (hConsole,9);
					}
					else
					{
						if(carton[M][F][C] == NumActual)
						{
							SetConsoleTextAttribute (hConsole,6);
						}
						else
						{
							if(Bolitas[carton[M][F][C]] == 0)
							{
								SetConsoleTextAttribute (hConsole,8);
							}
							if(Bolitas[carton[M][F][C]] == 1)
							{
								SetConsoleTextAttribute (hConsole,10);
							}
							if(Bolitas[carton[M][F][C]] == 3)
							{
								SetConsoleTextAttribute (hConsole,4);
							}
						}
					}

					printf(" %2d ",carton[M][F][C]);
					SetConsoleTextAttribute (hConsole,7);
					
				}
				printf(" \n");
			}
			printf(" \n");
				
			
    }
}
    
int CantidadCartones()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int cantidad = 0;
    do{
	    lineas(201,205,187,36,1);
		printf("%c   Por Favor Elija la cantidad de   %c\n",186,186);
		printf("%c   Cartones que desee para jugar    %c",186,186);
		lineas(200,205,188,36,0);
		lineas(201,205,187,36,1);//inicio
		printf("%c (1) Carton                         %c\n",186,186);
		printf("%c (2) Cartones                       %c\n",186,186);
		printf("%c (3) Cartones                       %c\n",186,186);
		lineas(200,205,188,36,1);
	     printf("\n\n");
		 SetConsoleTextAttribute (hConsole,4);
		 printf("------->>> ");
		 SetConsoleTextAttribute (hConsole,7);
	     scanf("%d",&cantidad);        
     }      
     while(cantidad > 3 || cantidad < 1);
     return cantidad;
}

int Sacar(int Bolita[91])
{
    int numero = 0;
    do{
        numero = rand()% 91;  // 0 - 90
       // numero = rand()% 90 +1;  1 - 90
       //  numero = rand()% 90;  0 - 89

        }while(Bolita[numero]==1);//si la bolita en la posicion numero es 1 significa que salio
        // sino salio se le asigna un 1 por primera vez
        Bolita[numero] = 1;
    return numero;
}
