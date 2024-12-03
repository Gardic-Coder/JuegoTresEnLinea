#include "GameLogic.h"

ControladorJuego::ControladorJuego(Tablero& t, Jugador& j1, Jugador& j2)
    : tablero(t), jugador1(j1), jugador2(j2), cursorFila(0), cursorColumna(0), enMenu(false), numOpciones(-1), turnos(1) {
    tablero->actualizarCursor(cursorFila, cursorColumna, true);
}

ControladorJuego::ControladorJuego(int numOpcMenu)
	: tablero(nullptr), jugador1(nullptr), jugador2(nullptr), cursorPos(0), numOpciones(numOpcMenu), enMenu(true), turnos(0) { 
}

ControladorJuego::~ControladorJuego() { 
	delete tablero; 
	delete jugador1; 
	delete jugador2;
}

void ControladorJuego::moverCursor(int nuevaFila, int nuevaColumna) {
    tablero->actualizarCursor(cursorFila, cursorColumna, false);
    cursorFila = nuevaFila;
    cursorColumna = nuevaColumna;
    tablero->actualizarCursor(cursorFila, cursorColumna, true);
}

void ControladorJuego::moverCursorArriba() {
    if (enMenu) {
        if (cursorPos > 0) { 
			actualizarCursor(cursorFila - 1); 
		}
    } else {
        if (cursorFila > 0) {
            moverCursor(cursorFila - 1, cursorColumna);
        }
    }
}

void ControladorJuego::moverCursorAbajo() {
    if (enMenu) {
        if (cursorPos < numOpciones - 1) { 
			actualizarCursor(cursorFila + 1); 
		}
    } else {
        if (cursorFila < 2) {
            moverCursor(cursorFila + 1, cursorColumna);
        }
    }
}

void ControladorJuego::moverCursorIzquierda() {
    if (!enMenu) {
        if (cursorColumna > 0) {
            moverCursor(cursorFila, cursorColumna - 1);
        }
    }
}

void ControladorJuego::moverCursorDerecha() {
    if (!enMenu) {
        if (cursorColumna < 2) {
            moverCursor(cursorFila, cursorColumna + 1);
        }
    }
}

void ControladorJuego::seleccionar() {
    if (enMenu) {
        // Logica para seleccionar una opcion en el menu
    } else {
        Casilla& casillaSeleccionada = tablero->getCasilla(cursorFila, cursorColumna);
        if (casillaSeleccionada.getEstado() == 0) {
        	int jugadorActual = (turnos % 2) + 1; // Alterna entre 1 y 2
        	casillaSeleccionada.setEstado(jugadorActual, turnos); 
			if (jugadorActual == 1) { 
				jugador1->conquistarCasilla(&casillaSeleccionada); 
			} else { 
				jugador2->conquistarCasilla(&casillaSeleccionada); 
			} 
			turnos++; 
        }
    }
}

void ControladorJuego::cancelar() {
    if (enMenu) {
        // Logica para retroceder en el menu
    }
}

void ControladorJuego::guardarYSalir() {
    if (!enMenu) {
        // Logica para guardar el estado del juego y salir
    }
}

void ControladorJuego::cambiarModo() {
    enMenu = !enMenu; 
	if (enMenu) { 
		// Destruye la instancia actual del juego y crea un menu 
		delete tablero; 
		delete jugador1; 
		delete jugador2; 
		cursorFila = 0; // Reajusta la posicion del cursor en el menu 
		cursorColumna = -1;
		numOpciones = 3; // Ejemplo de numero de opciones en el menu 
	} else { 
		// Destruye la instancia actual del menu y crea un nuevo juego 
		tablero = new Tablero(); 
		jugador1 = new Jugador("Jugador 1"); 
		jugador2 = new Jugador("Jugador 2");
		// Reajusta la posicion del cursor en el tablero 
		cursorFila = 0; 
		cursorColumna = 0;
		if (tablero) { 
			tablero->actualizarCursor(0, 0, true); 
		} 
	}
}

void ControladorJuego::actualizarCursor(int nuevaPos) { 
	cursorPos = nuevaPos; 
}

int ControladorJuego::getTurnos() const { 
	return turnos;
}
