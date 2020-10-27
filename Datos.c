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
#include "datos.h"	
struct DatosJugador{
	char Nombre[8];
	char Apellido[8];
	int Dni;
	int Puntaje;
};

Jugador RegistrarJugador()
{
	Jugador J = malloc(sizeof(struct DatosJugador));
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char auxN[8] = " ";
	char auxA[8] = " ";
	long Dni=0;
	
	//SetConsoleTextAttribute (hConsole,8);	
	//int  dniJugador = 0;
	int cantidadCartones = 0;
	struct DatosJugador Jug;
	lineas(201,205,187,36,1);
	printf("%c         Ingrese Su Nombre          %c",186,186);
	lineas(200,205,188,36,0);
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
	fflush(stdin);
	gets(auxN);
	system("cls");
	lineas(201,205,187,36,1);
	printf("%c         Ingrese Su Apellido        %c",186,186);
	lineas(200,205,188,36,0);
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
	fflush(stdin);
	gets(auxA);
	system("cls");
	fflush(stdin);
	lineas(201,205,187,36,1);
	printf("%c         Ingrese Su DNI             %c",186,186);
	lineas(200,205,188,36,0);
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
	scanf("%d",Dni);
	
	while(Dni < 10000000 || Dni > 99999999)
	{
		 			system("cls");
					lineas(201,205,187,36,1);
					printf("%c  DNI Invalido Ingreselo Nuevamente %c",186,186);
					lineas(200,205,188,36,0);
	                printf("\n");
	                printf("\n");
					SetConsoleTextAttribute (hConsole,4);
					printf("------->>> ");
					SetConsoleTextAttribute (hConsole,7);
	                scanf("%d",&Dni);
	}
	system("cls");
//	(J->Dni) = Dni;
   strcpy(J->Nombre, auxN);
   strcpy(J->Apellido, auxN);
   
	return J;
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

// -------- GETS
int GetNombre(Jugador J){return (J->Nombre);}
int GetApellido(Jugador J){return (J->Apellido);}
int GetDni(Jugador J){return (J->Dni);}
int GetPuntaje(Jugador J){return (J->Puntaje);}


