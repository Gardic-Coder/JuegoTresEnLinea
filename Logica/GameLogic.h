// Logica/GameLogic.h
#pragma once
#include <array>
#include <string>
#include <algorithm>
#include <conio.h> // Para detectar las teclas presionadas en sistemas Windows 
#include <iostream>
#include <vector>
#include "../Presentacion/GameUI.h"

class Casilla {
private:
    int estado; // 0 = libre, 1 = jugador 1, 2 = jugador 2
    int posicion;
    int numeroJugada;
    bool cursor;

public:
	Casilla(int pos) : estado(0), posicion(pos), numeroJugada(-1), cursor(false) {} 
	
	int getEstado() const { return estado; } 
	void setEstado(int e, int jugada) { estado = e; numeroJugada = jugada; } 
	int getPosicion() const { return posicion; } 
	int getNumeroJugada() const { return numeroJugada; } 
	void setCursor(bool c) { cursor = c; } 
	bool getCursor() const { return cursor; }
};

class Tablero {
private:
    std::array<std::array<Casilla, 3>, 3> casillas;
public:
    Tablero();
    
    Casilla& getCasilla(int fila, int columna);
    bool verificarGanador(int jugador) const;
    void actualizarCursor(int fila, int columna, bool c);
};

class Jugador {
private:
    std::string nombre;
    std::array<Casilla*, 3> casillasConquistadas;
    int numConquistadas;

public:
    Jugador(const std::string& nom) : nombre(nom), numConquistadas(0) {}
    
    void conquistarCasilla(Casilla* casilla); 
	void eliminarCasilla(); 
	const std::array<Casilla*, 3>& getCasillasConquistadas() const; 
	std::string getNombre() const;
};

class ControladorJuego { 
private: 
	Tablero* tablero; 
	Jugador* jugador1; 
	Jugador* jugador2;  
	int turnos;
	
public: 
	ControladorJuego(Tablero* t, Jugador* j1, Jugador* j2); 
	~ControladorJuego();
	void moverCursor(int& cursor, std::vector<std::string> opcionesMenu, Tecla tecla);
	void moverCursor(int& fila, int& columna, Tecla tecla);
	
    int getTurnos() const;
};

