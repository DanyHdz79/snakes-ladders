#ifndef MYGAMEAUTO_H_INCLUDED
#define MYGAMEAUTO_H_INCLUDED
#include "MyGame.h"

class MyGameAuto:public MyGame {
public:
MyGameAuto();
MyGameAuto(int, int, int, int, int, int, int, char);
void start();
};

#endif
