/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:13:32 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/07 18:16:31 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form{
	private:
		RobotomyRequestForm() : Form("", "", 42, 42){};
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm();
		void action(Bureaucrat const &executor) const;
};

#endif