/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:37:27 by marvin            #+#    #+#             */
/*   Updated: 2021/12/16 19:37:27 by marvin           ###   ########.fr       */
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
		Fixed&	operator = (const Fixed &fixed );
		void	setRawBits( int raw );
		int		getRawBits( void ) const;
		int		toInt(void)const;
		float	toFloat(void)const;
};

std::ostream& operator << (std::ostream &o, const Fixed &obj);

#endif