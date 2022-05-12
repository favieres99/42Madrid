/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:15:36 by marvin            #+#    #+#             */
/*   Updated: 2021/12/14 19:15:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char *argv[]){
	Karen karen;

	if (argc == 2)
		karen.complain(argv[1]);
	else
		std::cout << "Options: INFO, WARNING, DEBUG, ERROR" << std::endl;
	return (0);
}