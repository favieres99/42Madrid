/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:49:12 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/02 16:16:49 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap::ClapTrap(void)" << std::endl;
	this->_name = "default";
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

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap::operator=(other)" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const &target){
	std::cout << this->_name << " attacks "
			  << target << ", causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "You(" << this->_name << ") take " << amount << " damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << "You(" << this->_name << ") be repaired " << amount << " hit points!" << std::endl;
	this->_hitPoints += amount;
}

std::string ClapTrap::getName() const{
	return this->_name;
}

unsigned int ClapTrap::getHitPoints() const{
	return this->_hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const{
	return this->_energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const{
	return this->_attackDamage;
}

void ClapTrap::setHitPoints(unsigned int hitPoints){
	this->_hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints){
	this->_energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage){
	this->_attackDamage = attackDamage;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap(" << this->_name << ") was destroyed!" << std::endl;
}