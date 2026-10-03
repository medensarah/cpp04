/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 19:57:50 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/03 21:24:15 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "===== TEST 1: POLYMORPHISM =====" << std::endl;

	const Animal *animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << "===== TEST 2: DESTRUCTION THROUGH ANIMAL* =====" << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "===== TEST 3: DOG COPY CONSTRUCTOR =====" << std::endl;

	Dog dog1;
	Dog dog2(dog1);

	std::cout << "dog1: " << dog1.getType() << std::endl;
	std::cout << "dog2: " << dog2.getType() << std::endl;

	std::cout << std::endl;
	std::cout << "===== TEST 4: CAT COPY ASSIGNMENT =====" << std::endl;

	Cat cat1;
	Cat cat2;

	cat2 = cat1;

	std::cout << "cat1: " << cat1.getType() << std::endl;
	std::cout << "cat2: " << cat2.getType() << std::endl;

	std::cout << std::endl;
	std::cout << "===== TEST 5: SELF ASSIGNMENT =====" << std::endl;

	dog1 = dog1;
	cat1 = cat1;

	std::cout << std::endl;
	std::cout << "===== END =====" << std::endl;

	return (0);
}
