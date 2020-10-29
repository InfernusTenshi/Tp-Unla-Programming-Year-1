#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// PRE : COSAS QUE NECESITA LA FUNCION PARA EJECUTARSE DE MANERA CORRECTA
// POST : CAMBIOS O EFECTOS QUE TIENE LA FUNCION LUEGO DE EJECUTARSE SOBRE
// LOS VALORES DE ENTRADA O EN GENERAL LO QUE HACE

#define RENGLONES 3
#define COLUMNAS 5
int aleatorioEntre(int mini, int maxi);




int buscarEnMatriz(int m[][RENGLONES][COLUMNAS],int pos, int buscar);// Dejar en Funciones
void cargarMatrizAleatoria(int m[][RENGLONES][COLUMNAS],int pos);// Dejar en Funciones
void vaciar(int Bola[91]);// Dejar en Funciones
void vaciarCartonPiola(int carton[][RENGLONES][COLUMNAS],int cantidad);// Dejar en Funciones

// Visuales
void lineas(char P,char L,char F,char T,int X);// Dejar en Funciones
void Espacios(int X);
#endif // FUNCIONES_H_INCLUDED
