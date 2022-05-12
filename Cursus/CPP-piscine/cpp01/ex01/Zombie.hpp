/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:43:28 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 22:08:45 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie{

	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void	announce(void)const;
		void	SetName(std::string name);
};

Zombie*	newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif