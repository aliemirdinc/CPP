#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	i = 0;
}

void PhoneBook::ADD(void)
{
	PhoneBook book;

	std::string firstname, lastname, nickname, phonenumber, darkestsecret;

	std::cout << "First Name: ";
	getline(std::cin, firstname);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		book.EXIT();
	}
	std::cout << "Last Name: ";
	getline(std::cin, lastname);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		book.EXIT();
	}
	std::cout << "Nickname: ";
	getline(std::cin, nickname);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		book.EXIT();
	}
	std::cout << "Phone Number: ";
	getline(std::cin, phonenumber);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		book.EXIT();
	}
	std::cout << "Darkest Secret: ";
	getline(std::cin, darkestsecret);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		book.EXIT();
	}

	//no empty spaces
	if (firstname.empty() || lastname.empty() || nickname.empty() ||
		phonenumber.empty() || darkestsecret.empty())
	{
		std::cout << "Fields cannot be empty!" << std::endl;
		return ;
	}

	int idx = i % 8;
	this->contacts[idx].first_name = firstname;
	this->contacts[idx].last_name = lastname;
	this->contacts[idx].nick_name = nickname;
	this->contacts[idx].phone_number = phonenumber;
	this->contacts[idx].darkest_secret = darkestsecret;

	std::cout << "Contact added at index " << idx+1 << std::endl;
	i++;
}
std::string PhoneBook::truncate(std::string str, size_t len)
{
	if (str.length() > len) {
		str[len - 1] = '.';
		return str.substr(0, len);
	}
	return str;
}

void PhoneBook::displayContacts() {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	
	int max_contacts = (i > 8) ? 8 : i;
	for (int j = 0; j < max_contacts; j++) {
		std::cout << std::setw(10) << j + 1 << "|";
		std::cout << std::setw(10) << truncate(contacts[j].first_name, 10) << "|";
		std::cout << std::setw(10) << truncate(contacts[j].last_name, 10) << "|";
		std::cout << std::setw(10) << truncate(contacts[j].nick_name, 10) << std::endl;
	}
}

void PhoneBook::SEARCH(void) {
	if (i == 0) {
		std::cout << "No contacts available!" << std::endl;
		return;
	}
	
	displayContacts();
	
	std::cout << "Enter index: ";
	std::string input;
	getline(std::cin, input);
	
	int index = std::atoi(input.c_str()) - 1;
	int max_contacts;
	if (i > 8)
		max_contacts = 8;
	else
		max_contacts = i;

	if (index < 0 || index >= max_contacts)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}

	std::cout << "First Name: " << contacts[index].first_name << std::endl;
	std::cout << "Last Name: " << contacts[index].last_name << std::endl;
	std::cout << "Nickname: " << contacts[index].nick_name << std::endl;
	std::cout << "Phone Number: " << contacts[index].phone_number << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].darkest_secret << std::endl;
}

void PhoneBook::EXIT(void) {
	std::cout << "Goodbye!" << std::endl;
	exit(0);
}

int main()
{
	PhoneBook book;
	std::string line;
	
	std::cout << "Welcome to PhoneBook! Available commands: ADD, SEARCH, EXIT" << std::endl;
	
	while(1) {
		std::cout << "Enter command: ";
		getline(std::cin, line);
	
		if (line == "ADD") {
			book.ADD();
		}
		else if (line == "SEARCH") {
			book.SEARCH();
		}
		else if (line == "EXIT") {
			book.EXIT();
		}
		else if (std::cin.eof())
		{
			book.EXIT();
		}
		
		else if (!line.empty()) {
			std::cout << "Invalid command!" << std::endl;
		}
	
	}
	return 0;
}
