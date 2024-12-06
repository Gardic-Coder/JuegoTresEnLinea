// Presentacion/GameUI.h
#pragma once
#include <vector>
#include <string>
#include <conio.h>
#include "../Logica/GameLogic.h"

enum class Tecla { ARRIBA, ABAJO, IZQUIERDA, DERECHA, ENTER, ESCAPE, G, OTRA };

class GameUI {
public:
    void mostrarMenu(int cursor, std::vector<std::string> opcionesMenu);
    void mostrarTablero(std::array<std::array<Casilla, 3>, 3> casillas);
    void acercaDelJuego();
	void ayuda();
};
