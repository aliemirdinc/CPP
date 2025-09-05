/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:30:00 by aldinc            #+#    #+#             */
/*   Updated: 2025/09/05 12:11:38 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria " << type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    // According to subject: "copying the type doesn't make sense"
    // So we don't copy the type
    (void)other;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria " << type << " destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria use called on " << target.getName() << std::endl;
}
