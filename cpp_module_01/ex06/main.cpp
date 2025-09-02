#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl harl;

	if (argc != 2)
		return 1;

	int levelIndex = -1;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == argv[1])
			levelIndex = i;
	}
	
	switch (levelIndex) {
    case 0:
        harl.complain("DEBUG");
		// fall through
    case 1:
        harl.complain("INFO");
		// fall through
    case 2:
        harl.complain("WARNING");
		// fall through
    case 3:
        harl.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
	}

}