/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:05:28 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 20:12:01 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAN_HPP
#define SCAN_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Span{
	private:
		unsigned int _size;
		std::vector<int> _values;
		Span();
	public:
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		int &operator[](int i);
		~Span();
		unsigned int size() const;
		std::vector<int> const &getValues() const;
		void addNumber(int n);
		void addNumber(std::vector<int>::iterator const &, std::vector<int>::iterator const &);
		long shortestSpan() const;
		long longestSpan() const;
		class OutOfRangeException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Out of range");
				}
		};
		class FullException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Buffer is already full");
				}
		};
		class CantSearchException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Can't search");
				}
		};
};

#endif