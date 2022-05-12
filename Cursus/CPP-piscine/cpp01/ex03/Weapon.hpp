/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:54:05 by marvin            #+#    #+#             */
/*   Updated: 2021/12/13 19:54:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon{

	private:
		std::string _type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string getType(void)const;
		void setType(std::string type);
};
#endif