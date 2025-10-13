/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:02:40 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/19 18:19:37 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	public:
		const std::string name;
		int grade;
		
		Bureaucrat();
		Bureaucrat(const Bureaucrat& a);
		Bureaucrat &operator=(const Bureaucrat& other);
		Bureaucrat &operator<<(const Bureaucrat& other);
		~Bureaucrat();
		
		void GradeTooHighException();
		void GradeTooLowException();

		int getGrade() const;
		void getName() const;
};


#endif