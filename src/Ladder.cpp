#include "Ladder.h"

Ladder::Ladder(){
  reward = 0;
}

Ladder::Ladder(int nPlace, char nLetter, int nReward):Tile(nPlace, nLetter){
  reward = nReward;
}

int Ladder::special(){
  return reward;
}
