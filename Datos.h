#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
struct DatosJugador;


typedef struct DatosJugador *Jugador;

Jugador RegistrarJugador();
//------------- Gets
char* GetNombre(Jugador J);
char* GetApellido(Jugador J);
int GetDni(Jugador J);
int GetPuntaje(Jugador J);

//------------



//---- Relevamiento de Datos
void CargarArchivo(Jugador Jug[]);
void CargarArchivoLimpio(Jugador Jug[],int C);




//---- Utilizacion de Datos

void MostrarTablaJugadores(Jugador Jug[],int Max);
void Escribir (Jugador Jug,float Punt);



//---Internas
Jugador Leer(char aux[40]);
Jugador VaciarJugador();


#endif
