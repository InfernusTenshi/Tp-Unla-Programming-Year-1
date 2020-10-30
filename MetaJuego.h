#ifndef METAJUEGO_H_INCLUDED
#define METAJUEGO_H_INCLUDED


//Pre:debe estar creado e iniciado el carton
//Post:comprueba si se puede cantar Linea si es asi lo hace
int ComprobarLinea(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a MetaJuego

//Pre:El carton debe estar creado e iniciado
//comprueba si se puede cantar Columna si es asi lo hace
int ComprobarColumna(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num);// mover a MetaJuego

//Pre:El carton debe estar creado e iniciado
//Post:Compueba si se puede cantar bingo si es asi lo hace
int ComprobarBingo(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int Num);// mover a MetaJuego

#endif
