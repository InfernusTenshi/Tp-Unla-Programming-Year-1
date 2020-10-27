#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
struct DatosJugador;


typedef struct DatosJugadorg *Jugador;

Jugador RegistrarJugador();
//------------- Gets
int GetNombre(Jugador J);
int GetApellido(Jugador J);
int GetDni(Jugador J);
int GetPuntaje(Jugador J);

//------------

void Escribir (struct DatosJugador Jug); // ------------> MIO
void Leer(); // ------------> MIO


#endif
