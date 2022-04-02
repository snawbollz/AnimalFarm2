#pragma once
#include <iostream>
#include "Animal.h"
#ifndef HORSE_H
#define HORSE_H

class Horse : public Animal {
private:
	void gainWeight();
public:
	Horse();
	Horse(std::string n, double w, double h);
	void eat();
	void speak();
	double getTopWeight();
	std::string getType();
};
#endif // !HORSE_H

void Horse::gainWeight() {
	double tempW = 0.0;
	tempW = Animal::getWeight();
	tempW = tempW + 6.75;
	Animal::setWeight(tempW);
	std::cout << Animal::getName() + " the Horse gained 6.75 pounds." << "\n";
}

Horse::Horse() {
	Animal::setName("");
	Animal::setHeight(0.0);
	Animal::setWeight(0.0);
}

Horse::Horse(std::string n, double w, double h) {
	Animal::setName(n);
	Animal::setHeight(h);
	Animal::setWeight(w);
}

void Horse::eat() {
	std::cout << Animal::getName() + " is eating... \n";
	gainWeight();
	std::cout << Animal::getName() + " now weighs " << getWeight() << " pounds.\n";
}

void Horse::speak() {
	std::cout << "Neigh!";
}

double Horse::getTopWeight() {
	return 1500;
}

std::string Horse::getType()
{
	return "Horse";
}
