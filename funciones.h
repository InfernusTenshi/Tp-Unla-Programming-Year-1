#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// PRE : COSAS QUE NECESITA LA FUNCION PARA EJECUTARSE DE MANERA CORRECTA
// POST : CAMBIOS O EFECTOS QUE TIENE LA FUNCION LUEGO DE EJECUTARSE SOBRE
// LOS VALORES DE ENTRADA O EN GENERAL LO QUE HACE

#define RENGLONES 3
#define COLUMNAS 5

//Pre:Enviar dos enteros por parametro
//Post:Retorna un numero aleatoreo entre los valores que se envian por parametro
int aleatorioEntre(int mini, int maxi);

//Pre:El carton tiene que estar creado
//Post:Se usa para que no se cargue la matriz con numeros repetidos si es repetido retorna 0
int buscarEnMatriz(int m[][RENGLONES][COLUMNAS],int pos, int buscar);

//Pre:El carton tiene que estar creado
//Post:Se carga el Carton sin numero repetidos
void cargarMatrizAleatoria(int m[][RENGLONES][COLUMNAS],int pos);

//Pre:Tiene que estar credo un vector
//Post:Se vacia el vector escribiendo 0 en cada posicion
void vaciar(int Bola[91]);

//Pre:Debe estar creado el carton/Matriz
//Post:Se vacia la matriz escribiendola con 0
void vaciarCartonPiola(int carton[][RENGLONES][COLUMNAS],int cantidad);

// Visuales
void lineas(char P,char L,char F,char T,int X);
void Espacios(int X);
#endif // FUNCIONES_H_INCLUDED
