/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:43:39 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/13 16:43:42 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** ORTHODOX CANONICAL AForm --------------------------------
*/

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(const AForm& other) 
    : _name(other._name), 
      _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), 
      _gradeToExecute(other._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

AForm::~AForm() {
}

/*
** MAIN CONSTRUCTOR ----------------------------------
*/

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), 
      _isSigned(false), 
      _gradeToSign(gradeToSign), 
      _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

/*
** GETTERS -------------------------------------------
*/

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

/*
** MEMBER FUNCTIONS ----------------------------------
*/

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

/*
** EXCEPTION CLASSES ---------------------------------
*/

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm Error: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm Error: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm Error: Form is not signed!";
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->_isSigned)
        throw FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    this->beExecuted();
}

/*
** OPERATOR OVERLOAD ---------------------------------
*/

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm: " << f.getName() 
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return (os);
}
