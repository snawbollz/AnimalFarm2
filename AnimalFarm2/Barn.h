#pragma once

#include <vector>
#include "Chicken.h"
#include "Cow.h"
#include "Horse.h"
#include "Animal.h"

#ifndef BARN_H
#define BARN_H

class Barn {
private:
	Animal* myAnimals[15];
	int numAnimals = sizeof(myAnimals) / sizeof(Animal*);
public:
	Barn();
	void feedAnimals();
	void outToPasture(int i);
	~Barn();

};
#endif // !BARN_H

Barn::~Barn() {
	for (int i = 0; i < numAnimals; i++) {
		delete myAnimals[i];
	}
}

Barn::Barn() {
	myAnimals[0] = new Cow("New cow", 50, 50);

	myAnimals[1] = new Chicken("Joe", 5, 5);
	myAnimals[2] = new Chicken("Big John", 17.75, 30);

	myAnimals[3] = new Cow("Fsteak", 20, 100);
	myAnimals[4] = new Cow("Cheese", 19.10, 85.5);

	myAnimals[5] = new Horse("Juan", 40, 200);
	myAnimals[6] = new Horse("Trent", 45.25, 210.5);
	myAnimals[7] = new Horse("Shawn", 40, 100);

	myAnimals[8] = new Cow("Milk", 90, 190.5);
	myAnimals[9] = new Cow("test", 110, 85.5);

	myAnimals[10] = new Chicken("Small John", 17.75, 30);
	myAnimals[11] = new Chicken("Medium John", 17.75, 30);

	myAnimals[12] = new Horse("Mustang", 20, 75);
	myAnimals[13] = new Horse("Mustang", 20, 75);

	myAnimals[14] = new Cow("Thicc", 20, 120);
}

void Barn::feedAnimals()
{
	for (int i = 0; i < sizeof(myAnimals)/sizeof(Animal*); i++) {
		myAnimals[i]->speak();
		std::cout << "\n";
		myAnimals[i]->eat();
		std::cout<<"\n";

		if (myAnimals[i]->getWeight() >= myAnimals[i]->getTopWeight()) {
			outToPasture(i);
		}
	}

}

void Barn::outToPasture(int i) 
{
	std::cout << myAnimals[i]->getName() << " has exceeded the top weight of " << myAnimals[i]->getTopWeight() << "\n";
	std::cout << myAnimals[i]->getName() << " the " << myAnimals[i]->getType() << "is output pasture, and has been replace with ";

	Cow* CowPTR = dynamic_cast<Cow*> (myAnimals[i]);
	if (CowPTR != nullptr)
	{
		delete myAnimals[i];
		myAnimals[i] = new Cow("McDonalds", 500, 50);
		std::cout << myAnimals[i]->getName() << "\n";
		return;
	}

	Chicken* ChickPTR = dynamic_cast<Chicken*> (myAnimals[i]);
	if (ChickPTR != nullptr)
	{
		delete myAnimals[i];
		myAnimals[i] = new Chicken("Eggward", 100, 10);
		std::cout << myAnimals[i]->getName() << "\n";
		return;
	}

	Horse* HorsePTR = dynamic_cast<Horse*> (myAnimals[i]);
	if (HorsePTR != nullptr)
	{
		delete myAnimals[i];
		myAnimals[i] = new Horse("Apollo", 750, 80);
		std::cout << myAnimals[i]->getName() << "\n";
		return;
	}
	std::cout << "\n";
}

/*

void Barn::feedChickens() {
	for (int i = 0; i < coop.size(); i++) {
		coop[i].eat();
		std::cout << "\n";
	}
}

void Barn::feedCows() {
	for (int i = 0; i < pen.size(); i++) {
		pen[i].eat();
		std::cout << "\n";
	}
}

void Barn::feedHorses() {
	for (int i = 0; i < stalls.size(); i++) {
		stalls[i].eat();
		std::cout << "\n";
	}
}
*/