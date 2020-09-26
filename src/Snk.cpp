#include "Snk.h"

Snk::Snk(){
  penalty = 0;
}

Snk::Snk(int nPlace, char nLetter, int nPenalty):Tile(nPlace, nLetter){
  penalty = nPenalty;
}

int Snk::special(){
  return penalty;
}
