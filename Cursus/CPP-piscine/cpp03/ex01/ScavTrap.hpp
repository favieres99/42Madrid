/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:31:24 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 10:26:45 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &other);
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ScavTrap &operator=(ScavTrap const &other);
		void guardGate();
		~ScavTrap();
};

#endif