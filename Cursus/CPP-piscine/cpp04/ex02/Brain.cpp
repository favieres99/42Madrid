/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:43:47 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/11 16:18:22 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	const std::string ideas[] = {
		"happy",
		"angry",
		"shocked",
		"stunned",
		"hollow",
	};
	std::cout << "Constructor Brain:";
	for (int i = 0; i < 100; ++i){
		this->ideas[i] = ideas[rand() % (sizeof(ideas) / sizeof(std::string))];
		std::cout << " " << this->ideas[i];
	}
	std::cout << std::endl;
}

Brain::Brain(Brain const &other){
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.getIdea(i);
}

Brain &Brain::operator=(Brain const &other){
	if (this != &other){
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.getIdea(i);
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Destructor Brain:";
	for (int i = 0; i < 100; ++i)
		std::cout << " " << this->ideas[i];
	std::cout << std::endl;
}

std::string const &Brain::getIdea(int index) const{
	return this->ideas[index];
}