#include "Turno.h"

Turno::Turno() {
  nTurn = 1;
  nPlayer = 1;
  nPlace = 1;
  nRoll = 1;
  nTileC = 'N';
  nMove = 2;
}

Turno::Turno(int t, int py, int plc, int r, char tl, int m) {
  nTurn = t;
  nPlayer = py;
  nPlace = plc;
  nRoll = r;
  nTileC = tl;
  nMove = m;
}

int Turno::getNTurn(){
  return nTurn;
}

int Turno::getNPlayer(){
  return nPlayer;
}

int Turno::getNPlace(){
  return nPlace;
}

int Turno::getNRoll(){
  return nRoll;
}

char Turno::getNTileC(){
  return nTileC;
}

int Turno::getNMove(){
  return nMove;
}

void Turno::setNTurn(int tt){
  nTurn = tt;
}

void Turno::setNPlayer(int pyy){
  nPlayer = pyy;
}

void Turno::setNPlace(int pll){
  nPlace = pll;
}

void Turno::setNRoll(int rr){
  nRoll = rr;
}

void Turno::setNTileC(char tileChar){
  nTileC = tileChar;
}

void Turno::setNMove(int mm){
  nMove = mm;
}
