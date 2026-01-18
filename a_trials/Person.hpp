#ifndef PERSON
# define PERSON
#include <string>
#include <iostream>

class Person {
	private:
		std::string name;
		int yas;
		int boy;
		int kilo;
	public:
		Person(const std::string &name, const int &yas, const int &boy, const int &kilo);
		Person(const Person &a);
		Person &operator=(const Person &other);
		~Person();
		void WhoAreYou(Person &name);
	protected:
	
	
};
#endif