/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:17:43 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:20:12 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){}

Dog::~Dog(){}

Dog::Dog(Dog const &other) : Animal(other){}

Dog &Dog::operator=(Dog const &other){
	this->Animal::operator=(other);
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Wof-Wof!" << std::endl;
}