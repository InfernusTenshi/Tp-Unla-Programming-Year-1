#ifndef METAJUEGO_H_INCLUDED
#define METAJUEGO_H_INCLUDED

int ComprobarLinea(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a MetaJuego
int ComprobarColumna(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a MetaJuego
int ComprobarBingo(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int Num);// mover a MetaJuego

#endif
