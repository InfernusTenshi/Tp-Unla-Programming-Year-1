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



//---- Relevamiento de Datos------

//Pre:El vector jugador debe estar creado y debe existir el archivo
//Post:Se lee el archivo recupera los datos y los guarda en un vector
void CargarArchivo(Jugador Jug[]);

//Pre:El vector jugador debe estar creado
//Post:Se vacian las posicions de la estructura jug
void CargarArchivoLimpio(Jugador Jug[],int C);

//---- Utilizacion de Datos

//Pre:tiene que existir el jugador y estar cargado
//Post: Muestra la tabla de todos los jugadores
void MostrarTablaJugadores(Jugador Jug[],int Max);

//Pre:Debe esta declarada el puntero Jugador
//Post:Escribe en un archivo los datos del Jugador
void Escribir (Jugador Jug,float Punt);

//---Internas-------

//Pre:Debe estar creado el archivo.ear
//Post:recupera los datos del archivo y los retorna como una estructura
Jugador Leer(char aux[40]);

//Pre:ninguna
//Post:vacia todas las variables de un jugador y retorna la estructura
Jugador VaciarJugador();


#endif
