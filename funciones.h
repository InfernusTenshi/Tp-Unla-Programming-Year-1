#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define RENGLONES 3
#define COLUMNAS 5
int aleatorioEntre(int mini, int maxi);// Dejar en Funciones
int buscarEnMatriz(int m[][RENGLONES][COLUMNAS],int pos, int buscar);// Dejar en Funciones
void cargarMatrizAleatoria(int m[][RENGLONES][COLUMNAS],int pos);// Dejar en Funciones
void vaciar(int Bola[91]);// Dejar en Funciones
void vaciarCartonPiola(int carton[][RENGLONES][COLUMNAS],int cantidad);// Dejar en Funciones

// Visuales
void lineas(char P,char L,char F,char T,int X);// Dejar en Funciones
void Espacios(int X);
#endif // FUNCIONES_H_INCLUDED
