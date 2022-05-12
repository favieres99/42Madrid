/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:15 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/03 12:02:53 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		~Brain();
		std::string const &getIdea(int index) const;
};

#endif