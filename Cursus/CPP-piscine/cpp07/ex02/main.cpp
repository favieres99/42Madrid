/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:00:18 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 19:38:35 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void){
	Array<std::string> array(5);
	for (int i = 0; i < 5; i++){
		array[i] = std::string("Hello" + std::to_string(i));
	}
	for (int i = 0; i < 5; i++){
		std::cout << array[i] << std::endl;
	}
	Array<std::string> array2;
	array2 = array;
	for (int i = 0; i < 5; i++){
		std::cout << array2[i] << std::endl;
	}
	return (0);
}