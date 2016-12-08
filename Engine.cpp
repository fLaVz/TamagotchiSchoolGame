#include "Engine.h"

using namespace std;

Engine::Engine() {

	m_gameState = "INIT";

}

void Engine::setGameState(string gameState) {

	m_gameState = gameState;

}

string Engine::getGameState() {

	return m_gameState;
}


Engine::loadGame() {

	
}