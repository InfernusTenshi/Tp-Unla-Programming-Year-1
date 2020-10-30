#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

//Pre:El carton tiene que estar creado
//Post:Le pide al usuario los numeros a cargar en el carton
void cargarMatrizManual(int m[][RENGLONES][COLUMNAS],int pos);

//Pre:Debe estar cargado el Carton
//Post:Muestra el/los cartones
void MostrarCarton(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int NumActual,char Comp[2][3][RENGLONES][COLUMNAS],int Num);

//Pre:Ninguna
//Post:Retorna la Cantidad de cartones con la que va a jugar el jugador
int CantidadCartones();

//Pre:El vector tiene que estar creado
//Post:Saca bolitas de 0 a 90 sin repetir
int Sacar(int Bolita[91]);

#endif
