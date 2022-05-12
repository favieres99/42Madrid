/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:26:48 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/15 10:09:48 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
		Bureaucrat() : _name(""){}
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void increaseGrade(int amount);
		void decreasedGrade(int amount);
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw()
				{
					return ("Grade too low");
				}
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif