/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:21:33 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:25:24 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base{
	private:
	public:
		C(){};
		C(C const &other){
			*this = other;
		};
		C &operator=(C const &other){
			if (this != &other){
				Base::operator=(other);
			}
			return *this;
		};
		~C(){};
};

#endif