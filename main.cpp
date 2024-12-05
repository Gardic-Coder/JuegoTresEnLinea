#include <iostream>
#include <vector>
#include "Logica/GameLogic.h"
#include "Presentacion/GameUI.h"

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

struct partidas {
	Tablero tablero;
	Jugador j1;
	Jugador j2;
	bool terminada;
	bool nueva;
};

ControladorJuego jugadorVsJugador(ControladorJuego Partida);

int main() {
	int cursor = 0, fila = 0, columna = 0;
	bool salir = false
	
	do {
		system("cls");
		mostrarMenu(cursor, opcionesMenuPrincipal);
		Tecla tecla = obtenerTecla();
		moverCursor(cursor, opcionesMenuPrincipal, tecla);
		if(tecla == Tecla::Enter) {
			system("cls");
			switch(cursor) {
				case 0: {
					do {
						mostrarMenu(cursor, opcionesSubMenu);
						tecla = obtenerTecla();
						moverCursor(cursor, opcionesSubMenu, tecla);
						if(tecla == Tecla::Enter) {
							switch(cursor) {
								case 0: {
									ControladorJuego Partida = ControladorJuego(Tablero(), Jugador("Jugador 1"), Jugador("Jugador 2"));
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
					acercaDelJuego();
					break;
				}
				case 3: {
					ayuda();
					break;
				}
				case 4: {
					salir = !salir;
					break;
				}
			}
			cursor = 0;	
		}
	}while(!salir)
	return 0;
}

ControladorJuego jugadorVsJugador(ControladorJuego Partida){
	
}