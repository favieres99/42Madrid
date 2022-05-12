/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:31:24 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/01 15:50:13 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	private:
	public:
		ScavTrap();
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &other);
		void attack(std::string const &target);
		void guardGate();
};

#endif