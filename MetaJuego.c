#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "Juego.h"
#include "MetaJuego.h"
#include "Datos.h"




int ComprobarLinea(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num)
{
	//Num 0 = Jugador / Num 1 = Maquina	
	int cont =0;
	int acu =0;
	int aculumnas = 0;
	
	for (int M=0;M<cantidad;M++)
	{
		for(int F=0;F<RENGLONES;F++)
		{
			for(int C=0;C<COLUMNAS;C++)
			{
					if(Bolitas[carton[M][F][C]] == 1)
					{
						cont=cont+1;
						if(Comp[Num][M][F][C]=='C')
						{
							Comp[Num][M][F][C]='X';
						}
						else
						{
							Comp[Num][M][F][C]='L';
						}
					}
			}
			if (cont == COLUMNAS)
			{
				aculumnas=aculumnas+1;
				for(int X=0;X<COLUMNAS;X++)
				{
				if(Comp[Num][M][F][X]=='X')
				{
					Comp[Num][M][F][X]='L';
				}
				}
			}
			else
			{
				for(int X=0;X<COLUMNAS;X++)
				{
					if(Comp[Num][M][F][X]=='X')
					{
						Comp[Num][M][F][X]='C';
					}
					else
					{
						Comp[Num][M][F][X] = 'O';
					}
						
					
				}
			}
			cont =0;
		}
    }
    return aculumnas;
}

int ComprobarColumna(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],char Comp[2][3][RENGLONES][COLUMNAS],int Num)
{
	//Num 0 = Jugador / Num 1 = Maquina	
	int cont =0;
	int acu =0;
	int aculumnas = 0;
	
	for (int M=0;M<cantidad;M++)
	{
		
		for(int C=0;C<COLUMNAS;C++)
		{
			for( int F=0;F<RENGLONES;F++)
			{
					if(Bolitas[carton[M][F][C]] == 1)
					{
						cont=cont+1;
						if(Comp[Num][M][F][C]!='L')
						{
							Comp[Num][M][F][C]='C';	
						}
					}
			}
			if (cont == RENGLONES)
			{
				aculumnas=aculumnas+1;
			}
			else
			{
				for(int X=0;X<COLUMNAS;X++)
				{
					if(Comp[Num][M][X][C]!='L')
					{
						Comp[Num][M][X][C] = 'O';
					}
				}
			}
			cont =0;
		}
    }
    return aculumnas;
}
int ComprobarBingo(int carton[][RENGLONES][COLUMNAS],int cantidad,int Bolitas[91],int Num){
int cont = 0;
int Bingo = 0;
for (int M=0;M<cantidad;M++)
    {
    	for(int C=0;C<COLUMNAS;C++)
        {
            for( int F=0;F<RENGLONES;F++)
            {
                if(Bolitas[carton[M][F][C]] == 1)
                {
                    cont=cont+1;
                }
            }
        }
        if(cont == 15)
        {
            Bingo = 10;
            break;
        }
        cont =0;
    }
	return Bingo;
}
