/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:58:54 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:59:06 by aldinc           ###   ########.fr       */
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

int main()
{
    // Robotomy için rastgelelik tohumu (Seed)
    std::srand(time(NULL));

    std::cout << "\n========== TEST 1: SHRUBBERY CREATION ==========\n" << std::endl;
    try {
        Bureaucrat  gardener("Bahcivan Ali", 137); // Hem imzalar hem çalıştırır
        ShrubberyCreationForm shrub("Home");

        std::cout << shrub << std::endl;
        
        // Önce imzalamadan çalıştırmayı dene (Hata vermeli)
        gardener.executeForm(shrub); 

        // İmzala ve çalıştır
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
        
        // %50 şansı görmek için birkaç kez çalıştıralım
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
        Bureaucrat  baskan("Baskan", 5); // En yetkili
        Bureaucrat  stajyer("Stajyer", 150); // Yetkisiz
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << pardon << std::endl;

        // Stajyer imzalamaya çalışsın (Hata)
        stajyer.signForm(pardon);

        // Başkan imzalasın
        baskan.signForm(pardon);
        
        // Başkan çalıştırsın
        baskan.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n" << std::endl;

    return 0;
}
