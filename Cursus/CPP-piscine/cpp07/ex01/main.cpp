/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:00:18 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 19:24:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void print_string(std::string &str){
	std::cout << str << std::endl;
}

void print_something(Something &something){
	std::cout << something << std::endl;
}

int main(void){
	std::string strs[] = {"Hello", "World", "gfaviere", "42Madrid!"};
	iter(strs, sizeof(strs) / sizeof(std::string), print_string);
	Something somethings[] = {
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
	};
	iter(somethings, sizeof(somethings) / sizeof(Something), print_something);
}