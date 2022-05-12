/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:44:13 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 19:47:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

class OutOfRangeException : public std::exception{
	public:
		const char *what() const throw(){
			return "Out of range";
		}
};

template <class T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw OutOfRangeException();
	return it;
};

#endif