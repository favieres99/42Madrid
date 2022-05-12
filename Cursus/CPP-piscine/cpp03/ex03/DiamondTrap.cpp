/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:55:59 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/01 16:03:45 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(){
	std::cout << "DiamondTrap(void)" << std::endl;
	this->_name = "default";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(){
	std::cout << "DiamondTrap(" << name << ")" << std::endl;
	this->_name = name;
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap(" << this->_name << ") was destroyed!" << std::endl;
}

void DiamondTrap::attack(std::string const &target){
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << ClapTrap::getName() << std::endl;
}