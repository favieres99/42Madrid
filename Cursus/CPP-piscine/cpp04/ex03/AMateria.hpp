/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:00:30 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 11:04:04 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria{
	private:
		AMateria(){};
	protected:
		std::string _type;
		unsigned int _xp;
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		virtual ~AMateria();
		std::string const &getType() const;
		unsigned int getXP() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif