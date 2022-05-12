/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:51:07 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/01 16:10:39 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap(void)" << std::endl;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name){
	std::cout << "FragTrap (" << name << ")" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other){
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap(" << this->getName() << ") was destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other){
	ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::attack(std::string const &target){
	std::cout << "FragTrap:: ";
	this->ClapTrap::attack(target);
}

void FragTrap::highFivesGuys(void){
	std::cout << "HighFivesGuys" << std::endl;
}