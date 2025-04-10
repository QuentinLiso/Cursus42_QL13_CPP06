/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:24:39 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 12:01:37 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <cstdlib>
# include <cstring>
# include <climits>
# include <cfloat>
# include <limits>
# include <cmath>
# include <iostream>
# include <iomanip>

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &c);
		ScalarConverter& operator=(ScalarConverter const &rhs);
		virtual ~ScalarConverter(void);
		
		enum	LitType {CHAR, INT, FLOAT, DOUBLE, UNDEF};
		static bool	isChar(char *const str);
		static bool	isInt(char *const str);
		static bool	isFloat(char *const str);
		static bool	isDouble(char *const str);
		static LitType	getLitType(char* const str);

		static void	convertToChar(int i);
		static void	convertToChar(float f);
		static void	convertToChar(double d);
		static void	convertToInt(double d);
		static void	convertToFloat(double d);

		static void	displayChar(char c);
		static void displayInt(int i);
		static void	displayFloat(float f);
		static void	displayDouble(double d);
		
		static void displayType(std::string const &s);
		static void	handleChar(char* const str);
		static void	handleInt(char* const str);
		static void	handleFloat(char* const str);
		static void	handleDouble(char* const str);
		static void	incorrectValue(char* const str);
		
	public:
		static void	convert(char *const str); 
};

#endif