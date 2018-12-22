#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//Fighter in the ring
class Gladiator {
private:
	int dmgMin,//The lowest amount of damage a gladiator can inflict with a successful attack
		dmgRange,//The most damage ABOVE Minimum Damage that the gladiator can inflict with a single, non-critical hit
		evasion, //The % chance (0-100) that the gladiator will completely avoid incoming damage when defending
		critical,//The % chance (0-100) that the gladiator will inflict twice (2x) the rolled damage when attacking the opponent (known as a crit)
		maxHealth,//The amount of HP a gladiator will start each fight with
		curHealth;//The amount of HP a gladiator has left before they have died and lost the fight
public:
	//How the gladiator is referenced to the user, provided somehow in the constructor
	std::string name;

	//Called upon creation; prevent any uninitialized values from being available
	Gladiator();//Constructor
				//Use this to obtain all information on our gladiators, including their name.
				//Confirmation of the created gladiator is permitted but NOT required.

	//Accessor for health
	int getCurHealth();

	//Calculates a damage roll based on dmgMin, dmgRange, and crit
	//This would be a good place to display a crit notification
	int rollDamage();

	//Displays gladiator's stats, in one or two lines so it's pleasing in a list
	void display();//you're responsible for defining this function

	//Hint: Evasion should be calculated here
	bool takeDamage(int dmgAmt);//Returns whether the gladiator was killed by the damage or not
};




//Most simple function, so it's defined here to show syntax you'll be using

int Gladiator::getCurHealth()

{

  return curHealth;

}



Gladiator::Gladiator()

{

  //Note: static helps with optimization, only one instance of names is created, reused when appropriate

  static std::string names[10] = { "Alfred", "Bob", "Charles", "David", "Evan", "Fred", "George", "Hector", "Irene", "Jeff" };

  name = names[rand() % 10];

  curHealth = maxHealth = 150 + rand() % 3 * 50;//150,200,250

  evasion = 5 + rand() % 3 * 5;//5,10,15

  critical = 5 + rand() % 3 * 5;//5,10,15

  dmgMin = 8 + rand() % 7;//8-14

  dmgRange = 16 + rand() % 7;//16-22

}



int Gladiator::rollDamage()

{

  int dmg = rand() % (dmgRange + 1);//roll base damage

  if (rand() % 100 < critical)//allow for critical hits

  {

    std::cout << "Critical hit!\n";

    dmg *= 2;

  }

  return dmg;

}



void Gladiator::display()

{

  std::cout << name << ":\nHealth: " << curHealth << '/' << maxHealth <<

    "\nEvasion: " << evasion << "\nCritical: " << critical <<

    "\nDamage: " << dmgMin << '-' << dmgMin + dmgRange + 1 << "\n\n";

}



bool Gladiator::takeDamage(int dmgAmt)

{

  if (rand() % 100 < evasion)//allow for critical hits

  {

    std::cout << "Hit evaded!\n";

    dmgAmt = 0;

  }

    //-= to update variable, and use it in the expression "health < 0"

    //if gladiator has died, will return true. Will return false otherwise.

  return (curHealth -= dmgAmt) <= 0;

}


// Function that takes 2 vectors of Gladiators and attacks to random people in second vector.
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
