#pragma once
#include "Animal.h"
#ifndef CHICKEN_H
#define CHICKEN_H

class Chicken : public Animal {
private:
	void gainWeight();
public:
	Chicken();
	Chicken(std::string n, double h, double w);
	void eat();
	void speak();
	double getTopWeight();
	std::string getType();
};
#endif // !COW_H

void Chicken::gainWeight() {
	double tempW = 0.0;
	tempW = Animal::getWeight();
	tempW = tempW + .25;
	Animal::setWeight(tempW);
	std::cout << Animal::getName() + " the Chicken gained .25 pounds." << "\n";
}

Chicken::Chicken() {
	Animal::setName("");
	Animal::setHeight(0.0);
	Animal::setWeight(0.0);
}

Chicken::Chicken(std::string n, double h, double w) {
	Animal::setName(n);
	Animal::setHeight(h);
	Animal::setWeight(w);
}

void Chicken::eat() {
	std::cout << Animal::getName() + " is eating... \n";
	gainWeight();
	std::cout << Animal::getName() + " now weighs " << getWeight() << " pounds.\n";
}

void Chicken::speak() {
	std::cout << "Cluck!";
}

double Chicken::getTopWeight() {
	return 20;
}

inline std::string Chicken::getType()
{
	return "Chicken";
}
