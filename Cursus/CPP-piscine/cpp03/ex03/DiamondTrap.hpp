/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:50:44 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/01 16:12:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &other);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &other);
		void attack(std::string const &target);
		void whoAmI();
};

#endif