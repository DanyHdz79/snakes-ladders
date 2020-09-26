// TC1030.1 Programación orientada a objetos
// Tarea 4: manejo de excepciones
// Daniela Hernández y Hernández  A01730397

//Se incluyen las clases que contienes las características y funcionamiento del juego
#include "MyGame.cpp"
#include "MyGameAuto.cpp"
#include <exception>


class InvalidConfigurationException:public exception {
public:
  virtual string wrongConfig(string x, int s) const throw(){
    string s1 = to_string(s);
    return "Invalid " + x + " value " + s1;
  }
} invalid;


int main() {
  //Se declaran las variables del juego
  int numTiles, numSnakes, numLadders, numPenalty, numReward, numPlayers, numTurns;
  char charGameType;
  string pName;
  int pValue;

  //Se inicializa el 'seed' para random
  srand (time(NULL));

  //Se piden al usuario las características del juego y se almacenan en las variables

  try {
    cout << endl << "Snakes & Ladders" << endl;
    cout << "Customize your game!" << endl;

    cout << "Number of tiles: ";
    cin >> numTiles;
    if(cin.fail() || numTiles < 4){
      pName = "tiles";
      pValue = numTiles;
      throw invalid;
    }

    cout << "Number of snakes: ";
    cin >> numSnakes;
    if(cin.fail() || (numSnakes < 0) || (numSnakes > (numTiles*0.2))){
      pName = "snakes";
      pValue = numSnakes;
      throw invalid;
    }

    cout << "Number of ladders: ";
    cin >> numLadders;
    if(cin.fail() || (numLadders < 0) || numLadders > (numTiles*0.2)){
      pName = "ladders";
      pValue = numLadders;
      throw invalid;
    }

    cout << "Penalty of the snake: ";
    cin >> numPenalty;
    if(cin.fail() || numPenalty < 1 || (numPenalty > (numTiles*0.2))){
      pName = "penalty";
      pValue = numPenalty;
      throw invalid;
    }

    cout << "Reward of the ladder: ";
    cin >> numReward;
    if(cin.fail() || numReward < 1 || (numReward > (numTiles*0.2))){
      pName = "reward";
      pValue = numReward;
      throw invalid;
    }

    cout << "Number of players: ";
    cin >> numPlayers;
    if(cin.fail() || numPlayers < 2){
      pName = "players";
      pValue = numPlayers;
      throw invalid;
    }

    cout << "Maximum number of turns: ";
    cin >> numTurns;
    if(cin.fail() || numTurns < 1){
      pName = "turns";
      pValue = numTurns;
      throw invalid;
    }

    cout << "Game type (enter M for manual or A for automatic): ";
    cin >> charGameType;
    cout << endl;
    if(cin.fail() || (charGameType != 'M' && charGameType != 'A')){
      pName = "game type";
      pValue = charGameType;
      throw invalid;
    }
  }

  catch (InvalidConfigurationException& inv) {
    cout << endl << "------- " << inv.wrongConfig(pName, pValue) << " -------" << endl << endl;
    return 1;
  }


  if(charGameType == 'M'){
    //Se crea el objeto MyGame con las caracteríticas dadas
    MyGame play(numTiles, numSnakes, numLadders, numPenalty, numReward, numPlayers, numTurns, charGameType);
    //Se llama al método start(), que contiene la mecánica del juego
    play.start();
  } else {
    MyGameAuto play(numTiles, numSnakes, numLadders, numPenalty, numReward, numPlayers, numTurns, charGameType);
    //Se llama al método start(), que contiene la mecánica del juego
    play.start();
  }

  return 0;
}
