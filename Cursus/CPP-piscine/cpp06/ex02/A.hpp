/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:21:33 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:23:43 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base{
	private:
	public:
		A(){};
		A(A const &other){
			*this = other;
		};
		A &operator=(A const &other){
			if (this != &other){
				Base::operator=(other);
			}
			return *this;
		};
		~A(){};
};

#endif