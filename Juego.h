#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

void cargarMatrizManual(int m[][RENGLONES][COLUMNAS],int pos);
void MostrarCarton(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int NumActual,char Comp[2][3][RENGLONES][COLUMNAS],int Num);
int CantidadCartones();
void cartonesMaquina(int cantidad);
int Sacar(int Bolita[91]);

#endif
