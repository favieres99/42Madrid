/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:41:57 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:38:51 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(Dog const &);
		Dog &operator=(Dog const &);
		~Dog();
		void makeSound() const;
		Brain *getBrain() const;
};

#endif