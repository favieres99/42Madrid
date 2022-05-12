/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:53:30 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 15:58:40 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &target, std::string const &name, int signGrade, int execGrade) : _target(target), _name(name), _signGrade(signGrade), _execGrade(execGrade){}

Form::Form(Form const &other) : _target(other._target), _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()){
	this->_sign = other._sign;
}

Form &Form::operator=(Form const &other){
	this->_sign = other._sign;
	return (*this);
}

Form::~Form(){}

void Form::beSigned(Bureaucrat const &bureaucrat){
	if (bureaucrat.getGrade() > this->_execGrade)
		throw Form::GradeTooLowException();
	this->_sign = true;
}

std::string Form::getTarget() const{
	return (this->_target);
}

std::string Form::getName() const{
	return (this->_name);
}

bool Form::getSign() const{
	return (this->_sign);
}

int Form::getSignGrade() const{
	return (this->_signGrade);
}

int Form::getExecGrade() const{
	return (this->_execGrade);
}

void Form::execute(Bureaucrat const &executor) const{
	if (this->getSign() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &form){
	os << "<" << form.getName() << " sign: " << form.getSignGrade() << ", exec: " << form.getExecGrade();
	if (form.getSign())
		os << ", signed";
	else
		os << ", not signed";
	os << " >";
	return (os);
}