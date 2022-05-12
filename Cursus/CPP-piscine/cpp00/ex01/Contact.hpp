/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:12:42 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 18:32:29 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <string>
# include <iostream>

class Contact {

	private:
		std::string	_f_name;
		std::string	_l_name;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkest_secret;

	public:
		Contact();
		~Contact();
		void	setAttributes();
		void	printAttributes();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhone();
		std::string	getDarkestSecret();
};

#endif