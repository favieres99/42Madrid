/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:19:15 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:21:19 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base{
	private:
	public:
		Base(){};
		Base(Base const &other){
			*this = other;
		};
		Base &operator=(Base const &other){
			if (this != &other){
				/* Something */
			}
			return *this;
		};
		virtual ~Base(){};
};

#endif