/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:51 by gfaviere          #+#    #+#             */
/*   Updated: 2021/12/10 18:32:58 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	return;
}

Contact::~Contact(){
	return;
}

void	Contact::setAttributes(){
	std::string	buf;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, this->_f_name);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, this->_l_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Enter phone: ";
	std::getline(std::cin, this->_phone);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->_darkest_secret);
}

void	Contact::printAttributes(){
	std::cout << "First Name: ";
	std::cout << this->_f_name << std::endl;
	std::cout << "Last Name: ";
	std::cout << this->_l_name << std::endl;
	std::cout << "Nickname: ";
	std::cout << this->_nickname << std::endl;
	std::cout << "Phone: ";
	std::cout << this->_phone << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << this->_darkest_secret << std::endl;
}

std::string	Contact::getFirstName(){
	return (this->_f_name);
}

std::string	Contact::getLastName(){
	return (this->_l_name);
}

std::string	Contact::getNickname(){
	return (this->_nickname);
}

std::string	Contact::getPhone(){
	return (this->_phone);
}

std::string	Contact::getDarkestSecret(){
	return (this->_darkest_secret);
}