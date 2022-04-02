#pragma once
#include "Animal.h"
#ifndef COW_H
#define COW_H

class Cow : public Animal {
private:
	void gainWeight();
public:
	Cow();
	Cow(std::string n, double h, double w);
	void eat();
	void speak();
	double getTopWeight();
	std::string getType();
};
#endif // !COW_H

void Cow::gainWeight() {
	double tempW = 0.0;
	tempW = Animal::getWeight();
	tempW = tempW + 6;
	Animal::setWeight(tempW);
	std::cout << Animal::getName() + " the Cow gained 6 pounds." << "\n";
}

Cow::Cow() {
	Animal::setName("");
	Animal::setHeight(0.0);
	Animal::setWeight(0.0);
}

Cow::Cow(std::string n, double h, double w) {
	Animal::setName(n);
	Animal::setHeight(h);
	Animal::setWeight(w);
}

void Cow::eat() {
	std::cout << Animal::getName() + " is eating... \n";
	gainWeight();
	std::cout << Animal::getName() + " now weighs " << getWeight() << " pounds.\n";
}

void Cow::speak() {
	std::cout << "Moo!";
}

double Cow::getTopWeight() {
	return 1500;
}

inline std::string Cow::getType()
{
	return "Cow";
}
