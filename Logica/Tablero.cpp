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
	// Verificar filas 
	for (int fila = 0; fila < 3; ++fila) { 
		if (casillas[fila][0].getEstado() == jugador && 
			casillas[fila][1].getEstado() == jugador && 
			casillas[fila][2].getEstado() == jugador) { 
			return true; 
		} 
	} 
	
	// Verificar columnas 
	for (int columna = 0; columna < 3; ++columna) { 
		if (casillas[0][columna].getEstado() == jugador && 
			casillas[1][columna].getEstado() == jugador && 
			casillas[2][columna].getEstado() == jugador) { 
			return true; 
		} 
	} 
	
	// Verificar diagonales 
	if (casillas[0][0].getEstado() == jugador && 
		casillas[1][1].getEstado() == jugador && 
		casillas[2][2].getEstado() == jugador) { 
		return true; 
	} 
	if (casillas[0][2].getEstado() == jugador && 
		casillas[1][1].getEstado() == jugador && 
		casillas[2][0].getEstado() == jugador) { 
		return true; 
	} 
	
	// Si ninguna combinacion ganadora se cumple, regresar false 
	return false;
}

Tablero::actualizarCursor(int fila, int columna, bool c){
	casillas[fila][columna].setCursor(c);
}