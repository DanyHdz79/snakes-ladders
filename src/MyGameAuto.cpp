#include "MyGameAuto.h"

MyGameAuto::MyGameAuto(){}
MyGameAuto::MyGameAuto(int aTiles, int aSnakes, int aLadders, int aPenalty,
  int aReward, int aPlayers, int aTurns, char aGameType):
  MyGame(aTiles, aSnakes, aLadders, aPenalty, aReward, aPlayers, aTurns, aGameType){}

void MyGameAuto::start(){
  //--------------------------------- tablero --------------------------------------------------
  //Se generan los arreglos de números aleatorios que indicarán en qué casilla
  //estarán las serpientes o escaleras dependiendo de los límites del tablero.
    int randomBankS[snakes];
    for(int i = 0; i < snakes; i++){
      RandomNumber * r1 = new RandomNumber(penalty+2,tiles);
      randomBankS[i] = r1 -> generateRN();
    }

    int randomBankL[ladders];
    for(int i = 0; i < ladders; i++){
      RandomNumber * r2 = new RandomNumber(1,tiles-reward);
      randomBankL[i] = r2 -> generateRN();
    }

  //Se crea el tablero con un arreglo de objetos tipo casilla
    Tile *tablero[tiles];
    for(int i = 0; i <= tiles; i++){
      Tile * t1 = new Tile(i, 'N');
      tablero[i] = t1;
    }

  //Se colocan las serpientes y escaleras en el lugar aleatorio correspondiente
    for(int i = 0; i <= tiles; i++) {
      for(int j = 0; j < snakes; j++){
        if(i+1 == randomBankS[j]){
          Tile * t1 = new Snk(i, 'S', penalty);
          tablero[i] = t1;
        }
      }
    }

    for(int i = 0; i <= tiles; i++) {
      for(int j = 0; j < ladders; j++){
        if(i+1 == randomBankL[j]){
          Tile * t1 = new Ladder(i, 'L', reward);
          tablero[i] = t1;
        }
      }
    }

  //--------------------------------- Juego -----------------------------------------------------
  // Se declaran las variables del juego
    int cTurn = 1;
    int place = 1;
    RandomNumber roll;
    int dice;
    int indexMove;
    char charIndex;
    int finalPlace = 1;
    bool finish = false;

  //Se crean los objetos tipo Jugador
    Turno *people[players];
    for(int i = 0; i < players; i++){
      Turno * p1 = new Turno(1,i+1,1,1,'N',2);
      people[i] = p1;
    }
  //Se repite el mecanismo de manual, pero en vez de esperar el input del usuario,
  //se usa un ciclo para recorrer los turnos hasta que un jugador gane o los turnos se completen.
  while(cTurn <= turns && finish == false){
    for(int i = 0; i < players; i++){
      dice = roll.generateRN();
      people[i] -> setNTurn(cTurn);
      people[i] -> setNRoll(dice);

      indexMove = people[i] -> getNPlace() + dice;
      people[i] -> setNMove(indexMove);

      if(indexMove > tiles){
        charIndex = tablero[tiles] -> getLetter();
        people[i] -> setNMove(tiles);
      } else {
        charIndex = tablero[indexMove] -> getLetter();
        people[i] -> setNMove(*tablero[indexMove]+*people[i]);
      }

      people[i] -> setNTileC(charIndex);

      finalPlace = people[i] -> getNMove();
      if(finalPlace >= tiles){
        people[i] -> setNMove(tiles);
        cout << *people[i];
        cout << endl;
        cout << "Player " << people[i] -> getNPlayer() << " is the winner!!" << endl;
        finish = true;
        break;
      } else {
        cout << *people[i];
        cTurn ++;
        people[i] -> setNPlace(finalPlace);
        if(cTurn == turns + 1){
          cout << "The maximum number of turns has been reached." << endl;
          finish = true;
          break;
        }
      }
    }

    if(finish == true){
      if(cTurn == turns && finalPlace < tiles){
        cout << "Thanks for playing!" << endl;
        break;
      } else {
        cout << "--GAME OVER--" << endl << endl;
        break;
      }
    }
  }
}
