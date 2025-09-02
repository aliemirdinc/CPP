#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int i;
		std::string truncate(std::string str, size_t len);
		void displayContacts();

	public:
		PhoneBook();
		void ADD();
		void SEARCH();
		void EXIT();
};

#endif
