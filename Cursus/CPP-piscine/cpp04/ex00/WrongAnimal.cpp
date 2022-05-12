/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:20:34 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:24:22 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	_type = "Wrong Animal";
	std::cout << _type << " is born" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	this->_type = copy.getType();
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << _type << " is dead" << std::endl;
}

std::string const &WrongAnimal::getType() const{
	return this->_type;
}

void WrongAnimal::makeSound() const{
	std::cout << "Animal Animal!" << std::endl;
}