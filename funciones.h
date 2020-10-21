#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define RENGLONES 3
#define COLUMNAS 5
struct DatosJugador  // ------------> MIO
{
	char Nombre[8];
	char Apellido[8];
	int Dni;
	int Puntaje;
};

int aleatorioEntre(int mini, int maxi);// Dejar en Funciones
int buscarEnMatriz(int m[][RENGLONES][COLUMNAS],int pos, int buscar);// Dejar en Funciones
void cargarMatrizAleatoria(int m[][RENGLONES][COLUMNAS],int pos);// Dejar en Funciones
void cargarMatrizManual(int m[][RENGLONES][COLUMNAS],int pos);// mover a juego
void MostrarCarton(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int NumActual,char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a juego

//int RegistrarJugador(char nombreJugador[8],char apellidoJugador[8]);
struct DatosJugador RegistrarJugador(); // ------------> MIO

int CantidadCartones();// mover a juego
void cartonesMaquina(int cantidad);// mover a juego
void Escribir (struct DatosJugador Jug); // ------------> MIO
void Leer(); // ------------> MIO
void vaciar(int Bola[91]);// Dejar en Funciones
int Sacar(int Bolita[91]);// mover a juego
int ComprobarLinea(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a MetaJuego
int ComprobarColumna(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a MetaJuego
int ComprobarBingo(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int Num);// mover a MetaJuego
void vaciarCartonPiola(int carton[][RENGLONES][COLUMNAS],int cantidad);// Dejar en Funciones
void lineas(char P,char L,char F,char T,int X);// Dejar en Funciones
#endif // FUNCIONES_H_INCLUDED
