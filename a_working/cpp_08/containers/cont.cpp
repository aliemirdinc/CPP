#include <vector>
#include <iostream>
#include <algorithm>

int main(void) {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec[2] << std::endl;
    std::cout << vec[3] << std::endl;
    std::cout << *(vec.end()-1) << std::endl;
    std::cout << *vec.end() << std::endl;
}
