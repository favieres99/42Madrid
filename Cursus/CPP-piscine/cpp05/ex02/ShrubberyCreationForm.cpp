/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:36:02 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 18:40:30 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(target, "ShrubberyCreationForm", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::action(Bureaucrat const &executer) const{
	this->Form::execute(executer);
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (file.is_open() == false)
		throw std::ofstream::failure("Could not open file " + this->getTarget() + "_shrubbery");
	file << TREE_ASCII_ART;
}