/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:17:06 by aldinc            #+#    #+#             */
/*   Updated: 2025/12/06 17:52:32 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_FORM
# define PRE_FORM
# include "AForm.hpp"
class PresidentialPardonForm : public AForm {
private:
    std::string _target;
    void beExecuted(void) const;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();

};

#endif
