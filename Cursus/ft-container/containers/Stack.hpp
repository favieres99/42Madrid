/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:55:54 by gfaviere          #+#    #+#             */
/*   Updated: 2022/04/06 01:56:00 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"

namespace ft
{
	template <class T,class Container = ft::vector<T> > 
	class stack
	{
		public:
			//typedef
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
			typedef  typename ft::vector<T>::iterator iterator;

			//member functions
			explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {};

			bool empty() const {return _c.empty();}

			size_type size() const {return _c.size();}

			value_type& top() {return _c.back();}
			const value_type& top() const {return _c.back();}

			void push (const value_type& val) {_c.push_back(val);}

			void pop() {_c.pop_back();}

			//Friend for overloading
			template <class A, class B>
			friend bool operator==(const stack<A,B> &lhs, const stack<A,B> &rhs);
			template <class A, class B>
			friend bool operator!=(const stack<A,B> &lhs, const stack<A,B> &rhs);
			template <class A, class B>
			friend bool operator<(const stack<A,B> &lhs, const stack<A,B> &rhs);
			template <class A, class B>
			friend bool operator<=(const stack<A,B> &lhs, const stack<A,B> &rhs);
			template <class A, class B>
			friend bool operator>(const stack<A,B> &lhs, const stack<A,B> &rhs);
			template <class A, class B>
			friend bool operator>=(const stack<A,B> &lhs, const stack<A,B> &rhs);

		protected:
			container_type _c;
	};
	template <class T, class Container>
	bool operator==(const stack<T,Container> &lhs, const stack<T,Container> &rhs) { return lhs._c == rhs._c; }

	template <class T, class Container>
	bool operator!=(const stack<T,Container> &lhs, const stack<T,Container> &rhs) { return lhs._c != rhs._c; }

	template <class T, class Container>
	bool operator<(const stack<T,Container> &lhs, const stack<T,Container> &rhs) { return lhs._c < rhs._c; }

	template <class T, class Container>
	bool operator<=(const stack<T,Container> &lhs, const stack<T,Container> &rhs) { return lhs._c <= rhs._c; }

	template <class T, class Container>
	bool operator>(const stack<T,Container> &lhs, const stack<T,Container> &rhs) { return lhs._c > rhs._c; }

	template <class T, class Container>
	bool operator>=(const stack<T,Container> &lhs, const stack<T,Container> &rhs) { return lhs._c >= rhs._c; }
}