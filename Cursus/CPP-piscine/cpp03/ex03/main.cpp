/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:15:27 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/01 16:13:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap hello("Horacio");
	hello.attack("Fernando");
	hello.takeDamage(100);
	hello.beRepaired(3);
	hello.highFivesGuys();
	hello.guardGate();
	hello.whoAmI();
}