/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:10:23 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:12:06 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>

typedef struct{
	int age;
	std::string name;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif