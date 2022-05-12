/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:53:06 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:17:31 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){}

Cat::~Cat(){}

Cat::Cat(Cat const &other) : Animal(other){}

Cat &Cat::operator=(Cat const &other){
	this->Animal::operator=(other);
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}