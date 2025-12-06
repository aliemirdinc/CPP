/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:26:48 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:34:12 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::beExecuted(void) const {
    std::cout << "* BZZZZZT! WRRRRRRR! (Drilling noises) *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << this->_target << "!" << std::endl;
    }
}
