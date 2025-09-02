#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty()) {
        std::cerr << "Error: String to replace cannot be empty" << std::endl;
        return 1;
    }
    
    Sed sed(filename, s1, s2);
    if (!sed.replace())
        return 1;
    
    std::cout << "Successfully replaced all occurrences of '" << s1 
              << "' with '" << s2 << "' in file '" << filename << "'" << std::endl;
    std::cout << "Output written to '" << filename << ".replace'" << std::endl;
    
    return 0;
}
