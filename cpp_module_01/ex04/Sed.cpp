#include "Sed.hpp"

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2)
{
}

Sed::~Sed()
{
}

std::string Sed::replaceInString(const std::string& line) const
{
    if (_s1.empty())
        return line;

    std::string result;
    size_t prev = 0;
    size_t pos;

    result.reserve(line.size());

    while ((pos = line.find(_s1, prev)) != std::string::npos)
    {
        result.append(line, prev, pos - prev);
        result += _s2;
        prev = pos + _s1.length();
    }
    result.append(line, prev, std::string::npos);
    return result;
}

bool Sed::replace()
{
    std::ifstream inputFile(_filename.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Could not open file '" << _filename << "'" << std::endl;
        return false;
    }

    std::string outputFilename = _filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Could not create output file '" << outputFilename << "'" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string replacedLine = replaceInString(line);
        bool eof_after_read = inputFile.eof();
        outputFile << replacedLine;
        if (!eof_after_read)
            outputFile << '\n';

        if (!outputFile)
        {
            std::cerr << "Error: Write failed to '" << outputFilename << "'" << std::endl;
            return false;
        }
    }

    if (inputFile.bad())
    {
        std::cerr << "Error: I/O error while reading '" << _filename << "'" << std::endl;
        return false;
    }

    return true;
}
