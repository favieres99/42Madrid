/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:49:12 by gfaviere          #+#    #+#             */
/*   Updated: 2022/01/17 21:27:22 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap::ClapTrap(void)" << std::endl;
	this->_name = nullptr;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const &name){
	std::cout << "ClapTrap::ClapTrap(" << name << ")" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "ClapTrap::ClapTrap(other)" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap(" << this->_name << ") was destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap::operator=(other)" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	return (*this);
}

void ClapTrap::attack(std::string const & target){
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << this->_name << " take " << amount << " damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << this->_name << " repaired " << amount << " hit points!" << std::endl;
	this->_hitPoints += amount;
}