/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:38:17 by marvin            #+#    #+#             */
/*   Updated: 2021/12/27 18:58:58 by gfaviere         ###   ########.fr       */
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

Fixed::Fixed (const float raw) : _raw(round(raw * (1 << this->_bitFractional))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int raw) : _raw(round(raw * (1 << this->_bitFractional))){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &fixed){
	std::cout << "Assignation operator called" << std::endl;
	this->_raw = fixed.getRawBits();
	return ( *this );
}

std::ostream& operator<< (std::ostream &o, const Fixed &obj){
	o << obj.toFloat();
	return (o);
}

int Fixed::toInt (void) const{
	return (((int) this->_raw / (int)(1 << this->_bitFractional)));
}

float Fixed::toFloat (void) const{
	return (((float) this->_raw / (float)(1 << this->_bitFractional)));
}

int Fixed::getRawBits (void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits (int raw) {
	this->_raw = raw;
}