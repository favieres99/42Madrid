/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:03:23 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 12:06:40 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice &other) : AMateria(other){}

Ice &Ice::operator=(const Ice &other){
	this->AMateria::operator=(other);
	return (*this);
}

Ice::~Ice(){}

AMateria *Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
	this->AMateria::use(target);
}