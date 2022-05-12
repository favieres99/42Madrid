/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:56:36 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/04 12:19:51 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria *_materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		AMateria *getMateria(int index) const;
		~MateriaSource();
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const &type);
};

#endif