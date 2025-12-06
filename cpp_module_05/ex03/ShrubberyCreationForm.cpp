/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:26:48 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:34:12 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::beExecuted(void) const {
    std::string fileName = this->_target + "_shrubbery";

    std::ofstream outfile(fileName.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << fileName << std::endl;
        return;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile << "Target: " << this->_target << std::endl;

    outfile.close();
}