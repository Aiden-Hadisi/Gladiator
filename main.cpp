// Author: Aiden Hadisi
// CPSC 121
// 12/05/2018


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cctype>
#include "Gladiator.h"
#include "Gladiator.cpp"
using namespace std;


void attack(vector<Gladiator>&, vector<Gladiator>&);

int main() {
  char option;
  //create a vecotrs with 2 players
  vector<Gladiator> redTeam(2);
  vector<Gladiator> blueTeam(2);

  //Print number of players
  cout << "Number of fighters in red team: " << redTeam.size() << endl;
  cout << "Number of fighters in blue team: " << blueTeam.size() << endl;
  do {
    //Show menu
    cout << "Pick one of the options below: " << endl;
    cout << "a) Take turn." << endl;
    cout << "b) Add fighters." << endl;
    cout << "c) exit" << endl;
    cin >> option;
    option = tolower(option);
    if(option == 'a') {
      //Random variable to randomly select between red and blue
      int temp = rand() % 2;
      if(temp == 0) {
        cout << "Red team is attacking:" << endl;
        attack(redTeam, blueTeam);
      }
      else {
        cout << "Blue team is attacking:" << endl;
        attack(blueTeam, redTeam);
      }
    }

    else if(option == 'b') {
      //Create 2 gladiator: 1 for each team.
      cout << "Enter names for the figthers seperated by space: " << endl;
      string redName, blueName;
      cin >> redName >> blueName;
      Gladiator red;
      Gladiator blue;
      red.name = redName;
      blue.name = blueName;

      //Display their stats
      cout << "Stats of red Gladiator: " << endl;
      red.display();
      cout << "Stats of blue Gladiator: " << endl;
      blue.display();

      //Add them to vectors
      redTeam.push_back(red);
      blueTeam.push_back(blue);
    }
  }while(option != 'c');



  return 0;
}

void attack(vector<Gladiator>& a, vector<Gladiator>& b) {
  if(b.size() == 0) {
    cout << "All players in one of the teams are dead. Add more players to continue" << endl;
    return;
  }
  for(Gladiator g : a) {

  int temp = rand() % b.size();
  cout << g.name << " is attacking " << b[temp].name << endl;
  int damage = g.rollDamage();
  cout << "He deals " << damage << " damage." << endl;
  if(b[temp].takeDamage(damage)){
    cout << b[temp].name << " is killed." << endl;
    b.erase(b.begin() + temp);
  }
  cout << endl;
}
}
