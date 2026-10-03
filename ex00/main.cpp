/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 19:57:50 by smedenec          #+#    #+#             */
/*   Updated: 2026/10/03 20:36:44 by smedenec         ###   ########.fr       */
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
	// =========================================================
	// 1. Basic construction and types
	// =========================================================

	std::cout << "========== BASIC TYPES ==========" << std::endl;

	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "Animal type: " << animal->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	delete animal;
	delete dog;
	delete cat;


	// =========================================================
	// 2. Polymorphism
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== POLYMORPHISM ==========" << std::endl;

	const Animal *animals[2];

	animals[0] = new Dog();
	animals[1] = new Cat();

	std::cout << animals[0]->getType() << ": ";
	animals[0]->makeSound();

	std::cout << animals[1]->getType() << ": ";
	animals[1]->makeSound();

	delete animals[0];
	delete animals[1];


	// =========================================================
	// 3. Animal's own makeSound
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== ANIMAL SOUND ==========" << std::endl;

	const Animal *genericAnimal = new Animal();

	genericAnimal->makeSound();

	delete genericAnimal;


	// =========================================================
	// 4. Wrong hierarchy
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== WRONG POLYMORPHISM ==========" << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();

	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;


	// =========================================================
	// 5. Direct calls
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== DIRECT CALLS ==========" << std::endl;

	Dog directDog;
	Cat directCat;
	WrongCat directWrongCat;

	directDog.makeSound();
	directCat.makeSound();
	directWrongCat.makeSound();


	// =========================================================
	// 6. Copy constructors
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== COPY CONSTRUCTORS ==========" << std::endl;

	Dog dog1;
	Dog dog2(dog1);

	Cat cat1;
	Cat cat2(cat1);

	WrongCat wrongCat1;
	WrongCat wrongCat2(wrongCat1);

	std::cout << dog2.getType() << std::endl;
	std::cout << cat2.getType() << std::endl;
	std::cout << wrongCat2.getType() << std::endl;


	// =========================================================
	// 7. Copy assignment
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== COPY ASSIGNMENT ==========" << std::endl;

	Dog dog3;
	Dog dog4;

	dog4 = dog3;

	Cat cat3;
	Cat cat4;

	cat4 = cat3;

	WrongCat wrongCat3;
	WrongCat wrongCat4;

	wrongCat4 = wrongCat3;

	std::cout << dog4.getType() << std::endl;
	std::cout << cat4.getType() << std::endl;
	std::cout << wrongCat4.getType() << std::endl;


	// =========================================================
	// 8. Construction / destruction chaining
	// =========================================================

	std::cout << std::endl;
	std::cout << "========== DESTRUCTION CHAIN ==========" << std::endl;

	{
		Dog scopedDog;
		Cat scopedCat;
		WrongCat scopedWrongCat;

		std::cout << "--- Leaving scope ---" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== END ==========" << std::endl;

	return (0);
}
