/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:55:19 by marvin            #+#    #+#             */
/*   Updated: 2021/12/13 19:55:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string type){
	this->_type = type;
}

Weapon::~Weapon(){
}

std::string Weapon::getType(void)const{
	return (this->_type);
}

void Weapon::setType(std::string type){
	this->_type = type;
}