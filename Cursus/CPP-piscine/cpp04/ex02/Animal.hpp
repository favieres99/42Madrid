/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:30:34 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 12:06:29 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &);
		virtual ~Animal();
		Animal &operator=(Animal const &);
		virtual void makeSound() const = 0;
		std::string const &getType() const;
};

#endif