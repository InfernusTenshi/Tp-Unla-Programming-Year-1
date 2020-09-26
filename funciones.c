#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
 

struct DatosJugador RegistrarJugador()
{
	
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute (hConsole,8);	
	//int  dniJugador = 0;
	int cantidadCartones = 0;
	struct DatosJugador Jug;
	printf("\n*****************************************************");
	printf("\n************ Ingrese su nombre **********************");
	printf("\n*****************************************************");
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
	fflush(stdin);
	gets(Jug.Nombre);
	system("cls");
	fflush(stdin);
	printf("\n*****************************************************");
	printf("\n************ Ingrese su apellido ********************");
	printf("\n*****************************************************");
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
	fflush(stdin);
	gets(Jug.Apellido);
	system("cls");
	fflush(stdin);
	printf("\n*****************************************************");
	printf("\n************ Ingrese su DNI *************************");
	printf("\n*****************************************************");
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
	scanf("%d",&Jug.Dni);
	
	while(Jug.Dni < 10000000 || Jug.Dni > 99999999)
	{
		 			system("cls");
		 			printf("%d",Jug.Dni);
	                printf("\n*****************************************************");
	                printf("\n********* DNI invalido intente nuevamente ***********");
	                printf("\n*****************************************************");
	                printf("\n");
	                printf("\n");
					SetConsoleTextAttribute (hConsole,4);
					printf("------->>> ");
					SetConsoleTextAttribute (hConsole,7);
	                scanf("%d",&Jug.Dni);
	}
	system("cls");
	return Jug;
}

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
void cargarMatrizManual(int m[][RENGLONES][COLUMNAS],int pos){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

     int numeroNuevo = 0;
     int resultadoBusqueda = 0 ;
	
	 for ( int i = 0; i<RENGLONES; i++){
			for ( int j = 0; j < COLUMNAS;j++)
				{
				
					do{
						printf("Ingrese un numero...");
						printf("\n");
						SetConsoleTextAttribute (hConsole,4);
						printf("------->>> ");
						SetConsoleTextAttribute (hConsole,7);
			     		scanf("%d",&numeroNuevo); 
				        resultadoBusqueda = buscarEnMatriz(m,pos,numeroNuevo); //nos da la posicion ---> -1
				        if(resultadoBusqueda == 0)
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

int CantidadCartones()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int cantidad = 0;
    do{
     printf("\n*****************************************************");
     printf("\n******** Por favor elija el numero de cartones: *****");
     printf("\n**************** 1- Carton **************************");
     printf("\n**************** 2- Cartones ************************");
     printf("\n**************** 3- Cartones ************************");
     printf("\n*****************************************************");
     printf("\n");
	 printf("\n");
	 SetConsoleTextAttribute (hConsole,4);
	 printf("------->>> ");
	 SetConsoleTextAttribute (hConsole,7);
     scanf("%d",&cantidad);        
     }      
     while(cantidad > 3 || cantidad < 1);
     return cantidad;
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

void Escribir(struct DatosJugador Jug)
{
	int Auxi =0;
	FILE *archivo = fopen("Puntajes.ear","a");
	if(archivo == NULL)
	{
		perror("error abriendo el archivo");
	}
	else
	{
		fprintf(archivo,"/ %d ",Jug.Dni);
		
		Auxi = (8 - strlen(Jug.Nombre));
		fprintf(archivo,"%s",Jug.Nombre);
		if(Auxi != 0)
		{
			for(int K=0;K<Auxi;K++)
			fprintf(archivo," ");
		}


		
		Auxi = (8 - strlen(Jug.Apellido));
		fprintf(archivo," %s ",Jug.Apellido);
		if(Auxi != 0)
		{
			for(int K=0;K<Auxi;K++)
			fprintf(archivo," ");
		}
		
		fprintf(archivo," %3d  /",Jug.Puntaje);
			fputc('\n',archivo);
		}
	fclose(archivo);	
}
/*void Escribir(int punt,int dni,char nomb[10],char ape[10])
{
	FILE *archivo = fopen("Puntajes.ear","a");
	if(archivo == NULL)
	{
		perror("error abriendo el archivo");
		
	}
	else
	{
		fprintf(archivo,"%d ",dni);
		fprintf(archivo,"%s ",nomb);
		fprintf(archivo,"%s ",ape);
		fprintf(archivo,"%d ",punt);
			fputc('\n',archivo);
		}
	fclose(archivo);
}
*/
void Leer()
{
	FILE *archivo = fopen("Puntajes.ear","r");
	if(archivo == NULL)
	{
		perror("error abriendo el archivo");
	}
	int c;
	lineas(201,205,187,34,1); // PRINCIPIO / LINEA / FIN / TAMAÑO / ESPACIO
	printf("%c         <Mejores Puntajes>       %c\n",186,186);
	lineas(200,205,188,34,1);
	lineas(201,205,187,34,1);
	printf("%c   DNI     Nombre  Apellido Score %c\n",186,186);
	//printf("%c 00000000 00000000 00000000  000  %c\n",186,186);
	lineas(204,205,185,34,1);

	if (archivo) {
	    while ((c = getc(archivo)) != EOF)
	    {
	        
	        if(c=='/')
	        {
	        	printf("%c",186);
			}else
			{
				putchar(c);
			}
		}
	    fclose(archivo);
	}
	lineas(200,205,188,34,1);
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

int Sacar(int Bolita[91]){
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

void vaciar(int Bola[91]){
    for(int i=0;i<91;i++)
    {
        Bola[i] = 0;
    }
}

void vaciarCartonPiola(int carton[][RENGLONES][COLUMNAS],int cantidad){//se vacia el carton porque estaba 
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

int ComprobarLinea(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num)
{
	//Num 0 = Jugador / Num 1 = Maquina	
	int cont =0;
	int acu =0;
	int aculumnas = 0;
	
	for (int M=0;M<cantidad;M++)
	{
		for(int F=0;F<RENGLONES;F++)
		{
			for(int C=0;C<COLUMNAS;C++)
			{
					if(Bolitas[carton[M][F][C]] == 1)
					{
						cont=cont+1;
						if(Comp[Num][M][F][C]=='C')
						{
							Comp[Num][M][F][C]='X';
						}
						else
						{
							Comp[Num][M][F][C]='L';
						}
					}
			}
			if (cont == COLUMNAS)
			{
				aculumnas=aculumnas+1;
				for(int X=0;X<COLUMNAS;X++)
				{
				if(Comp[Num][M][F][X]=='X')
				{
					Comp[Num][M][F][X]='L';
				}
				}
			}
			else
			{
				for(int X=0;X<COLUMNAS;X++)
				{
					if(Comp[Num][M][F][X]=='X')
					{
						Comp[Num][M][F][X]='C';
					}
					else
					{
						Comp[Num][M][F][X] = 'O';
					}
						
					
				}
			}
			cont =0;
		}
    }
    return aculumnas;
}

int ComprobarColumna(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num)
{
	//Num 0 = Jugador / Num 1 = Maquina	
	int cont =0;
	int acu =0;
	int aculumnas = 0;
	
	for (int M=0;M<cantidad;M++)
	{
		
		for(int C=0;C<COLUMNAS;C++)
		{
			for( int F=0;F<RENGLONES;F++)
			{
					if(Bolitas[carton[M][F][C]] == 1)
					{
						cont=cont+1;
						if(Comp[Num][M][F][C]!='L')
						{
							Comp[Num][M][F][C]='C';	
						}
					}
			}
			if (cont == RENGLONES)
			{
				aculumnas=aculumnas+1;
			}
			else
			{
				for(int X=0;X<COLUMNAS;X++)
				{
					if(Comp[Num][M][X][C]!='L')
					{
						Comp[Num][M][X][C] = 'O';
					}
				}
			}
			cont =0;
		}
    }
    return aculumnas;
}
int ComprobarBingo(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int Num){
int cont = 0;
int Bingo = 0;
for (int M=0;M<cantidad;M++)
    {
    	for(int C=0;C<COLUMNAS;C++)
        {
            for( int F=0;F<RENGLONES;F++)
            {
                if(Bolitas[carton[M][F][C]] == 1)
                {
                    cont=cont+1;
                }
            }
        }
        if(cont == 15)
        {
            Bingo = 10;
            break;
        }
        cont =0;
    }
	return Bingo;
}

