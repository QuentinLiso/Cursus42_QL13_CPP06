/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:46:16 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 12:11:00 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class	Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &c);
		Serializer&	operator=(Serializer const &rhs);
		virtual ~Serializer(void);	

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

/*
What is Serialization?
Serialization is the process of turning an object in memory into a linear sequence of bytes that can be:
    Saved to a file
    Sent over a network
    Stored in a database
    Shared between programs
    Passed between processes or even machines

And Deserialization?
	Deserialization is the opposite
	It’s taking that sequence of bytes and rebuilding the original object in memory.

How does reinterpret_cast come into play?
	C++ is a low-level language, so it gives you raw tools.
	One way (not always safe, but fast) to serialize something is to treat its memory 
		as a char* or uint8_t* — a byte stream.

Big caveats of using reinterpret_cast for serialization:
	Not portable across platforms (different endianness, padding, alignment)
    Not safe with polymorphic types (like classes with virtual methods)
    Breaks if structure layout changes

It’s very fast, but it's a bit like using raw memcpy — powerful but dangerous.
This technique is often used in embedded systems, game engines, or systems programming where performance is key and you control the memory layout tightly.

*/



#endif