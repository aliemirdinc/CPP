/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:53:28 by aldinc            #+#    #+#             */
/*   Updated: 2025/11/05 18:16:31 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {
private:
	const std::string   _name;
	bool                _isSigned;
	const int           _gradeToSign;
	const int           _gradeToExecute;

public:
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	Form(const std::string name, int gradeToSign, int gradeToExecute);

	std::string getName() const;
	bool        getIsSigned() const;
	int         getGradeToSign() const;
	int         getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif