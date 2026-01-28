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
	
	it = std::find(lst.begin(), lst.end(), 3);

	std::cout << &it << std::endl;
	std::cout << *it << std::endl;

}
