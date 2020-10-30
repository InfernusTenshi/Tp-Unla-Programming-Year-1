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
#include "Datos.h"
#define MAXJUGADORES 30

void Menu(){
	Jugador MejoresJugadores[MAXJUGADORES];
	CargarArchivoLimpio(MejoresJugadores,MAXJUGADORES);
	CargarArchivo(MejoresJugadores);
	
	float Multip=0;
	int CantBolitas =0;
	int cantidadCartones;	
	int Bolillas[91];
	int NumActual =0;
	int TEST = 0;
	int PuntajeActual = 0;
	int PuntajeMaquina = 0;
	bool PLinea = false;
	bool PColumna = false;
	bool PBingo = false;
	vaciar(Bolillas);
	
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	lineas(201,205,187,36,1);
	printf("%c         Bienvenido Al Bingo        %c",186,186);
	lineas(200,205,188,36,0);
	
	Jugador Player=RegistrarJugador();
	SetConsoleTextAttribute (hConsole,6);
	printf("Jugador: %s , %s , DNI: %d \n",GetNombre(Player),GetApellido(Player),GetDni(Player));

	//Escribir(Player);
	SetConsoleTextAttribute (hConsole,7);
	cantidadCartones = CantidadCartones();
	char Comprobador[2][cantidadCartones][RENGLONES][COLUMNAS];
    if(cantidadCartones != 0)
    {
    	
        int cartonJugador[cantidadCartones][RENGLONES][COLUMNAS];
        int cartonesMaquina[cantidadCartones][RENGLONES][COLUMNAS];
        int op = 0;
        for(int i = 0; i < cantidadCartones ; i++)
        {
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
					
					lineas(201,205,187,36,1);



	                for(int I=0;I<10;I++)
	                {
	                	NumActual = Sacar(Bolillas);
					printf("%c       Salio el Numero:  %2d         %c",186,NumActual,186);
					printf("\n");
					}
					lineas(200,205,188,36,1);
	                printf("\n");
	                ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                ComprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                getch();
	                	system("cls");
	                	lineas(201,205,187,36,1);
						printf("%c       Cartones Del Jugador         %c",186,186);
						lineas(200,205,188,36,0);
						MostrarCarton(cartonJugador,cantidadCartones,Bolillas,-98,Comprobador,0);	
						getch();
						system("cls");					
						lineas(201,205,187,36,1);
						printf("%c     Cartones De La Maquina         %c",186,186);
						lineas(200,205,188,36,0);
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
	        		
	        		lineas(201,205,187,36,1);
					printf("%c       Salio el Numero:  %2d         %c",186,NumActual,186);
					lineas(200,205,188,36,0);

	                getch();	  
					ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                ComprobarLinea(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
	                system("cls");
	                lineas(201,205,187,36,1);
					printf("%c       Cartones Del Jugador         %c",186,186);
					lineas(200,205,188,36,0);
					MostrarCarton(cartonJugador,cantidadCartones,Bolillas,NumActual,Comprobador,0);
					getch();
					system("cls");					
					lineas(201,205,187,36,1);
					printf("%c     Cartones De La Maquina         %c",186,186);
					lineas(200,205,188,36,0);
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
					lineas(201,205,187,45,1);
					printf("%c   Hay %d Lineas Completas Marcadas en Rojo   %c",186,ComprobarLinea(cartonJugador,cantidadCartones,Bolillas,Comprobador,0),186);
					//Num 0 = Jugador / Num 1 = Maquina	
					lineas(200,205,188,45,0);
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
	                lineas(201,205,187,36,1);
					printf("%c       Cartones Del Jugador         %c",186,186);
					lineas(200,205,188,36,0);
					MostrarCarton(cartonJugador,cantidadCartones,Bolillas,NumActual,Comprobador,0);
					getch();
					
		           	system("cls");
						system("cls");					
						lineas(201,205,187,36,1);
						printf("%c     Cartones De La Maquina         %c",186,186);
						lineas(200,205,188,36,0);
					MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,NumActual,Comprobador,1);
					getch();
					}else{
	                	lineas(201,205,187,47,1);
						printf("%c Usted No Cumple COn los Requisitos Necesarios %c",186,186);
						lineas(200,205,188,47,0);
					}
	                getch();
				break;
				case 5:
					system("cls");
					if(ComprobarColumna(cartonJugador,cantidadCartones,Bolillas,Comprobador,0) != 0)
	                {
	                	lineas(201,205,187,45,1);
						printf("%c  Hay %d Columnas Completas Marcas en Celeste %c",186,
						ComprobarColumna(cartonJugador,cantidadCartones,Bolillas,Comprobador,0),186);
						//Num 0 = Jugador / Num 1 = Maquina
						lineas(200,205,188,45,0);
		                getch();
		                //ComprobarColumna(cartonesMaquina,cantidadCartones,Bolillas,Comprobador,1);
		                	if(PColumna == false)
		                	{
		                		PColumna = true;
		                		PuntajeActual = PuntajeActual+10;
							}
		                					              
		                system("cls");
	                lineas(201,205,187,36,1);
					printf("%c       Cartones Del Jugador         %c",186,186);
					lineas(200,205,188,36,0);
						MostrarCarton(cartonJugador,cantidadCartones,Bolillas,NumActual,Comprobador,0);
						getch();
						
			           	system("cls");
						system("cls");					
						lineas(201,205,187,36,1);
						printf("%c     Cartones De La Maquina         %c",186,186);
						lineas(200,205,188,36,0);
						MostrarCarton(cartonesMaquina,cantidadCartones,Bolillas,NumActual,Comprobador,1);

					}else{
	                	lineas(201,205,187,47,1);
						printf("%c Usted No Cumple COn los Requisitos Necesarios %c",186,186);
						lineas(200,205,188,47,0);
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
	                	lineas(201,205,187,47,1);
						printf("%c Usted No Cumple COn los Requisitos Necesarios %c",186,186);
						lineas(200,205,188,47,0);
					}
	                getch();
				break;
				case 7:
					system("cls");
	                MostrarTablaJugadores(MejoresJugadores,MAXJUGADORES);
	                getch();
				break;
				case 0:// FINAL PROGRAMA !!
					system("cls");
	                	lineas(201,205,187,47,1);
						printf("%c          Hasta Luego Vuelva Pronto            %c",186,186);
						lineas(200,205,188,47,0);
	                getch();
				break;
	        	default:
	        	    system("cls");
	                	lineas(201,205,187,47,1);
						printf("%c       Opcion Invalida Intente Nuevamente      %c",186,186);
						lineas(200,205,188,47,0);
	                printf("\n");
	                getch();
	        	break;
			   }
		   }while(OPC != 0);
		   
		for(int I=0;I<91;I++)
		{
			if(Bolillas[I] == 1)
			{
				CantBolitas=CantBolitas+1;
			}
		}
		/*
		Además, una vez terminada la partida se podrá multiplicar los puntos.
		 Si a la hora de lograr el Bingo se necesitaron sacar menos de 30 números de la bolsa,
		  el puntos obtenidos se multiplicarán por 2, si se necesitaron entre 30 y 50 números el
		   puntaje se multiplica por 1.7, si se necesitaron entre 50 y 70 números al puntaje se lo
		    multiplicará por 1.5.
		*/
		if(CantBolitas < 30)
		{
			Multip = 2;
		}else if(CantBolitas < 50)
		{
			Multip = 1.7;
		}else if(CantBolitas < 70)
		{
			Multip = 1.5;
		}else
		{
			Multip = 1;
		}
		

		if(PBingo == true)
		{
			if(PuntajeActual > PuntajeMaquina)
			{
					system("cls");
					lineas(201,205,187,47,1);
					printf("%c     Usted Fue Vencido Por La Maquina          %c",186,186);
					lineas(186,255,186,47,0);
					printf("%c     La Maquina Lo Detrozo con %3d Puntos      %c",186,PuntajeMaquina,186);
					lineas(200,205,188,47,0);
	                getch();
	                system("cls");
	                lineas(201,205,187,47,1);
	                if(CantBolitas > 89)
	                {
	                	printf("%c     Usted Gano Sacando Todas las Bolitas      %c",186,186);
					}else
					{
						printf("%c   Usted Finalizo El Juego Sacando %2d Bolitas  %c",186,CantBolitas,186);
					}


	            	if(Multip == 1)
	            	{
	            	lineas(186,255,186,47,0);
	            	printf("%c      Sus Puntajes No Seran Multiplicados      %c",186,186);
	            	//printf("\n******** Sus Puntajes No Seran Multiplicados **********");	
					}else
					{
						lineas(186,255,186,47,0);
						//printf("\n**** Sus Puntajes Seran Multiplicados por %.1f   ********",Multip);	
						printf("%c   Sus Puntajes Seran Multiplicados por %.1f    %c",186,Multip,186);

					}
					lineas(200,205,188,47,0);
					getch();
					char SAVEAUX = 'G';
					int SAVE =8;
					do{
					system("cls");
					lineas(201,205,187,47,1);
					printf("%c          Su Nuevo Puntaje es de %.0f           %c",186,(PuntajeActual*Multip),186);
					lineas(200,205,188,47,0);
	            	
	            	lineas(201,205,187,47,1);
					printf("%c            Desea Guardar Su Puntaje?          %c",186,186);
					lineas(186,255,186,47,0);
					printf("%c             (Y) SI           (N) NO           %c",186,186);
					lineas(200,205,188,47,0);
					printf("\n\n\n");
					SetConsoleTextAttribute (hConsole,4);
					printf("------->>> ");
					SetConsoleTextAttribute (hConsole,7);
					scanf("%c",&SAVEAUX);
					if(SAVEAUX == 'Y' || SAVEAUX == 'y') //  TIENE QUE GUARDAR Y MOSTRAR
					{
						SAVE =7;
						//Escribir(Player,(PuntajeActual*Multip))

					}
					if(SAVEAUX == 'N' || SAVEAUX == 'n')  // FINAL PROGRAMA !!
					{
						system("cls");
	                	lineas(201,205,187,47,1);
						printf("%c          Hasta Luego Vuelva Pronto            %c",186,186);
						lineas(200,205,188,47,0);
						break;
		                getch();
					}
					
	            	}while(SAVE != 7);
	            	
	            	
			}
			if(PuntajeActual < PuntajeMaquina)// FINAL PROGRAMA !!
			{
				lineas(201,205,187,47,1);
				printf("%c       Usted Fue Vencido Por La Maquina        %c",186,186);
				lineas(186,255,186,47,0);
				printf("%c       La Maquina Le Gano Con %3d Puntos       %c",186,PuntajeMaquina,186);
				lineas(200,205,188,47,0);
	            printf("\n");
			}
		}
	
	
		   
		   
	}
	
}
