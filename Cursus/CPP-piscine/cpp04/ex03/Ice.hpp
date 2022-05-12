/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:13:59 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 11:15:58 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria{
	private:
	public:
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		~Ice();
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif