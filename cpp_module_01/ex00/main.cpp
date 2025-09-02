#include "Zombie.hpp"

int main () {
	Zombie* the_heap_zombie = newZombie("heap zombie");
	the_heap_zombie->announce();
	delete the_heap_zombie;

	randomChump("Ali");

}