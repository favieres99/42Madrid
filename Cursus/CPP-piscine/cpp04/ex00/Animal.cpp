/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:33:42 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 10:52:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	this->_type = "Some animal";
	std::cout << "Born " << this->_type << std::endl;
}

Animal::Animal(std::string type){
	this->_type = type;
	std::cout << "Born " << this->_type << std::endl;
}

Animal::Animal(Animal const &other){
	*this = other;
}

Animal &Animal::operator=(Animal const &other){
	this->_type = other.getType();
	return (*this);
}

Animal::~Animal(){
	std::cout << "Die " << this->_type << std::endl;
}

std::string const &Animal::getType() const{
	return (this->_type);
}

void Animal::makeSound() const{
	std::cout << "Animal Animal!" << std::endl;
}