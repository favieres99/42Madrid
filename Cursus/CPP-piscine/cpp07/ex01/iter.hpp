/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:06:28 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 19:24:06 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

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

template <typename T>
void iter(T *lst, size_t len, void (*f)(T &)){
	for (size_t i = 0; i < len; i++){
		f(lst[i]);
	}
}

#endif