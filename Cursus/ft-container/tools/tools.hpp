/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:28 by gfaviere          #+#    #+#             */
/*   Updated: 2022/04/11 18:52:22 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Iterators/ReverseIterator.hpp"
#include "type_traits.hpp"

namespace ft{
	template<class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	//lexicographical
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2 ){
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
	}

	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2,
									Compare comp ){
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
		if (comp(*first1, *first2)) return true;
		if (comp(*first2, *first1)) return false;
	}
	return (first1 == last1) && (first2 != last2);
	}
}