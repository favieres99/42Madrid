/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:39:55 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 11:38:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const &);
		Cat &operator=(Cat const &);
		~Cat();
		void makeSound() const;
		Brain *getBrain() const;
};

#endif