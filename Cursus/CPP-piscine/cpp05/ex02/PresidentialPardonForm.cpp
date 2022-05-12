/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:27:59 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 18:31:56 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(target, "PresidentialPardonForm", 72, 45){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
	this->Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action(Bureaucrat const &executer) const{
	this->Form::execute(executer);
	std::cout << "The " << this->getTarget() << " has been pardoned by " << executer.getName() << "." << std::endl;
}