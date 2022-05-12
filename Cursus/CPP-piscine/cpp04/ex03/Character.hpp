/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:04:18 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 12:19:06 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
	private:
		std::string _name;
		AMateria *_materia[4];
		Character(){};
	public:
		Character(std::string const &name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		~Character();
		std::string const &getName() const;
		AMateria const *getMateria(int index) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif