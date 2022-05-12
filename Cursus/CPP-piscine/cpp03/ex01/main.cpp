/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:15:27 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 10:26:32 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap hello("Horacio");
	hello.attack("Fernando");
	hello.takeDamage(100);
	hello.beRepaired(3);
	hello.guardGate();
}