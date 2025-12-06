/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:17:06 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:42:25 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBO_FORM
# define ROBO_FORM
# include "AForm.hpp"
class RobotomyRequestForm : public AForm {
private:
    std::string _target;
    void beExecuted(void) const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

};

#endif
