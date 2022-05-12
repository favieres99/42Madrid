/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:44:38 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 18:27:29 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>

class Bureaucrat;

class Form{
	private:
		const std::string _target;
		const std::string _name;
		bool _sign;
		const int _signGrade;
		const int _execGrade;
		Form() : _target(""), _name(""), _signGrade(42), _execGrade(42){};
	public:
		Form(std::string const &target, std::string const &name, int signGrade, int execGrade);
		Form(Form const &other);
		Form &operator=(Form const &other);
		virtual ~Form();
		std::string getTarget() const;
		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void action(Bureaucrat const &executor) const = 0;
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw()
				{
					return ("Grade too low");
				}
		};
		class NotSignedException : public std::exception{
			public:
				const char *what() const throw()
				{
					return ("Not Signed");
				}
		};
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif