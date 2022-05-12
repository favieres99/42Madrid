/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:08:27 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 11:10:33 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria{
	private:
	public:
		Cure();
		Cure(Cure const &other);
		Cure &operator=(Cure const &other);
		~Cure();
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif