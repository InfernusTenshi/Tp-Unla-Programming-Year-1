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
    MenuPiola();
    return 0;
}
