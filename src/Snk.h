#ifndef SNK_H_INCLUDED
#define SNK_H_INCLUDED
#include "Tile.h"

class Snk:public Tile{
protected:
  int penalty;

public:
  Snk();
  Snk(int, char, int);
  int special();
};

#endif
