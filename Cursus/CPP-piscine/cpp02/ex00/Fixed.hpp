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

class Fixed{

	private:
		static const int	_bitFractional = 8;
		int					_raw;

	public:
		Fixed();
		Fixed( const Fixed &fixed );
		~Fixed();
		Fixed&	operator = (const Fixed &fixed );
		void	setRawBits( int raw );
		int		getRawBits( void ) const;
};

#endif