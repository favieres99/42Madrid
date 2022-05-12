/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:33:39 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 10:26:53 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap(void)" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name){
	std::cout << "ScavTrap(" << name << ")" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other){}

ScavTrap &ScavTrap::operator=(ScavTrap const &other){
	ClapTrap::operator=(other);
	return (*this);
}

void ScavTrap::attack(std::string const &target){
	std::cout << "ScavTrap:: ";
	this->ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount){
	std::cout << "ScavTrap:: ";
	this->ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount){
	std::cout << "ScavTrap:: ";
	this->ClapTrap::beRepaired(amount);
}

void ScavTrap::guardGate(){
	std::cout << "Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap(" << this->getName() << ") was destroyed!" << std::endl;
}