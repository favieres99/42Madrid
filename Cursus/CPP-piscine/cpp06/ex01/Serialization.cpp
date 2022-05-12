/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:12:17 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/14 18:13:51 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}