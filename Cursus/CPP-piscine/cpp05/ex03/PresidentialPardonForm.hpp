/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:10:47 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 16:29:24 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form{
	private:
		PresidentialPardonForm() : Form("", "", 42, 42){};
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		void action(Bureaucrat const &executor) const;
		static Form *create(std::string const &target);
};

#endif