#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class Sed
{
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

public:
    Sed(const std::string& filename, const std::string& s1, const std::string& s2);
    ~Sed();
    
    bool replace();
    std::string replaceInString(const std::string& line) const;
};

#endif