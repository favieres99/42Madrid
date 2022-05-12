/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:33:28 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 18:01:39 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name){
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name){
	this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::increaseGrade(int amount){
	if (this->_grade - amount <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade - amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade -= amount;
}

void Bureaucrat::decreasedGrade(int amount){
	if (this->_grade + amount <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += amount;
}

void Bureaucrat::signForm(Form &form){
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " cannot sign " << form << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat){
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (os);
}