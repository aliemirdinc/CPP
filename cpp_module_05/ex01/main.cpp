/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:54:55 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 16:34:05 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    // --- Test 1: Valid Form Creation ---
    std::cout << "--- Test 1: Valid Form Creation ---" << std::endl;
    try
    {
        Form f1("Form_A98", 50, 25);
        std::cout << f1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // --- Test 2: Invalid Form (Grade Too High) ---
    std::cout << "\n--- Test 2: Invalid Form (Grade Too High) ---" << std::endl;
    try
    {
        Form f2("Form_B7", 0, 25);
        std::cout << f2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // --- Test 3: Invalid Form (Grade Too Low) ---
    std::cout << "\n--- Test 3: Invalid Form (Grade Too Low) ---" << std::endl;
    try
    {
        Form f3("Form_C22", 50, 151);
        std::cout << f3 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // --- Test 4: Bureaucrat Signs Form (Success) ---
    std::cout << "\n--- Test 4: Bureaucrat Signs Form (Success) ---" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 40);
        Form f4("TaxForm_101", 50, 20);
        
        std::cout << b1 << std::endl;
        std::cout << f4 << std::endl;
        
        b1.signForm(f4);
        
        std::cout << f4 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    // --- Test 5: Bureaucrat Fails to Sign (Grade Too Low) ---
    std::cout << "\n--- Test 5: Bureaucrat Fails to Sign (Grade Too Low) ---" << std::endl;
    try
    {
        Bureaucrat b2("Bob", 60);
        Form f5("SecretMemo_X", 50, 20);
        
        std::cout << b2 << std::endl;
        std::cout << f5 << std::endl;
        
        b2.signForm(f5);
        
        std::cout << f5 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }
    
    // --- Test 6: Bureaucrat Signs Form (Exact Grade) ---
    std::cout << "\n--- Test 6: Bureaucrat Signs Form (Exact Grade) ---" << std::endl;
    try
    {
        Bureaucrat b3("Charlie", 75);
        Form f6("PermissionSlip_Y", 75, 20);
        
        std::cout << b3 << std::endl;
        std::cout << f6 << std::endl;
        
        b3.signForm(f6);
        
        std::cout << f6 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "\n--- ex01 tests finished ---" << std::endl;
    return 0;
}