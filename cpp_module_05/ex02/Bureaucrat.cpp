/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:51:29 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:56:41 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor Called: " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat Constructor Called" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << this->_name << "'s grade has been incremented, old grade is: " << this->_grade;
    this->_grade--;
    std::cout << ", updated grade is: " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << this->_name << "'s grade has been decremented, old grade is: " << this->_grade;
    this->_grade++;
    std::cout << ", updated grade is: " << this->_grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& Aform) const
{

    try
    {
        Aform.beSigned(*this);
        std::cout << this->_name << " signed " << Aform.getName() << std::endl;
    }
    catch (std::exception & e)
    {

        std::cout << this->_name << " couldn't sign " << Aform.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << this->_name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
