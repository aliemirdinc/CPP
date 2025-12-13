/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:58:54 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/13 13:11:35 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(0));

    std::cout << "\n========== TEST 1: SHRUBBERY CREATION ==========\n" << std::endl;
    try {
        Bureaucrat  gardener("Bahcivan Ali", 137);
        ShrubberyCreationForm shrub("Home");

        std::cout << shrub << std::endl;
        

        gardener.executeForm(shrub); 

        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        
        std::cout << "\n(Check for 'Home_shrubbery' file now!)" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 2: ROBOTOMY REQUEST ==========\n" << std::endl;
    try {
        Bureaucrat  tech("Teknisyen Veli", 45);
        RobotomyRequestForm robo("Bender");

        std::cout << robo << std::endl;

        tech.signForm(robo);
        
        std::cout << "--- Attempt 1 ---" << std::endl;
        tech.executeForm(robo);
        std::cout << "--- Attempt 2 ---" << std::endl;
        tech.executeForm(robo);
        std::cout << "--- Attempt 3 ---" << std::endl;
        tech.executeForm(robo);
        std::cout << "--- Attempt 4 ---" << std::endl;
        tech.executeForm(robo);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 3: PRESIDENTIAL PARDON ==========\n" << std::endl;
    try {
        Bureaucrat  baskan("Baskan", 5);
        Bureaucrat  stajyer("Stajyer", 150);
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << pardon << std::endl;

        stajyer.signForm(pardon);

        baskan.signForm(pardon);
        
        baskan.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 4: INTERN (EX03) ==========\n" << std::endl;
    try {
        Intern  someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;

        std::cout << "Trying to create invalid form..." << std::endl;
        rrf = someRandomIntern.makeForm("coffee request", "Boss");
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n" << std::endl;

    return 0;
}
