#ifndef TILES_H_INCLUDED
#define TILES_H_INCLUDED
#include <iostream>
#include "Turno.cpp"
using namespace std;

class Tile{
protected:
  int place;
  char letter;

public:
  Tile();
  Tile(int, char);
  int getPlace();
  char getLetter();
  virtual int special();

  //Aquí se declara la sobrecarga del operador +, que recibe un objeto tipo casilla
  //y un objeto de la clase turno, y regrresa un entero
  friend int operator+ (Tile& mTile, Turno& mTurno);
};

#endif
