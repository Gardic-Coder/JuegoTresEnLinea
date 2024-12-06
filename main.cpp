#include <iostream>
#include <vector>
#include <string>
#include "Logica/GameLogic.h"
#include "Presentacion/GameUI.h"

using namespace std;

vector<string> opcionesMenuPrincipal = { // Aca se guardan las cadenas de texto utilizadas en el menu principal.
	"INICIAR JUEGO",
	"CARGAR JUEGO",
	"ACERCA DEL JUEGO",
	"AYUDA",
	"SALIR"
};

vector<string> opcionesSubMenu = {
	"JUGADOR VS JUGADOR",
	"JUGADOR VS BOT",
	"BOT VS BOT"
};

ControladorJuego jugadorVsJugador(ControladorJuego Partida);
Tecla obtenerTecla() { 
	int c = _getch(); 
	if (c == 224) { // Flechas del teclado 
		switch (_getch()) { 
			case 72: return Tecla::ARRIBA; 
			case 80: return Tecla::ABAJO; 
			case 75: return Tecla::IZQUIERDA; 
			case 77: return Tecla::DERECHA; 
		} 
	} else if (c == 13) { 
		return Tecla::ENTER; 
	} else if (c == 27) { 
		return Tecla::ESCAPE; 
	} else if (c == 'g' || c == 'G') { 
		return Tecla::G; 
	}
	return Tecla::OTRA; // Valor por defecto 
}


int main() {
	int cursor = 0, fila = 0, columna = 0;
	bool salir = false;
	Tablero tablero = new Tablero();
	GameUI interfaz;
	
	do {
		system("cls");
		interfaz.mostrarMenu(cursor, opcionesMenuPrincipal);
		Tecla tecla = obtenerTecla();
		interfaz.moverCursor(cursor, opcionesMenuPrincipal, tecla);
		if(tecla == Tecla::ENTER) {
			system("cls");
			switch(cursor) {
				case 0: {
					do {
						mostrarMenu(cursor, opcionesSubMenu);
						tecla = obtenerTecla();
						moverCursor(cursor, opcionesSubMenu, tecla);
						if(tecla == Tecla::ENTER) {
							switch(cursor) {
								case 0: {
									ControladorJuego Partida = ControladorJuego(tablero, Jugador("Jugador 1"), Jugador("Jugador 2"));
									break;
								}
								case 1: {
									
									break;
								}
								case 2: {
									
									break;
								}
							}	
						}
					}while(tecla != Tecla::ESCAPE);
					cursor = 0;
					break;
				}
				case 1: {
					
					break;
				}
				case 2: {
					GameUI::acercaDelJuego();
					break;
				}
				case 3: {
					GameUI::ayuda();
					break;
				}
				case 4: {
					salir = !salir;
					break;
				}
			}
			cursor = 0;	
		}
	}while(!salir);
	return 0;
}

ControladorJuego jugadorVsJugador(ControladorJuego Partida){
	
}