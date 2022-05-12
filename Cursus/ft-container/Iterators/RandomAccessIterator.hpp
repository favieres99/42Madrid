/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:53:26 by gfaviere          #+#    #+#             */
/*   Updated: 2022/04/06 01:53:32 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

namespace ft{
	template < class T >
	class RandomAccessIterator{
		public:
		//typedef
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

		//constructors
			RandomAccessIterator():_ptr(NULL) {};
			RandomAccessIterator(pointer ptr):_ptr(ptr) {};
			~RandomAccessIterator() {};
			RandomAccessIterator (RandomAccessIterator const& other): _ptr(other._ptr) {};
			RandomAccessIterator &operator=(RandomAccessIterator const& other) {
				if (this != &other)
					_ptr = other._ptr;
				return *this; 
			};

		//Dereference
			reference operator*() {return *_ptr;}
			pointer operator->() const {return &(operator*());}

			pointer base() const {return _ptr;}
			

		//Incrementation
			RandomAccessIterator	&operator++() {
				++_ptr;
				return *this;
			}
			RandomAccessIterator	operator++(int) {
				RandomAccessIterator ret(*this);
				++_ptr;
				return ret;
			}
			RandomAccessIterator	&operator--() {
				--_ptr;
				return *this;
			}
			RandomAccessIterator	operator--(int) {
				RandomAccessIterator ret(*this);
				--_ptr;
				return ret;
			}
			RandomAccessIterator	&operator+=(difference_type n) {
				_ptr += n;
				return *this;
			}
			RandomAccessIterator	&operator-=(difference_type n) {
				_ptr -= n;
				return *this;
			}

			//Arithmetics
			RandomAccessIterator	operator+(difference_type n){return (_ptr + n);}
			RandomAccessIterator	operator-(difference_type n){return (_ptr - n);}
			difference_type			operator-(RandomAccessIterator const& a){return _ptr - a._ptr;}

			//offset derefence operator
			reference &operator[] (difference_type n) const {return &_ptr[n];}

			operator RandomAccessIterator<const T> () const
			{ return (RandomAccessIterator<const T>(_ptr)); }

		private:
			pointer	_ptr;
	};
			//comparisons
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator!=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator==(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() == rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() < rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() <= rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() > rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() >= rhs.base());
	}

	//Comparisons with const
	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator==(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() == rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator!=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() != rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() >= rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() > rhs.base());
	}
}