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
struct DatosJugador{
	char Nombre[12];
	char Apellido[12];
	int Dni;
	int Puntaje;
};
void Destructor(Jugador j){
	free(j);
}
Jugador RegistrarJugador()
{
	Jugador J = malloc(sizeof(struct DatosJugador));
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char auxN[12] = " ";
	char auxA[12] = " ";
	int Dni;

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

	scanf("%d",&Dni);
	


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
    (J->Dni) = Dni;
    strcpy(J->Nombre, auxN);
    strcpy(J->Apellido, auxA);
   
	return J;
}


void Escribir(Jugador Jug,float Punt)
{
	int NPunt = Punt;
	int Auxi =0;
	FILE *archivo = fopen("Puntajes.ear","a");
	if(archivo == NULL)
	{
		lineas(201,205,187,47,1);
		printf("%c   Archivo De Puntajes Roto o no Encontrado    %c",186,186);
		lineas(200,205,188,47,0);
	}
	else
	{
		//fputc('\n',archivo);
		fprintf(archivo,"\n%d+%s+%s+%d",Jug->Dni,Jug->Nombre,Jug->Apellido,NPunt);
		lineas(201,205,187,47,1);
		printf("%c     Puntaje Nuevo Añadido De Forma Exitosa    %c",186,186);
		lineas(200,205,188,47,0);
	}

	fclose(archivo);	
}






void CargarArchivo(Jugador Jug[])
{
    int JugActual = 0;

    FILE * puntero;

    puntero = fopen("Puntajes.ear", "r");
    while (!feof(puntero)){

        char aux[40] = " ";
        fgets(aux, 40 ,puntero);

        Jug[JugActual] = Leer(aux);

    JugActual=JugActual+1;
    }
    fclose(puntero);
}

void CargarArchivoLimpio(Jugador Jug[],int C)
{
	for(int I=0;I<C;I++)
	{
		Jug[I]=VaciarJugador();
	}
}


Jugador VaciarJugador()
{
	Jugador J = malloc(sizeof(struct DatosJugador));
	char Aux[12]=" ";
	strcpy(J->Nombre,Aux);
	strcpy(J->Apellido,Aux);
	J->Dni = 0;
	J->Puntaje = -1;
	return J;
}

Jugador Leer(char aux[40])
{
    Jugador J = malloc(sizeof(struct DatosJugador)); // estructura local
    int Estado = 0;
    char auxN[40] = " ";
    char auxA[40] = " ";
    char auxD[40] = " ";
    char auxP[40] = " ";
    int IFija = 0;
    bool No = false;
    bool Ap = false;
    bool Pu = false;


    for ( int i = 0; i<strlen (aux); i++ ){

        if(aux[i] == '+')
        {
            Estado++;
        }

        if(Estado == 0 && aux[i] != '+') // verificador del DNI
        {
            auxD[i] = aux[i];
        }
        if(Estado == 1 && aux[i] != '+')
        {
            if( No == false ) // verificador del Nombre
            {
                IFija = i;
                No = true;
            }
            auxN[(i - IFija)] = aux[i];
        }
        if(Estado == 2 && aux[i] != '+') //verificador del Apellido
        {
            if( Ap == false )
            {
                IFija = i;
                Ap = true;
            }

            auxA[(i - IFija)] = aux[i];
        }
        if(Estado == 3 && aux[i] != '+') //verificador del Puntaje
        {
            if( Pu == false )
            {
                IFija = i;
                Pu = true;
            }

            auxP[(i - IFija)] = aux[i];
        }

    }


    strcpy(J->Nombre,auxN);
    strcpy(J->Apellido,auxA);
    J->Dni = atoi(auxD);
    J->Puntaje = atoi(auxP);


return J;
}


void MostrarTablaJugadores(Jugador Jug[],int Max)
{
	Jugador J = malloc(sizeof(struct DatosJugador));
	lineas(201,205,187,44,1);
	printf("%c              <Mejores Puntajes>            %c\n",186,186);
	lineas(200,205,188,44,1);
	lineas(201,205,187,44,1);
	printf("%c   DNI     Nombre        Apellido     Score %c\n",186,186);
	lineas(204,205,185,44,1);
	//printf("%c",186);
	for(int I=0;I<Max;I++)
	{
		J = Jug[I];
		if(J->Puntaje != -1)
		{
				printf("%c",186);
			Espacios(1);
				printf("%d",J->Dni);
			Espacios(2);
				printf("%s",J->Nombre);
			Espacios((12 -strlen(J->Nombre)));		
			Espacios(2);
				printf("%s",J->Apellido);
			Espacios((12 - strlen(J->Apellido)));
			Espacios(2);
			printf("%d",J->Puntaje);
			if(J->Puntaje < 10)
			{
			Espacios(4);	
			}else if(J->Puntaje < 100)
			{
			Espacios(3);	
			}else
			{
			Espacios(2);	
			}
				printf("%c\n",186);
		}
	}
	
	
	
	lineas(200,205,188,44,1);// Fin
}

// -------- GETS
char* GetNombre(Jugador J)
{
return J->Nombre;
}

char* GetApellido(Jugador J)
{
return J->Apellido;
}

int GetDni(Jugador J)
{
return J->Dni;
}

int GetPuntaje(Jugador J)
{
return (J->Puntaje);
}


