/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:32:13 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 18:35:44 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, "RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::action(Bureaucrat const &executer) const{
	this->Form::execute(executer);
	std::cout << "\a";
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " is a robot!\n";
	else
		std::cout << this->getTarget() << " is human!\n";
}