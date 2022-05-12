/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:21:33 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:24:30 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base{
	private:
	public:
		B(){};
		B(B const &other){
			*this = other;
		};
		B &operator=(B const &other){
			if (this != &other){
				Base::operator=(other);
			}
			return *this;
		};
		~B(){};
};

#endif