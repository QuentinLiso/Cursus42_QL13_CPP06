/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:32:14 by qliso             #+#    #+#             */
/*   Updated: 2025/04/04 19:27:33 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <iomanip>
#include "Data.hpp"
#include "Serializer.hpp"

void	displayData(Data *ptr)
{
	std::cout << "Name : " << ptr->name << std::endl;
	std::cout << "Age : " << ptr->age << std::endl;
	std::cout << "Dog : " << ptr->dog << std::endl;
}

int	main()
{
	Data	me;
	
	me.name = "Didier";
	me.age = 10;
	me.dog = true;
	std::cout << "First ptr address : " << &me << std::endl;
	displayData(&me);
	
	uintptr_t	me_serialized = Serializer::serialize(&me);
	std::cout << "Second ptr address in hex : 0x" << std::hex << me_serialized << std::endl;
	std::cout << "Second ptr address in dec : " << std::dec << me_serialized << std::endl;
	
	Data	*me_bis = Serializer::deserialize(me_serialized);
	displayData(me_bis);

	return (0);
}