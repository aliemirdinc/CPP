/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:53:12 by aldinc            #+#    #+#             */
/*   Updated: 2025/11/05 17:43:48 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Test 1: Valid Creation ---" << std::endl;
    try
    {
        Bureaucrat b1("Arthur", 42);
        std::cout << b1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too High (Creation) ---" << std::endl;
    try
    {
        Bureaucrat b2("Ford", 0);
        std::cout << b2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade Too Low (Creation) ---" << std::endl;
    try
    {
        Bureaucrat b3("Zaphod", 151);
        std::cout << b3 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Valid Increment/Decrement ---" << std::endl;
    try
    {
        Bureaucrat b4("Trillian", 5);
        std::cout << "Initial: " << b4 << std::endl;
        
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
        
        b4.decrementGrade();
        std::cout << "After decrement: " << b4 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Increment Too High ---" << std::endl;
    try
    {
        Bureaucrat b5("Marvin", 1);
        std::cout << b5 << std::endl;
        b5.incrementGrade();
        std::cout << "This line should not be reached." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 6: Decrement Too Low ---" << std::endl;
    try
    {
        Bureaucrat b6("Slartibartfast", 150);
        std::cout << b6 << std::endl;
        b6.decrementGrade();
        std::cout << "This line should not be reached." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 7: OCF Tests ---" << std::endl;
    Bureaucrat b7("Eddie", 75);
    std::cout << "Original b7: " << b7 << std::endl;

    Bureaucrat b8(b7);
    std::cout << "Copy b8(b7): " << b8 << std::endl;

    Bureaucrat b9("Deep Thought", 1);
    std::cout << "Original b9: " << b9 << std::endl;
    
    b9 = b7;
    std::cout << "Assigned b9 = b7: " << b9 << std::endl;
    std::cout << "(Note: Name 'Deep Thought' should remain due to const _name)" << std::endl;


    std::cout << "\n--- All tests finished ---" << std::endl;
    return 0;
}
