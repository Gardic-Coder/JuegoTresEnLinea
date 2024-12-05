// Presentacion/GameUI.h
#pragma once
#include <vector>
#include <conio.h>
#include "Logica/GameLogic.h"

enum class Tecla { ARRIBA, ABAJO, IZQUIERDA, DERECHA, ENTER, ESCAPE, G, OTRA };
 
Tecla obtenerTecla() { 
	int c = _getch(); 
	if (c == 224) { // Flechas del teclado 
		switch (_getch()) { 
			case 72: return Direccion::ARRIBA; 
			case 80: return Direccion::ABAJO; 
			case 75: return Direccion::IZQUIERDA; 
			case 77: return Direccion::DERECHA; 
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

class GameUI {
public:
    void mostrarMenu(int cursor, vector<string> opcionesMenu);
    void mostrarTablero(std::array<std::array<Casilla, 3>, 3> casillas);
    void acercaDelJuego();
	void ayuda();
};
