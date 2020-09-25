#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#define TESTING 2 // 1 (MODO DESAROLLADOR HABILITADO) - ? (MODO DESAROLLADOR DESABILITADO)
struct DatosJugador
{
	char Nombre[8];
	char Apellido[8];
	int Dni;
	int Puntaje;
};

int main()
{
struct DatosJugador Jugador;

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
	
    srand(time(NULL));   
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole,7);

	
	if(TESTING == 1)
    {
    printf("\n*****************************************************");
    printf("\n*--------- PROGRAMA EN FASE DE TESTEO --------------*");
    printf("\n*---------------------------------------------------*");
    printf("\n*---------------------------------------------------*");
    printf("\n*--------- ELIJA ENTRE PRUEBA ");
    SetConsoleTextAttribute (hConsole,4);
	printf("PROGRAMADOR");
	SetConsoleTextAttribute (hConsole,7);
	printf(" (1)-------*");
    printf("\n*--------- ELIJA ENTRE PRUEBA ");
    SetConsoleTextAttribute (hConsole,6);
	printf("USUARIO FINAL");
	SetConsoleTextAttribute (hConsole,7);
	printf(" (2)-----*");
	printf("\n*****************************************************");
    SetConsoleTextAttribute (hConsole,4);
    printf("\n\n\n");
	printf("\n*****************************************************");
	printf("\n****************** ADVERTENCIA **********************");
	printf("\n*****************************************************");
    printf("\n*SI USTED VE ESTE MENSAJE NO PRESIONE NADA FUERA DE *");
    printf("\n*---------- LOS PARAMETROS ESTABLECIDOS ------------*");
    printf("\n*---------- RUPTURA DEL PROGRAMA SEGURA ------------*");
    printf("\n*****************************************************");
    SetConsoleTextAttribute (hConsole,7);
    printf("\n\n\n");
	SetConsoleTextAttribute (hConsole,4);
	printf("------->>> ");
	SetConsoleTextAttribute (hConsole,7);
    scanf("%d",&TEST);
    system("cls");
	}
	if(TESTING != 1)
	{
		TEST = 2;
	}
	
	if(TEST == 2)
    {
	printf("\n*****************************************************");
    printf("\n************** Bienvenido al Bingo ******************");
    printf("\n-----------------------------------------------------");
	}
    if(TEST == 2)
    {
    Jugador.Dni = RegistrarJugador(Jugador.Nombre,Jugador.Apellido);
	SetConsoleTextAttribute (hConsole,6);
	printf("Jugador: %s , %s , DNI: %d \n",Jugador.Nombre,Jugador.Apellido,Jugador.Dni);
	SetConsoleTextAttribute (hConsole,7);
	}
	
    cantidadCartones = CantidadCartones();
	char Comprobador[2][cantidadCartones][RENGLONES][COLUMNAS];
    if(cantidadCartones != 0)
    {
    	
        int cartonJugador[cantidadCartones][RENGLONES][COLUMNAS];
        int cartonesMaquina[cantidadCartones][RENGLONES][COLUMNAS];
        for(int i = 0; i < cantidadCartones ; i++)
        {
        	
		    int op;
		      do{
		      	system("cls");
		      	    if(TEST == 2)
    				{
		      	   printf("\n*********************************************");
		           printf("\n** Elija como quiere cargar el carton n%c %d **",167,i+1);
		           printf("\n*********************************************");
		           printf("\n****** -1- Carton personalizado *************");
		           printf("\n****** -2- Carton Aleatorio *****************");
		           printf("\n*********************************************");
		           //printf("\nOpcion: ");
		           printf("\n\n\n");
				   SetConsoleTextAttribute (hConsole,4);
				   printf("------->>> ");
				   SetConsoleTextAttribute (hConsole,7);
		           scanf("%d",&op);
		       		}
		       		if(TEST == 1)
		       		{
		       			op = 2;
					}
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
		                printf("\n*****************************************************");
		                printf("\n******** Opcion invalida intente de nuevo ***********");
		                printf("\n*****************************************************");
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
				printf("\n*********************************************");
				printf("\n***************** Bienvenido ****************");
				printf("\n*********************************************");
				printf("\n****** -1- Mostrar cartones            ******");
				printf("\n****** -2- Sacar 10 Bolitas            ******");
				printf("\n****** -3- Sacar bolilla               ******");
				printf("\n****** -4- Cantar Linea                ******");
				printf("\n****** -5- Cantar Columna              ******");
				printf("\n****** -6- Cantar Bingo                ******");
				printf("\n****** -7- Ver Puntajes                ******");
				printf("\n****** -0- Salir Del Juego             ******");
				printf("\n*********************************************");
				printf("\n******   Su Puntaje Actual es de : %3d ******",PuntajeActual);
				printf("\n*********************************************");
				printf("\n******   Puntaje De La Maquina : %3d   ******",PuntajeMaquina);
				printf("\n*********************************************");
	           	printf("\n\n\n");
				SetConsoleTextAttribute (hConsole,4);
				printf("------->>> ");
				SetConsoleTextAttribute (hConsole,7);
	            scanf("%d",&OPC);
	           switch(OPC)
	           {
	           	case 1:
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
			                PColumna = true;
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
		
		//printf("se sacaron %d",CantBolitas);
		if(PBingo == true)
		{
			if(PuntajeActual > PuntajeMaquina)
			{
					system("cls");
	                printf("\n*****************************************************");
	                printf("\n******** Usted Vencio a La Maquina por %3d **********",(PuntajeActual-PuntajeMaquina));
	                printf("\n*****************************************************");
	            	printf("\n*****************************************************");
					printf("\n********   Su Puntaje es de : %3d        ************",PuntajeActual);
					printf("\n*****************************************************");
					printf("\n********   Puntaje De La Maquina : %3d   ************",PuntajeMaquina);
					printf("\n*****************************************************");
	                printf("\n");
	                getch();
	                system("cls");
	                printf("\n*******************************************************");
	                if(CantBolitas > 89)
	                {
	                	printf("\n** Usted Finalizo el Juego Sacando Todas las Bolitas **",CantBolitas);
					}else
					{
						printf("\n**** Usted Finalizo el Juego Sacando %2d Bolitas *******",CantBolitas);
					}
	            	
	            	printf("\n*******************************************************");
	            	if(Multip == 1)
	            	{
	            	printf("\n******** Sus Puntajes No Seran Multiplicados **********");	
					}else
					{
	        	    	printf("\n**** Sus Puntajes Seran Multiplicados por %.1f   ********",Multip);	
					}
					getch();
					char SAVEAUX = 'G';
					int SAVE =8;
					do{
					system("cls");
	            	printf("\n*******************************************************");
	            	printf("\n************ Su Nuevo puntaje es de %3d ***************",(PuntajeActual*Multip));
	            	printf("\n*******************************************************\n\n");
	            	
	            	printf("\n*******************************************************");
	            	printf("\n************ Desea Guardar Su Puntaje? ****************");
	            	printf("\n*******************************************************");
	            	printf("\n************ (Y) SI *********** (N) NO ****************");
	            	printf("\n*******************************************************");
					printf("\n\n\n");
					SetConsoleTextAttribute (hConsole,4);
					printf("------->>> ");
					SetConsoleTextAttribute (hConsole,7);
					scanf("%c",&SAVEAUX);
					if(SAVEAUX == 'Y' || SAVEAUX == 'y') //  TIENE QUE GUARDAR Y MOSTRAR
					{
						SAVE =7;
						//void Escribir(int punt,int dni,char nomb[10],char ape[10])
					}
					if(SAVEAUX == 'N' || SAVEAUX == 'n')  // FINAL PROGRAMA !!
					{
						system("cls");
		                printf("\n*****************************************************");
		                printf("\n*********** Hasta Luego Vuelva Pronto ***************");
		                printf("\n*****************************************************");
		                getch();
					}
					
	            	}while(SAVE != 7);
	            	
	            	
			}
			if(PuntajeActual < PuntajeMaquina)// FINAL PROGRAMA !!
			{
					system("cls");
	                printf("\n*****************************************************");
	                printf("\n****  Usted Fue Vencido Por la Maquina       ********");
	                printf("\n*****************************************************");
	                printf("\n****  La Maquina Lo Destrozo con %3d Puntos  ********",PuntajeMaquina);
	                printf("\n*****************************************************");
	                
	                printf("\n");
			}
		}
	
	
		   
		   
	}
    return 0;
}
