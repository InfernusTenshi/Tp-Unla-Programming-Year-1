#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define RENGLONES 3
#define COLUMNAS 5


int aleatorioEntre(int mini, int maxi);
int buscarEnMatriz(int m[][RENGLONES][COLUMNAS],int pos, int buscar);
void cargarMatrizAleatoria(int m[][RENGLONES][COLUMNAS],int pos);
void cargarMatrizManual(int m[][RENGLONES][COLUMNAS],int pos);
void MostrarCarton(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int NumActual,char Comp[2][3][RENGLONES][COLUMNAS],int Num);
int RegistrarJugador(char nombreJugador[8],char apellidoJugador[8]);
int CantidadCartones();
void cartonesMaquina(int cantidad);
void Escribir(int punt,int dni,char nomb[10],char ape[10]);
void Leer();
void vaciar(int Bola[91]);
int Sacar(int Bolita[91]);
int ComprobarLinea(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);
int ComprobarColumna(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);
int ComprobarBingo(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int Num);
void vaciarCartonPiola(int carton[][RENGLONES][COLUMNAS],int cantidad);

#endif // FUNCIONES_H_INCLUDED
