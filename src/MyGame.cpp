//Se incluyen las clases necesarias para el juego
#include "MyGame.h"
#include "RandomNumber.h"
#include <stdlib.h>
#include <string.h>

//Se crea la excepción que manejará los inputs del usuario
class InvalidOptionException:public exception {
public:
  virtual string wrongOption(int track) const throw(){
    if(track < 5){
      return "Invalid option, please press C to continue next turn, or E to end the game: ";
    } else {
      return "Invalid menu choice exceeded.";
    }
  }
} ivdOption;

//Constructor vacío/default
MyGame::MyGame(){
  tiles = 30;
  snakes = 3;
  ladders = 3;
  penalty = 3;
  reward = 3;
  players = 2;
  turns = 20;
  gameType = 'M';
}

//Constructor con parámetros
MyGame::MyGame(int aTiles, int aSnakes, int aLadders, int aPenalty, int aReward, int aPlayers, int aTurns, char aGameType){
  tiles = aTiles;
  snakes = aSnakes;
  ladders = aLadders;
  penalty = aPenalty;
  reward = aReward;
  players = aPlayers;
  turns = aTurns;
  gameType = aGameType;
}

//Método que contiene la mecánica del juego
void MyGame::start(){
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
  char startC;
  int cTurn = 1;
  int place = 1;
  RandomNumber roll;
  int dice;
  int indexMove;
  char charIndex;
  int finalPlace = 1;

//Se crean los objetos tipo Jugador
  Turno *people[players];
  for(int i = 0; i < players; i++){
    Turno * p1 = new Turno(1,i+1,1,1,'N',2);
    people[i] = p1;
  }

  int counter = 0;
  //Se pide al usuario la indicación para iniciar el juego
  cout << "Press C to continue next turn, or E to end the game: ";

  do{
    //Se valida el input del usuario con un 'try'
    try{
      cin >> startC;
      //Si el input no es válido, se lanza la excepción
      if(cin.fail() || (startC != 'C' && startC != 'E') && counter <= 5) {
        counter++;
        throw ivdOption;
      }
    }

    //dependiendo de los intentos del usuario, se muestra un mensaje o se termina el juego
    catch(InvalidOptionException& errorL){
      cerr << errorL.wrongOption(counter) << endl;
      if(counter >= 5){
        cout << "--GAME OVER--" << endl;
        exit(1);
      }
    }

  } while (startC != 'C' && startC != 'E' && counter < 5);

  if(startC == 'E'){
    if(cTurn < turns && finalPlace < tiles){
      cout << "Thanks for playing!" << endl;
      exit(1);
    }
  }


  do {
    //Mensaje de fin del juego
    counter = 0;
    //Se genera la información de cada jugador por cada turno
    for(int i = 0; i < players; i++){
      //se 'gira' el dado
      dice = roll.generateRN();
      //Se establecen los atributos del jugador para cada turno
      people[i] -> setNTurn(cTurn);
      people[i] -> setNRoll(dice);
      indexMove = people[i] -> getNPlace() + dice;
      people[i] -> setNMove(indexMove);
      //Se asigna la letra correspondiente a la casilla donde el jugador cae
      //y se asigna el lugar donde quedará el jugador
      if(indexMove > tiles){
        charIndex = tablero[tiles] -> getLetter();
        people[i] -> setNMove(tiles);
      } else {
        charIndex = tablero[indexMove] -> getLetter();
        //Aquí se usa la sobrecarga del operador +
        people[i] -> setNMove(*tablero[indexMove]+*people[i]);
      }
      people[i] -> setNTileC(charIndex);

      finalPlace = people[i] -> getNMove();

      //Se establecen y evalúan las condiciones para finalizar el juego y asignar al ganador
      if(finalPlace >= tiles){
        people[i] -> setNTileC('N');
        people[i] -> setNMove(tiles);
        //Se usa la sobrecarga del operador << para imprimir en pantalla la información del turno actual
        cout << *people[i];
        cout << endl;
        //Se notifica si algún jugador llegó a la última casilla
        cout << "Player " << people[i] -> getNPlayer() << " is the winner!!" << endl;
        startC = 'E';
        break;
      } else {
        cout << *people[i];
        cTurn ++;
      }
      people[i] -> setNPlace(finalPlace);

      //Se termina el juego si los turnos se completan
      if(cTurn == turns + 1){
        cout << "The maximum number of turns has been reached." << endl;
        startC = 'E';
        break;
      } else {
        do{
          try{
            cin >> startC;
            if(cin.fail() || (startC != 'C' && startC != 'E') && counter <= 5) {
              counter++;
              throw ivdOption;
            }
          }

          catch(InvalidOptionException& errorL){
            cerr << errorL.wrongOption(counter) << endl;
            if(counter >= 5){
              cout << "--GAME OVER--" << endl;
              exit(1);
            }
          }

        } while (startC != 'C' && startC != 'E' && counter < 5);

        if(startC == 'E'){
          if(cTurn < turns && finalPlace < tiles){
            cout << "Thanks for playing!" << endl;
            break;
          } else {
            cout << "--GAME OVER--" << endl << endl;
            break;
          }
        }
      }
    }
  } while(finalPlace <= tiles && cTurn <= turns && startC == 'C' && counter < 5);
}//start
