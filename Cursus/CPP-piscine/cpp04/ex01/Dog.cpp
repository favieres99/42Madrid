/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:17:43 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:56:35 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"){
	this->brain = new Brain();
}

Dog::~Dog(){
	delete this->brain;
}

Dog::Dog(Dog const &other) : Animal(other){
	this->brain = new Brain(*other.getBrain());
}

Dog &Dog::operator=(Dog const &other){
	if (this != &other)
	{
		this->~Dog();
		this->brain = new Brain(*other.getBrain());
		this->Animal::operator=(other);
	}
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Wof-Wof!" << std::endl;
}

Brain *Dog::getBrain() const{
	return this->brain;
}