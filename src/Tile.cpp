#include "Tile.h"

Tile::Tile(){
  place = 0;
  letter = 'N';
}

Tile::Tile(int nPlace, char nLetter){
  place = nPlace;
  letter = nLetter;
}

int Tile::getPlace(){
  return place;
}

char Tile::getLetter(){
  return letter;
}

int Tile::special(){
  return 0;
}

//Esta es la definición de la sobrecarga del operador +
//Dependiendo si la casilla es una serpiente, una escalera, o normal, se hace
//la operación adecuada para retroceder o avanzar posiciones.
int operator+ (Tile& mTile, Turno& mTurno) {
  int fposition;
  if(mTile.getLetter()=='S'){
    fposition=(mTurno.getNMove())-(mTile.special());
  } else {
    fposition=(mTurno.getNMove())+(mTile.special());
  }
  return fposition;
}
