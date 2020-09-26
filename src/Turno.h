#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
#include <iostream>
using namespace std;

class Turno{
protected:
  int nTurn, nPlayer, nPlace, nRoll, nMove;
  char nTileC;

public:
  Turno();
  Turno(int, int, int, int, char, int);

  int getNTurn();
  int getNPlayer();
  int getNPlace();
  int getNRoll();
  char getNTileC();
  int getNMove();

  void setNTurn(int);
  void setNPlayer(int);
  void setNPlace(int);
  void setNRoll(int);
  void setNTileC(char);
  void setNMove(int);

  friend ostream & operator << (ostream &out, const Turno &t);
};

//Aquí se hace la sobrecarga del operador << que imprime todos los atributos de
//esta clase en el formato especificado.
ostream & operator << (ostream &out, const Turno &t) {
    out << t.nTurn << " " << t.nPlayer << " " << t.nPlace << " " << t.nRoll << " " << t.nTileC << " " << t.nMove << endl;
    return out;
}

#endif
