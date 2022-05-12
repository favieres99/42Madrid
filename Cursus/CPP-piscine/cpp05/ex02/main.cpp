/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:12 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 15:59:29 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_form(Form &form, Bureaucrat &correct, Bureaucrat &wrong)
{
	wrong.signForm(form);
	correct.executeForm(form);
	correct.signForm(form);
	wrong.executeForm(form);
	correct.executeForm(form);
}

int main()
{
	srand(time(NULL));

	Bureaucrat a("Horacio", 1);
	Bureaucrat b("Fernando", 150);

	ShrubberyCreationForm form1("target");
	RobotomyRequestForm form2("target");
	PresidentialPardonForm form3("target");
	test_form(form1, a, b);
	test_form(form2, a, b);
	test_form(form3, a, b);

	return 0;
}