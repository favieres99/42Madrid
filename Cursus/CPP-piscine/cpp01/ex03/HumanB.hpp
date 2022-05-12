/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:46:33 by marvin            #+#    #+#             */
/*   Updated: 2021/12/13 19:46:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB{

	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void setType(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void);
		std::string getType(void)const;
};

#endif