/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:04:59 by marvin            #+#    #+#             */
/*   Updated: 2021/12/17 15:20:57 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon){
	this->_name = name;
}

HumanA::~HumanA(){
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

std::string HumanA::getName(void)const{
	return(this->_name);
}

void HumanA::setName(std::string name){
	this->_name = name;
}