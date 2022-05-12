/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:20:25 by marvin            #+#    #+#             */
/*   Updated: 2021/12/14 18:20:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(){
}

HumanB::HumanB(std::string name){
	this->_name = name;
}

HumanB::~HumanB(){
}

void HumanB::attack(void){
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setType(std::string name){
	this->_name = name;
}

std::string HumanB::getType(void)const{
	return (this->_name);
}

void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}