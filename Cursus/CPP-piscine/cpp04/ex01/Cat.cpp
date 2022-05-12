/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:53:06 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:53:53 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"){
	this->brain = new Brain();
}

Cat::~Cat(){
	delete this->brain;
}

Cat::Cat(Cat const &other) : Animal(other){
	this->brain = new Brain(*other.getBrain());
}

Cat &Cat::operator=(Cat const &other){
	if (this != &other)
	{
		this->~Cat();
		this->brain = new Brain(*other.getBrain());
		this->Animal::operator=(other);
	}
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const{
	return this->brain;
}