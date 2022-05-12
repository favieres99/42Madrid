/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:51:37 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/17 15:17:11 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::Zombie(std::string name){
	this->_name = name;
}

Zombie::~Zombie(){
	std::cout << this->_name << " Even more dead" << std::endl;
}

void	Zombie::announce(void)const{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(std::string name){
	this->_name = name;
}