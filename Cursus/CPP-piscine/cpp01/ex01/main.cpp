/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:07:15 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 22:07:25 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int	n = 5;

	Zombie *horde = zombieHorde(n, "Walking dead");
	if (!horde)
	{
		std::cout << "Error creating horde" << std::endl;
		return EXIT_FAILURE;
	}
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete []horde;
	return EXIT_SUCCESS;
}