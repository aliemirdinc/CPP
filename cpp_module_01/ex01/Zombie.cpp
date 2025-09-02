#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie( void ) {
	std::cout << name << " has been destroyed" << std::endl;
}

Zombie::Zombie() {
    this->name = "";
}

void Zombie::announce( void ) {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
