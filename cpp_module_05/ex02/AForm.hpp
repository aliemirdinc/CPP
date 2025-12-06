/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:53:28 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:02:26 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string   _name;
	bool                _isSigned;
	const int           _gradeToSign;
	const int           _gradeToExecute;

public:
	AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	AForm(const std::string name, int gradeToSign, int gradeToExecute);

	std::string getName() const;
	bool        getIsSigned() const;
	int         getGradeToSign() const;
	int         getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);
	void execute(Bureaucrat const & executor) const;
	
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

protected:
		virtual void beExecuted(void) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif