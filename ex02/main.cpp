/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:44:16 by qliso             #+#    #+#             */
/*   Updated: 2025/04/04 20:14:50 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base*	generate(void)
{
	int	randomNumber = std::rand() % 3;
	switch(randomNumber)
	{
		case 0:
		return (new A());
			break;
		case 1:
		return (new B());
			break;
		case 2:
		return (new C());
			break;
		default:
			break;
	}
	return (NULL);
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

	if (a == NULL)
		std::cout << "Object instantiated is not of type A" << std::endl;
	else
		std::cout << "Object instantiated is of type A" << std::endl;
	if (b == NULL)
		std::cout << "Object instantiated is not of type B" << std::endl;
	else
		std::cout << "Object instantiated is of type B" << std::endl;
	if (c == NULL)
		std::cout << "Object instantiated is not of type C" << std::endl;
	else
		std::cout << "Object instantiated is of type C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << "Object instantiated is of type A" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Object instantiated is not of type A : " << e.what() << std::endl;
	}
	
	try
	{
		B&	b = dynamic_cast<B&>(p);
		std::cout << "Object instantiated is of type B" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Object instantiated is not of type B : " << e.what() << std::endl;
	}
	
	try
	{
		C&	c = dynamic_cast<C&>(p);
		std::cout << "Object instantiated is of type C" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Object instantiated is not of type C : " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(std::time(NULL));
	Base*	base = generate();
	identify(base);
	identify(*base);
	return (0);
}
