/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:17:18 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 16:30:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form{
	private:
		ShrubberyCreationForm() : Form("", "", 42, 42){};
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();
		void action(Bureaucrat const &executor) const;
		static Form *create(std::string const &target);
};

#define TREE_ASCII_ART "\
  ,d                                      \n\
  88                                      \n\
MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  \n\
  88    88P'   'Y8 a8P_____88 a8P_____88  \n\
  88    88         8PP''''''' 8PP'''''''  \n\
  88,   88         '8b,   ,aa '8b,   ,aa  \n\
  'Y888 88          `'Ybbd8'´  `'Ybbd8'´\n\
"

#endif