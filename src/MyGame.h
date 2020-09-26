#ifndef MYGAME_H_INCLUDED
#define MYGAME_H_INCLUDED
#include "Tile.cpp"
#include "Snk.cpp"
#include "Ladder.cpp"

class MyGame {
protected:
  int tiles, snakes, ladders, penalty, reward, players, turns;
  char gameType;

public:
  MyGame();
  MyGame(int, int, int, int, int, int, int, char);
  virtual void start();
};

#endif
