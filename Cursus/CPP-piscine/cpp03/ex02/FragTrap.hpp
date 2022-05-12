/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:47:32 by gfaviere          #+#    #+#             */
/*   Updated: 2022/01/17 21:50:21 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	private:
	public:
		FragTrap();
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		~FragTrap();
		FragTrap &operator=(FragTrap const &other);
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys();
};

#endif