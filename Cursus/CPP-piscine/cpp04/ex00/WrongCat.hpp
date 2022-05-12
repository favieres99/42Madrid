/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:46:27 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 10:48:28 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &copy);
		virtual ~WrongCat();
		void makeSound() const;
};

#endif