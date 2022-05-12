/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:12 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 17:41:32 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
	Intern intern;
	Form *form;
	form = intern.makeForm("ShrubberyCreationForm", "target");
	test_form(*form, a, b);
	delete form;
	form = intern.makeForm("RobotomyRequestForm", "target");
	test_form(*form, a, b);
	delete form;
	form = intern.makeForm("PresidentialPardonForm", "target");
	test_form(*form, a, b);
	delete form;
	try
	{
		form = intern.makeForm("WrongName", "target");
		test_form(*form, a, b);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}