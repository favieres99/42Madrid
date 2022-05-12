/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:32:24 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 12:23:08 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(const Cure &other) : AMateria(other){}

Cure &Cure::operator=(const Cure &other){
	this->AMateria::operator=(other);
	return (*this);
}

Cure::~Cure(){}

AMateria *Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	this->AMateria::use(target);
}