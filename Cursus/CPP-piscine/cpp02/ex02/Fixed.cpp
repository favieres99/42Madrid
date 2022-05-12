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
	this->_raw = fixed.getRawBits();
	return ( *this );
}

std::ostream& operator<< (std::ostream &o, const Fixed &obj){
	o << obj.toFloat();
	return (o);
}

Fixed Fixed::operator++ (){
	this->_raw++;
	return ( *this );
}

Fixed Fixed::operator++ (int i){
	Fixed tmp(*this);
	(void)i;
	this->operator++();
	return (tmp);
}

Fixed Fixed::operator-- (){
	this->_raw--;
	return (*this);
}

Fixed Fixed::operator-- (int i){
	Fixed tmp(*this);
	(void)i;
	this->operator--();
	return (tmp);
}

Fixed	Fixed::operator+ (const Fixed &obj)  {
	this->setRawBits(this->getRawBits() + obj.getRawBits());
	return (*this);
}

Fixed	Fixed::operator- (const Fixed &obj){
	this->setRawBits(this->getRawBits() - obj.getRawBits());
	return (*this);
}

Fixed Fixed::operator* (Fixed const &obj){
	Fixed tmp(*this);
	long aux1, aux2;
	aux1 = ((long)this->getRawBits());
	aux2 = ((long)obj.getRawBits());
	tmp.setRawBits((aux1 * aux2) / (1 << this->_bitFractional));
	return ( tmp );
}

Fixed Fixed::operator/ (Fixed const &obj)
{
	Fixed tmp(*this);
	long aux1, aux2;
	aux1 = ((long)this->getRawBits());
	aux2 = ((long)obj.getRawBits());
	tmp.setRawBits((aux1 * (1 << this->_bitFractional)) / aux2);
	return (tmp);
}

bool Fixed::operator > (const Fixed &obj) const{
	return ((this->_raw > obj.getRawBits()));
}

bool Fixed::operator < (const Fixed &obj) const{
	return ((this->_raw < obj.getRawBits()));
}

bool Fixed::operator == (const Fixed &obj) const{
	return ((this->_raw == obj.getRawBits()));
}

bool Fixed::operator >= (const Fixed &obj) const{
	return ((this->_raw >= obj.getRawBits()));
}

bool Fixed::operator <= (const Fixed &obj) const{
	return ((this->_raw <= obj.getRawBits()));
}

bool Fixed::operator != ( const Fixed &obj ) const{
	return ((this->_raw != obj.getRawBits()));
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b){
	if (a > b)
		return (b);
	return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a > b)
		return (b);
	return (a);
}

Fixed const &min(Fixed const &a, Fixed const &b){
	return (Fixed::min(a, b));
}

Fixed &min(Fixed &a, Fixed &b){
	return (Fixed::min(a, b));
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b){
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	return (b);
}

Fixed const &max(Fixed const &a, Fixed const &b){
	return (Fixed::max(a, b));
}

Fixed &max(Fixed &a, Fixed &b){
	return (Fixed::max(a, b));
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