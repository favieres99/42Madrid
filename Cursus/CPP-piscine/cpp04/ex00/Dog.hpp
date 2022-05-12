/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:41:57 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 10:43:25 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(Dog const &);
		Dog &operator=(Dog const &);
		~Dog();
		void makeSound() const;
};

#endif