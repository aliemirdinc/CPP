#include "Person.hpp"

Person::Person(const std::string &name, const int &yas, const int &boy, const int &kilo) : name(name), yas(yas), boy(boy), kilo(kilo) {
	std::cout << "the person "<< this->name << " created" << std::endl;

}

Person::Person(const Person &a) {
	this->name = a.name;
	this->boy = a.boy;
	this->kilo = a.kilo;
	this->yas = a.yas;
	std::cout << "now person " << a.name << " has a copy" << std::endl;
}

Person &Person::operator=(const Person &other) {
	if (this != &other) {
		this->name = other.name;
		this->boy = other.boy;
		this->kilo = other.kilo;
		this->yas = other.yas;
	}
	return *this;
}

Person::~Person() {
	std::cout << "destructor called" << std::endl;
}
