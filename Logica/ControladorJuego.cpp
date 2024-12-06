#include "GameLogic.h"

ControladorJuego::ControladorJuego(Tablero& t, Jugador& j1, Jugador& j2)
    : tablero(t), jugador1(j1), jugador2(j2), turnos(1) {
    tablero.actualizarCursor(cursorFila, cursorColumna, true);
}

ControladorJuego::~ControladorJuego() { 
	delete tablero; 
	delete jugador1; 
	delete jugador2;
}

void ControladorJuego::moverCursor(int& cursor, vector<string> opcionesMenu, Tecla tecla) {
	switch (tecla) { 
		case Tecla::ARRIBA: 
			if (cursor > 0) cursor--; 
			break; 
		case Tecla::ABAJO: 
			if (cursor < opcionesMenu.size()) cursor++; 
			break; 
		default: 
			break; 
	}
}

void ControladorJuego::moverCursor(int& fila, int& columna, Tecla tecla) {
	tablero->actualizarCursor(fila, columna, false);
	switch (tecla) { 
		case Tecla::ARRIBA: 
			if (fila > 0) fila--; 
			break; 
		case Tecla::ABAJO: 
			if (fila < 2) fila++;
			break; 
		case Tecla::IZQUIERDA: 
			if (columna > 0) columna--; 
			break; 
		case Tecla::DERECHA:
			if (columna < 2) columna++; 
			break; 
		default: 
			break; 
	}
    tablero->actualizarCursor(fila, columna, true);
}

int ControladorJuego::getTurnos() const { 
	return turnos;
}
