/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:09:23 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/13 16:00:09 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** CONSTRUCTOR --------------------------------
*/

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

/*
** DESTRUCTOR --------------------------------
*/

Intern::~Intern() {
}

/*
** OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

/*
** HELPER FUNCTIONS -----------------------------
*/

AForm* Intern::makeShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

/*
** MEMBER FUNCTIONS -----------------------------
*/

const char* Intern::FormNotFoundException::what() const throw() {
    return "Intern Error: Form name not found!";
}

AForm* Intern::makeForm(std::string name, std::string target) {

    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*funcs[])(std::string) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*funcs[i])(target);
        }
    }

    throw FormNotFoundException();
}