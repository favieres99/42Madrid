/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:30:23 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 19:33:51 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Intern{
	private:
	public:
		Intern(){}
		Intern(Intern const &){}
		Intern &operator=(Intern const &)
		{
			return *this;
		}
		~Intern(){}
		Form *makeForm(std::string const &formName, std::string const &target);
		class NotKnownFormException : public std::exception{
			public:
				const char *what() const throw()
				{
					return ("Intern can`t create NotKnownForm");
				}
		};
};

#endif