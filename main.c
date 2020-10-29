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
#include "Menu.h"
#define TESTING 1 // 1 (MODO DESAROLLADOR HABILITADO) - ? (MODO DESAROLLADOR DESABILITADO)
#define MAXJUGADORES 30

int main()
{
	/*Jugador MejoresJugadores[MAXJUGADORES];
	CargarArchivoLimpio(MejoresJugadores,MAXJUGADORES);
	CargarArchivo(MejoresJugadores);*/
	int TEST = 0;
	/*float Multip=0;
	int CantBolitas =0;
	int cantidadCartones;	
	int Bolillas[91];
	int NumActual =0;
	
	int PuntajeActual = 0;
	int PuntajeMaquina = 0;
	bool PLinea = false;
	bool PColumna = false;
	bool PBingo = false;
	vaciar(Bolillas);*/
	
    srand(time(NULL));   
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole,7);

	
	if(TESTING == 1)
    {
    printf("\n*****************************************************");
    printf("\n*--------- PROGRAMA EN FASE DE TESTEO --------------*");
    printf("\n*---------------------------------------------------*");
    printf("\n*---------------------------------------------------*");
    printf("\n*--------- ELIJA ENTRE PRUEBA ");
    SetConsoleTextAttribute (hConsole,4);
	printf("PROGRAMADOR");
	SetConsoleTextAttribute (hConsole,7);
	printf(" (1)-------*");
    printf("\n*--------- ELIJA ENTRE PRUEBA ");
    SetConsoleTextAttribute (hConsole,6);
	printf("USUARIO FINAL");
	SetConsoleTextAttribute (hConsole,7);
	printf(" (2)-----*");
	printf("\n*****************************************************");
    SetConsoleTextAttribute (hConsole,4);
    printf("\n\n\n");
	printf("\n*****************************************************");
	printf("\n****************** ADVERTENCIA **********************");
	printf("\n*****************************************************");
    printf("\n*SI USTED VE ESTE MENSAJE NO PRESIONE NADA FUERA DE *");
    printf("\n*---------- LOS PARAMETROS ESTABLECIDOS ------------*");
    printf("\n*---------- RUPTURA DEL PROGRAMA SEGURA ------------*");
    printf("\n*****************************************************");
    SetConsoleTextAttribute (hConsole,7);
    printf("\n\n\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
    scanf("%d",&TEST);
    system("cls");
	}
	if(TESTING != 1)
	{
		TEST = 2;
	}
	
	
    MenuPiola();// 			--------------------CAMBIOSSSS------------------------
/*	printf("\n*****************************************************");
    printf("\n************** Bienvenido al Bingo ******************");
    printf("\n-----------------------------------------------------");*/
	
	
    
    return 0;
}
