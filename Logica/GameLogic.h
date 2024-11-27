// Logica/GameLogic.h
#pragma once
#include <array>
#include <string>
#include <algorithm>
#include <conio.h> // Para detectar las teclas presionadas en sistemas Windows 
#include <iostream>


class GameLogic {
public:
    void update();
};

class Casilla {
private:
    int estado; // 0 = libre, 1 = jugador 1, 2 = jugador 2
    int posicion;
    int numeroJugada;
    bool cursor;

public:
    Casilla(int pos);

    int getEstado() const { return estado; }
    void setEstado(int e, int jugada) { estado = e; numeroJugada = jugada; }
    int getPosicion() const { return posicion; }
    int getNumeroJugada() const { return numeroJugada; }
    void setCursor(bool c) { cursor = c; }
    bool getCursor() const { return cursor; }
};

class Tablero {
private:
    std::array<Casilla, 9> casillas;

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
    int victorias; 
	int derrotas;

public:
    Jugador(const std::string& nom);
    
    void conquistarCasilla(Casilla* casilla); 
	void eliminarCasilla(); 
	void limpiarCasillasConquistadas(); 
	const std::array<Casilla*, 3>& getCasillasConquistadas() const; 
	std::string getNombre() const; 
	void setNombre(const std::string& nom); 
	int getVictorias() const; 
	void setVictorias(int v); 
	int getDerrotas() const; 
	void setDerrotas(int d);
};

class GameController {
private: 
	Tablero& tablero;
	Jugador& jugador1; 
	Jugador& jugador2; 
	int fila; 
	int columna; 
	
public: 
	GameController(Tablero& tab, Jugador& j1, Jugador& j2); 
	
	void iniciarJuego(); 
	
private: 
	void moverCursor(int key); 
	void procesarEntrada();
};
