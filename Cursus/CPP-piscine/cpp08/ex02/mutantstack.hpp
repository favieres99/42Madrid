/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:57:38 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 21:24:19 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		~MutantStack();
		MutantStack<T> &operator=(MutantStack<T> const &other);
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin();
		iterator end();
		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		const_iterator cbegin() const;
		const_iterator cend() const;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;
};

#endif