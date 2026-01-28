#include <list>
#include <iostream>
#include <algorithm>

int main(void) {
    std::list<int> lst;
    std::list<int>::iterator it;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    lst.push_back(60);

    it = lst.begin();
    for (size_t i = 0; i < 14; i++)
    {
        std::cout << *it << std::endl;
        it++;
    }


    // std::advance(it, 7);
    // std::cout << *it << std::endl;

}
