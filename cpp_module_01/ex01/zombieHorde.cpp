#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	if (N <= 0)
		return NULL;
	Zombie *Zombos = new Zombie[N];
	for (int i = 0; i < N; i++)
		Zombos[i].setName(name);
	return Zombos;
}
