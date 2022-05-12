/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:03:07 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/15 11:59:01 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(void)
{
	Data horacio;

	horacio.name = "Horacio";
	horacio.age = 21;
	uintptr_t out = serialize(&horacio);
	Data *data = deserialize(out);
	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Age: " << data->age << std::endl;
}