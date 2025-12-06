/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:09:21 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 18:18:57 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class Intern {
    private:
        AForm* makeShrubbery(std::string target);
        AForm* makeRobotomy(std::string target);
        AForm* makePresidential(std::string target);

    public:
        Intern();
        Intern(const Intern& other);
        Intern &operator=(const Intern& other);
        virtual ~Intern();
    
        AForm* makeForm(std::string name, std::string target);

        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif
