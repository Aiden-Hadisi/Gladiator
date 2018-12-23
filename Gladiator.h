#pragma once
#include <string>
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
	int rollDamage();

	//Displays gladiator's stats, in one or two lines so it's pleasing in a list
	void display();//you're responsible for defining this function

	
	bool takeDamage(int dmgAmt);//Returns whether the gladiator was killed by the damage or not
};
