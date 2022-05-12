/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:54:36 by gfaviere          #+#    #+#             */
/*   Updated: 2022/04/06 01:54:42 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"
#include "RandomAccessIterator.hpp"

namespace ft{
	template <class Iterator> 
	class reverse_iterator{
		public:
			//typedef
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			//default (1)	
			reverse_iterator():_it(NULL){};
			//initialization (2)	
			explicit reverse_iterator (iterator_type it):_it(it){};
			//copy (3)	
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it):_it(rev_it.base()){};

			iterator_type base() const{return _it;}
			reference operator*() const {
				iterator_type tmp = _it;
				--tmp;
				return *tmp;
			}
			reverse_iterator operator+ (difference_type n) const {return reverse_iterator(_it - n);}
			reverse_iterator& operator++(){
				--_it;
				return *this;
			};
			reverse_iterator  operator++(int){
				reverse_iterator temp = *this;
				--_it;
				return temp;
			};
			reverse_iterator& operator+= (difference_type n){
				_it -= n;
				return *this;
			};
			reverse_iterator operator- (difference_type n) const {return reverse_iterator(_it + n);}
			reverse_iterator& operator--(){
				++_it;
				return *this;
			};
			reverse_iterator  operator--(int){
				reverse_iterator temp = *this;
				++_it;
				return temp;
			};
			reverse_iterator& operator-= (difference_type n){
				_it += n;
				return *this;
			};
			pointer operator->() const {return &(operator*());}
			reference operator[] (difference_type n) const {return *(_it - n - 1);}

		private:
			iterator_type _it;
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it){
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
	const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return lhs.base() - rhs.base();
	}
}