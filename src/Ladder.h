#ifndef LADDER_H_INCLUDED
#define LADDER_H_INCLUDED
#include "Tile.h"

class Ladder:public Tile{
protected:
  int reward;

public:
  Ladder();
  Ladder(int, char, int);
  int special();
};

#endif
