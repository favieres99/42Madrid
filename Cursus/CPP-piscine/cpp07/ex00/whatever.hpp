/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:51:42 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:59:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T &min(T &a, T &b){
	return (a < b) ? a : b;
}

template <typename T>
T &max(T &a, T &b){
	return (a > b) ? a : b;
}

class Something{
	private:
		int _value;
	public:
		Something(int const &value){
			this->_value = value;
		};
		Something(Something const &other){
			*this = other;
		}
		Something &operator=(Something const &other){
			if (this != &other){
				this->_value = other._value;
			}
			return *this;
		}
		~Something(){};
		bool operator<(Something const &other) const{
			return (this->_value < other._value);
		}
		bool operator>(Something const &other) const{
			return (this->_value > other._value);
		}
		int getValue() const{
			return this->_value;
		};
};

std::ostream &operator<<(std::ostream &os, Something const &something){
	os << something.getValue();
	return os;
}

#endif