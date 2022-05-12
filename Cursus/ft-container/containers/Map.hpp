/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:47:20 by gfaviere          #+#    #+#             */
/*   Updated: 2022/04/11 18:53:04 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include "../tools/pair.hpp"
#include "../tools/bst.hpp"
#include "../tools/tools.hpp"
#include "../tools/type_traits.hpp"
#include "../Iterators/RandomAccessIterator.hpp"
#include "../Iterators/ReverseIterator.hpp"
#include "../Iterators/BstIterator.hpp"


namespace ft{
	template < class Key,
	class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > 
	> class map{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				public:
					value_compare (Compare c) : comp(c) {}

				protected:
					Compare comp;
					
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			typedef Alloc 										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef typename ft::bst<value_type, value_compare>::iterator				iterator;
			typedef typename ft::bst<value_type, value_compare>::const_iterator			const_iterator;
			typedef typename ft::bst<value_type, value_compare>::reverse_iterator		reverse_iterator;
			typedef typename ft::bst<value_type, value_compare>::const_reverse_iterator	const_reverse_iterator;

			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;

//empty 	(1)
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp){};
//range 	(2)
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp)
			{
				while (first != last)
					insert(*first++);
			}
//copy 		(3)
			map (const map& x)
			{
				_alloc = x._alloc;
				_comp = x._comp;
				_c = x._c;
			}

			~map(){};//only allocations inside of the binary search tree that has its own destructor

			iterator begin(){return _c.begin();}
			const_iterator begin() const{return _c.begin();}
			iterator end() {return _c.end();}
			const_iterator end() const {return _c.end();}
			reverse_iterator rbegin(){return reverse_iterator(end());}
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
			reverse_iterator rend(){return reverse_iterator(begin());}
			const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

			//Capacity
			bool empty() const {return _c.empty();}
			size_type size() const {return _c.size();}
			size_type	max_size() const {return _c.max_size();}

			//Element Access
			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}

			//Modifiers
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				return _c.insert(val, _c.getRoot());
			};

			iterator insert (iterator position, const value_type& val){
				return _c.insert(position, val);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last){
				while (first != last)
					_c.insert(*first++, _c.getRoot());
			}

			void erase (iterator position){
				_c.erase(position);
			}

			size_type erase (const key_type& k){
				return _c.erase(ft::make_pair(k, mapped_type()));
			}

			void erase (iterator first, iterator last){
				while (first != last)
					_c.erase(first++);
			}

			void swap (map& x)
			{
				allocator_type tmpAlloc = _alloc;
				key_compare tmpComp = _comp;

				_alloc = x._alloc;
				_comp = x._comp;

				x._alloc = tmpAlloc;
				x._comp = tmpComp;

				_c.swap(x._c);
			}

			void clear()
			{
				_c.clear();
			}

		//Observers

			key_compare key_comp() const {return key_compare();}
			value_compare value_comp() const {return value_compare(key_compare());}

		//Operations

			iterator find (const key_type& k)
			{
				iterator ret(_c.research(ft::make_pair(k, mapped_type())), _c.getRoot());
				return ret;
			}

			const_iterator find (const key_type& k) const
			{
				iterator ret(_c.research(ft::make_pair(k, mapped_type())), _c.getRoot());
				return ret;
			}

			size_type count (const key_type& k) const
			{
				return _c.count(ft::make_pair(k, mapped_type()));
			}

			iterator lower_bound (const key_type& k)
			{
				return _c.lower_bound(ft::make_pair(k, mapped_type()));
			}
			const_iterator lower_bound (const key_type& k) const
			{
				return _c.lower_bound(ft::make_pair(k, mapped_type()));
			}

			iterator upper_bound (const key_type& k)
			{
				return _c.upper_bound(ft::make_pair(k, mapped_type()));
			}
			const_iterator upper_bound (const key_type& k) const
			{
				return _c.upper_bound(ft::make_pair(k, mapped_type()));
			}
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				const_iterator low = lower_bound(k);
				const_iterator up = upper_bound(k);
				return ft::make_pair(low, up);
			}
			ft::pair<iterator,iterator> equal_range (const key_type& k)
			{
				iterator low = lower_bound(k);
				iterator up = upper_bound(k);
				return ft::make_pair(low, up);
			}

		//Allocator
			allocator_type get_allocator() const { return _alloc;}
	
		private:
			allocator_type						_alloc;
			key_compare							_comp;
			ft::bst<value_type, key_compare>	_c;
	};

	//Relational operators
	template <class T, class Alloc>
	bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;	
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return true;
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator>  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return false;
		return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
		if (lhs == rhs)
			return true;
		return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	//Swap
	template <class T, class Alloc>
	void swap (map<T,Alloc>& x, map<T,Alloc>& y){
		x.swap(y);
	}
}