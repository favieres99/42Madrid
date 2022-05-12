/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:21:21 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/11 16:07:58 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(){
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wrong = new WrongCat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	wrong->makeSound();
	delete meta;
	delete cat;
	delete dog;
	delete wrong;
//	system("leaks Animal");
	return (0);
}