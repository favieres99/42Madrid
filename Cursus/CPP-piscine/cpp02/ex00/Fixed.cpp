/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:38:17 by marvin            #+#    #+#             */
/*   Updated: 2021/12/16 19:38:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed (const Fixed &fixed){
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(fixed);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &fixed){
	std::cout << "Assignation operator called" << std::endl;
	this->_raw = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits ( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits ( int raw) {
	this->_raw = raw;
}