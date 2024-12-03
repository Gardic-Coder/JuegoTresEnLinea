#include "GameLogic.h"

Tablero::Tablero() { 
	int pos = 0; 
	for (int fila = 0; fila < 3; ++fila) { 
		for (int col = 0; col < 3; ++col) { 
			casillas[fila][col] = Casilla(pos++); 
			} 
		} 
	}

Tablero::getCasilla(int fila, int columna){
	return casillas[fila][columna];
}

Tablero::verificarGanador(int jugador){
	const int combinacionesGanadoras[8][3] = { 
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
		{0, 4, 8}, {2, 4, 6} 
	}; 
		
	for (const auto& combinacion : combinacionesGanadoras) { 
		if (casillas[combinacion[0]].getEstado() == jugador && 
			casillas[combinacion[1]].getEstado() == jugador && 
			casillas[combinacion[2]].getEstado() == jugador) { 
			return true; 
		}
	} 
	
	return false;
}

Tablero::actualizarCursor(int fila, int columna, bool c){
	casillas[fila][columna].setCursor(c);
}