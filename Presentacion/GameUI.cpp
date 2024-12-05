// Presentacion/GameUI.cpp
#include "GameUI.h"
#define SEPARADOR "---------------------------------------------------------------------------------------------------------------------"
#define RESET "\033[0m"  // Restablece el color de la fuente.
#define YELLOW "\033[33m"  // Cambia el color de la fuente a amarillo.
#define PURPURA "\033[35m" // Cambia el color de la fuente a purpura.
#define VERDE "\033[1;32m"


using namespace std;

void GameUI::mostrarMenu(int cursor, std::vector<string> opcionesMenu) { 
	cout << PURPURA << SEPARADOR << RESET << endl;
	for(size_t i = 0; i < opcionesMenu.size(); ++i) { // Se repite hasta imprimir todas las opciones del menu.
		if(i == cursor) { // Si se va a imprimir la posicion donde esta el cursor se imprime una flecha.
			cout << YELLOW << "			->>" << RESET;
		} else { // Sino se deja un espacio.
			cout << "				";
		}
		cout << opcionesMenu[i] << endl;
	}
	cout << PURPURA << SEPARADOR << RESET << endl;
}

void mostrarTablero(array<array<Casilla, 3>, 3> casillas) {
	int estado;
	for (const auto& fila : casillas) { 
		cout << "			";
		for (const auto& casilla : fila) {
			if(Casilla.getCursor()){
				cout << VERDE << "{ ";
			} else {
				cout << PURPURA << "{ ";
			}
			cout << YELLOW;
			estado = Casilla.getEstado();
			if(estado == 1){
				cout << "X";
			} else if(estado == 2){
				cout << "O";
			} else {
				cout << " ";
			}
			if(Casilla.getCursor()){
				cout << VERDE << " }";
			} else {
				cout << PURPURA << " }";
			}
		} 
		cout << endl;
	}
}

void GameUI::acercaDelJuego() {
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "ACERCA DEL JUEGO" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << "		El juego de " << YELLOW << "tres en raya" << RESET << " consiste en capturar" << endl;
	cout << "	3 casillas que tracen una recta. Se pueden alinear horizontal, vertical" << endl;
	cout << "	y diagonalmente. En esta version del juego, ademas, cada jugador puede" << endl;
	cout << "	tener como maximo 3 casillas capturadas a la vez, por lo que al intentar" << endl;
	cout << "	capturar una 4ta se elimina la casilla capturada mas antigua." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "CREDENCIALES" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << "	Juego creado en 2024 por:" << endl;
	cout << "		-> Juan Garcia." << endl;
	cout <<	"		-> Keiner Perez." << endl;
	cout << "		-> Roxana Moreno." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << "	Presione cualquier tecla para volver al menu." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	_getch();
}

void GameUI::ayuda() {
	char c = 16; // Para imprimir el caracter ASCII de una flecha.
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "COMO SE JUEGA" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << Yellow << "	->" << RESET << " Selecciona una casilla para capturarla." << endl;
	cout << Yellow << "	->" << RESET << " Captura 3 casillas alineadas para ganar." << endl;
	cout << Yellow << "	->" << RESET << " Evita que tu adversario conquiste 3 casillas alineadas." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "CONSEJOS" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << Yellow << "	->" << RESET << " Capturar la casilla del centro al principio suele ser la mejor estrategia." << endl;
	cout << Yellow << "	->" << RESET << " Si el centro ya esta ocupado, opta por una de las esquinas." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "CONTROLES" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << PURPURA << "	[Flechas direccionales]" << RESET << " 	Mover cursor." << endl;
	cout << PURPURA << "		[Enter]" << RESET << " 		Seleccionar." << endl;
	cout << PURPURA << "		  [G]" << RESET << "			Guardar partida." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << "	Presione cualquier tecla para volver al menu." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	_getch();
}
