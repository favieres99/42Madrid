/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:07:02 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 22:12:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *horde;
	std::string tmp;
	if (N > 0)
	{
		horde = new Zombie[N];
		if (!horde)
			return (NULL);
		for (int i = 0; i < N; i++)
		{
			if (i > 0)
				tmp = tmp + std::to_string(i + 1);
			else
				tmp = name;
			horde[i].SetName(tmp);
		}
		return (horde);
	}
	return (NULL);
}