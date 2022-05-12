/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:12 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/11 17:06:30 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b("gfaviere", 10);
	try
	{
		b.increaseGrade(9);
		std::cout << b << std::endl;
		b.increaseGrade(1);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Form formA("a", 10, 10);
	Form formB("b", 10, 10);
	b.signForm(formA);
	b.decreasedGrade(10);
	b.signForm(formB);
//	std::cout << formA << std::endl;
//	std::cout << formB << std::endl;
	return 0;
}