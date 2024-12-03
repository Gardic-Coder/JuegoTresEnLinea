#include "GameLogic.h" 

void Jugador::conquistarCasilla(Casilla* casilla){
	if (numConquistadas == 3) { 
		eliminarCasilla(); 
	} 
	
	casillasConquistadas[numConquistadas++] = casilla; 
	std::sort(casillasConquistadas.begin(), casillasConquistadas.begin() + numConquistadas, 
	[](Casilla* a, Casilla* b) { return a->getNumeroJugada() < b->getNumeroJugada(); });
}

void Jugador::eliminarCasilla(){
	if (numConquistadas > 0) { 
		casillasConquistadas[0]->setEstado(0, -1); 
		for (int i = 1; i < numConquistadas; ++i) { 
			casillasConquistadas[i - 1] = casillasConquistadas[i]; 
		} 
		--numConquistadas; 
	}
}

const std::array<Casilla*, 3>& Jugador::getCasillasConquistadas(){
	return casillasConquistadas;
}

std::string Jugador::getNombre(){
	return nombre;
}