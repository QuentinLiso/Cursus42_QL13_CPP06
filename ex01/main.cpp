/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:32:14 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 12:12:58 by qliso            ###   ########.fr       */
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
	std::cout << "First ptr address in hex : " << &me << std::endl;
	displayData(&me);
	
	uintptr_t	me_serialized = Serializer::serialize(&me);
	std::cout << "Serialized ptr in hex : 0x" << std::hex << me_serialized << std::dec << std::endl;
	
	Data	*me_bis = Serializer::deserialize(me_serialized);
	displayData(me_bis);

	return (0);
}