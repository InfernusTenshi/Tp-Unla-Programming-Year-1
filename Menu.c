#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "Juego.h"
#include "MetaJuego.h"
#include "Menu.h"


void MainMenu(float Multip,int CantBolitas,int cantidadCartones,	int Bolillas[],int NumActual,
int PuntajeActual ,int PuntajeMaquina,	bool PLinea,bool PColumna,bool PBingo,
char Comprobador[2][cantidadCartones][RENGLONES][COLUMNAS])
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


if(cantidadCartones != 0)
    {
    	
        int cartonJugador[cantidadCartones][RENGLONES][COLUMNAS];
        int cartonesMaquina[cantidadCartones][RENGLONES][COLUMNAS];
        for(int i = 0; i < cantidadCartones ; i++)
        {
        	
		    int op;
		      do{
		      	system("cls");
		      	        lineas(201,205,187,36,1);
						printf("%c   Por Favor Elija Como Desearia    %c\n",186,186);
						printf("%c       El Carton Actual N%c %d        %c",186,167,i+1,186);
						lineas(200,205,188,36,0);
						lineas(201,205,187,36,1);//inicio
						printf("%c (1) Carton Personalizado           %c\n",186,186);
						printf("%c (2) Carton Aleatorio               %c\n",186,186);
						lineas(200,205,188,36,1);
		           //printf("\nOpcion: ");
		           printf("\n\n\n");
				   SetConsoleTextAttribute (hConsole,4);
				   printf("------->>> ");
				   SetConsoleTextAttribute (hConsole,7);
		           scanf("%d",&op);
		           switch(op)
		           {
		
		            case 1:
		                //LLAMAR FUNCION GENERAR POR TECLADO
		                vaciarCartonPiola(cartonJugador,cantidadCartones);
		                cargarMatrizManual(cartonJugador,i);
		               	break;
		            case 2:
		                //LLAMAR FUNCION GENERAR ALEATORIO
		                cargarMatrizAleatoria(cartonJugador,i);  		
		                break;
		            default:
		                system("cls");
						lineas(201,205,187,36,1);
						printf("%c Opcion Invalida Intentelo De Nuevo %c",186,186);
						lineas(200,205,188,36,0);
		                printf("\n\n\n");
		                getch();
		                system("cls");
		            break;
		           }
		        }
		       while(op > 2 || op < 1);
		       
		      
		       
		   }	 
		for(int i = 0; i < cantidadCartones ; i++)
        {
        	
		   
		   cargarMatrizAleatoria(cartonesMaquina,i);
		       
		      
		       
		}
		int OPC;
		
			system("cls");
    	       	do{
				system("cls");
				lineas(201,205,187,36,1);
				printf("%c              Bienvenido            %c",186,186);
				lineas(200,205,188,36,0);// fin 
				lineas(201,205,187,36,1);//inicio
				printf("%c (1) Mostrar Cartones               %c\n",186,186);
				printf("%c (2) Sacar 10 Bolitas               %c\n",186,186);
				printf("%c (3) Sacar Bolita                   %c\n",186,186);
				printf("%c (4) Cantar Linea                   %c\n",186,186);
				printf("%c (5) Cantar Columna                 %c\n",186,186);
				printf("%c (6) Cantar Bingo                   %c\n",186,186);
				printf("%c (7) Ver Puntajes Altos             %c\n",186,186);
				printf("%c (0) Salir del Juego                %c\n",186,186);
				lineas(200,205,188,36,1);
				lineas(201,205,187,36,0);
				printf("%c Su Puntaje Actual es: %3d          %c",186,PuntajeActual,186);
				lineas(200,205,188,36,0);
				lineas(201,205,187,36,0);
				printf("%c Puntaje De La Maquina : %3d        %c",186,PuntajeMaquina,186);
				lineas(200,205,188,36,0);

	           	printf("\n\n\n");
				SetConsoleTextAttribute (hConsole,4);
				printf("------->>> ");
				SetConsoleTextAttribute (hConsole,7);
	            scanf("%d",&OPC);
	           switch(OPC)
	           {
	           	case 1:
	           			system("cls");
						lineas(201,205,187,36,1);
						printf("%c       Cartones Del Jugador         %c",186,186);
						lineas(200,205,188,36,0);
						printf("\n");
						MostrarCarton(cartonJugador,cantidadCartones,Bolillas,-98,Comprobador,0);
						getch();
						system("cls");
						lineas(201,205,187,36,1);
						printf("%c     Cartones De La Maquina         %c",186,186);
						lineas(200,205,188,36,0);	
						printf("\n"); 	
						MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,-98,Comprobador,1);
						getch();
	           	break;
	           	case 2:
					system("cls");
	                printf("\n*****************************************************");
	                for(int I=0;I<10;I++)
	                {
	                	NumActual = Sacar(Bolillas);
	                	printf("\n******** Salio EL Numero ----> %2d *******************",NumActual);
					}
	                printf("\n*****************************************************");
	                printf("\n");
	                ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                ComprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                getch();
	                	system("cls");
						printf("\n*********************************************");
						printf("\n*************** Cartones Jugador ************");
						printf("\n*********************************************");
						printf("\n");
						MostrarCarton(cartonJugador,cantidadCartones,Bolillas,-98,Comprobador,0);
						getch();
						system("cls");
		           		printf("\n*********************************************");
						printf("\n*************** Cartones Maquina ************");
						printf("\n*********************************************");	
						printf("\n"); 	
						MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,-98,Comprobador,1);
						getch();
					if(ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1) != 0)
	                {
	                	if(PColumna == false)
	                	{
	                		PColumna = true;
	                		PuntajeMaquina = PuntajeMaquina+10;
						}
					}
					if(ComprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1) != 0)
	                {
	                	if(PLinea == false)
	                	{
	                		PLinea = true;
	                		PuntajeMaquina = PuntajeMaquina+20;
						}
					}
					if(ComprobarBingo(cartonesMaquina,cantidadCartones,Bolillas,0)== 10)
					{
			            if(PBingo == false)
			            {
			                PBingo = true;
			                PuntajeMaquina = PuntajeMaquina+70;
						}
						OPC=0;
					}
	        	break;
	        	case 3:
	        		system("cls");
	        		NumActual = Sacar(Bolillas);
	                printf("\n*****************************************************");
	                printf("\n******** Salio EL Numero ----> %2d *******************",NumActual);
	                printf("\n*****************************************************");
	                printf("\n");
	                getch();	  
					ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                ComprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                system("cls");
					printf("\n*********************************************");
					printf("\n*************** Cartones Jugador ************");
					printf("\n*********************************************");
					printf("\n");
					MostrarCarton(cartonJugador,cantidadCartones,Bolillas,NumActual,Comprobador,0);
					getch();
					
		           	system("cls");
		           	printf("\n*********************************************");
					printf("\n*************** Cartones Maquina ************");
					printf("\n*********************************************");	
					printf("\n"); 
					MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,NumActual,Comprobador,1);
					getch();
	                if(ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1) != 0)
	                {
	                	if(PColumna == false)
	                	{
	                		PColumna = true;
	                		PuntajeMaquina = PuntajeMaquina+10;
						}
					}
					if(ComprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1) != 0)
	                {
	                	if(PLinea == false)
	                	{
	                		PLinea = true;
	                		PuntajeMaquina = PuntajeMaquina+20;
						}
					}
					if(ComprobarBingo(cartonesMaquina,cantidadCartones,Bolillas,0)== 10)
					{
			            if(PBingo == false)
			            {
			                PBingo = true;
			                PuntajeMaquina = PuntajeMaquina+70;
						}
						OPC=0;
					}
				break;
				case 4:
					system("cls");
					if(ComprobarLinea(cartonJugador,cantidadCartones,Bolillas,Comprobador,0) != 0)
					{
	                printf("\n*****************************************************");
	                printf("\n***** Hay %d Lineas Completas Marcadas en Rojo *******",
					ComprobarLinea(cartonJugador,cantidadCartones,Bolillas,Comprobador,0));//Num 0 = Jugador / Num 1 = Maquina	
	                printf("\n*****************************************************");
	                getch();
	                // suma de Puntajes
	                	if(PLinea == false)
	                	{
	                		PLinea = true;
	                		PuntajeActual = PuntajeActual+20;
						}
	                // fin Suma
	                //omprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                					              
	                system("cls");
					printf("\n*********************************************");
					printf("\n*************** Cartones Jugador ************");
					printf("\n*********************************************");
					printf("\n");
					MostrarCarton(cartonJugador,cantidadCartones,Bolillas,NumActual,Comprobador,0);
					getch();
					
		           	system("cls");
		           	printf("\n*********************************************");
					printf("\n*************** Cartones Maquina ************");
					printf("\n*********************************************");	
					printf("\n"); 
					MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,NumActual,Comprobador,1);
					getch();
					}else{
					   	printf("\n*********************************************");
						printf("\n***** Usted no Cumple Con Los Requisitos ****");
						printf("\n*********************************************");
					}
	                getch();
				break;
				case 5:
					system("cls");
					if(ComprobarColumna(cartonJugador,cantidadCartones,Bolillas,Comprobador,0) != 0)
	                {
		                printf("\n*****************************************************");
		                printf("\n*** Hay %2d Columnas Completas Marcadas en Celeste ***",
						ComprobarColumna(cartonJugador,cantidadCartones,Bolillas,Comprobador,0));//Num 0 = Jugador / Num 1 = Maquina	
		                printf("\n*****************************************************");
		                getch();
		                //ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
		                	if(PColumna == false)
		                	{
		                		PColumna = true;
		                		PuntajeActual = PuntajeActual+10;
							}
		                					              
		                system("cls");
						printf("\n*********************************************");
						printf("\n*************** Cartones Jugador ************");
						printf("\n*********************************************");
						printf("\n");
						MostrarCarton(cartonJugador,cantidadCartones,Bolillas,NumActual,Comprobador,0);
						getch();
						
			           	system("cls");
			           	printf("\n*********************************************");
						printf("\n*************** Cartones Maquina ************");
						printf("\n*********************************************");	
						printf("\n"); 
						MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,NumActual,Comprobador,1);

					}else{
					   	printf("\n*********************************************");
						printf("\n***** Usted no Cumple Con Los Requisitos ****");
						printf("\n*********************************************");
					}
					getch();
				break;
				case 6:
					system("cls");
					if(ComprobarBingo(cartonJugador,cantidadCartones,Bolillas,0)== 10)
					{
			            if(PBingo == false)
			            {
			                PBingo = true;
			                PuntajeActual = PuntajeActual+10;
						}
						//printf("\n*************** Usted gana ***************\n");
						OPC=0;
					}else{
					   	printf("\n*********************************************");
						printf("\n***** Usted no Cumple Con Los Requisitos ****");
						printf("\n*********************************************");
					}
	                getch();
				break;
				case 7:
					system("cls");
	                Leer();
	                getch();
				break;
				case 0:// FINAL PROGRAMA !!
					system("cls");
	                printf("\n*****************************************************");
	                printf("\n*********** Hasta Luego Vuelva Pronto ***************");
	                printf("\n*****************************************************");
	                getch();
				break;
	        	default:
	        	    system("cls");
	                printf("\n*****************************************************");
	                printf("\n******** Opcion invalida intente de nuevo ***********");
	                printf("\n*****************************************************");
	                printf("\n");
	                getch();
	        	break;
			   }
		   }while(OPC != 0);
		   
	}
		
}
