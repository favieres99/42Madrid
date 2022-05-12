/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:37:27 by marvin            #+#    #+#             */
/*   Updated: 2021/12/27 18:58:41 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <math.h>

class Fixed{

	private:
		static const int	_bitFractional = 8;
		int					_raw;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const float raw);
		Fixed(const int raw);
		~Fixed();
		Fixed&	operator = (const Fixed &fixed);
		Fixed	operator++ ();
		Fixed	operator++ (int i);
		Fixed	operator-- ();
		Fixed	operator-- (int i);
		Fixed	operator+ (const Fixed &obj);
		Fixed	operator- (const Fixed &obj);
		Fixed	operator* (const Fixed &obj);
		Fixed	operator/ (const Fixed &obj);
		static Fixed	const &min(Fixed const &a, Fixed const &b);
		static Fixed	const &max(Fixed const &a, Fixed const &b);
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		bool	operator> (const Fixed &obj)const;
		bool	operator< (const Fixed &obj)const;
		bool	operator>= (const Fixed &obj)const;
		bool	operator<= (const Fixed &obj)const;
		bool	operator== (const Fixed &obj)const;
		bool	operator!= (const Fixed &obj)const;
		void	setRawBits(int const raw);
		int		getRawBits(void)const;
		int		toInt(void)const;
		float	toFloat(void)const;
};

std::ostream& operator << (std::ostream &o, const Fixed &obj);

#endif