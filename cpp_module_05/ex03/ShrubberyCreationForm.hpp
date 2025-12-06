/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:17:06 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:26:40 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUB_FORM
# define SHRUB_FORM
# include "AForm.hpp"
class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
    void beExecuted(void) const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

};

#endif
