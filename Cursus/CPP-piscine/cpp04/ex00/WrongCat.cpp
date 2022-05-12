/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:24:35 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:27:42 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	_type = "Wrong Cat";
	std::cout << _type << " is born" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy){
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
	this->WrongAnimal::operator=(copy);
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << _type << " is dead" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}