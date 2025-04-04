/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:24:39 by qliso             #+#    #+#             */
/*   Updated: 2025/04/04 18:14:34 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Determine the literal type of the parameter
bool	ScalarConverter::isChar(char* const str)
{
	return (std::strlen(str) == 1 && !std::isdigit(*str));	
}

bool	ScalarConverter::isInt(char* const str)
{
	char	*end;
	long	i;

	i = std::strtol(str, &end, 10);
	return (*end == '\0' && i <= INT_MAX && i >= INT_MIN);
}

bool	ScalarConverter::isFloat(char* const str)
{
	char	*end;
	double	f;

	f = static_cast<double>(std::strtof(str, &end));
	return (end[0] == 'f' 
			&& *(end + 1) == '\0'
			&& ((f <= FLT_MAX && f >= -FLT_MAX) || std::isinf(f) || std::isnan(f)));
}

bool	ScalarConverter::isDouble(char* const str)
{
	char	*end;
	double	f;

	f = std::strtod(str, &end);
	static_cast<void>(f);
	return (*end == '\0');
}

ScalarConverter::LitType	ScalarConverter::getLitType(char* const str)
{
	bool	(*f[4])(char* const str) = 
			{
				&ScalarConverter::isChar,
				&ScalarConverter::isInt,
				&ScalarConverter::isFloat,
				&ScalarConverter::isDouble,
			};
	
	for (int i = 0; i < 4; i++)
	{
		if ((f[i])(str) == true)
			return (static_cast<ScalarConverter::LitType>(i));
	}
	return (static_cast<ScalarConverter::LitType>(4));
}


// Functions to convert from a type, to handle downcast
void	ScalarConverter::convertToChar(int i)
{
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) 
		std::cout << "char: Overflow, cannot convert to char" << std::endl;
	else
		displayChar(static_cast<char>(i));
}

void	ScalarConverter::convertToChar(float f)
{
	int	i;
	if (std::isinf(f) || std::isnan(f))
	{
		std::cout << "char: Impossible" << std::endl;
		return ;
	}
	i = static_cast<int>(f);
	if (f != i)
	{
		std::cout << "char: Non-integer value, cannot convert to char" << std::endl;
		return ;
	}
	convertToChar(i);
}

void	ScalarConverter::convertToChar(double d)
{
	int	i;
	if (std::isinf(d) || std::isnan(d))
	{
		std::cout << "char: Impossible" << std::endl;
		return ;
	}
	i = static_cast<int>(d);
	if (d != i)
	{
		std::cout << "char: Non-integer value, cannot convert to char" << std::endl;
		return ;
	}
	convertToChar(i);
}

void	ScalarConverter::convertToInt(double d)
{
	int	i;

	if (std::isinf(d) || std::isnan(d))
	{
		std::cout << "int: Impossible" << std::endl;
		return ;
	}
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
	{
		std::cout << "int: Overflow, cannot convert to int" << std::endl;
		return ;
	}
	i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::convertToFloat(double d)
{
	float	f;

	if (std::isinf(d) || std::isnan(d))
	{
		std::cout << "float: " << d << "f" << std::endl;
		return ;
	}
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
	{
		std::cout << "float: Overflow, cannot convert to float" << std::endl;
		return ;
	}
	f = static_cast<float>(d);
	ScalarConverter::displayFloat(f);
}


// Functions to display based on the type
void	ScalarConverter::displayChar(char c)
{
	if (!std::isprint(c))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

void	ScalarConverter::displayInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::displayFloat(float f)
{
	if (std::isinf(f) || std::isnan(f))
	{
		std::cout << "float: " << f << "f" << std::endl;
		return ;
	}
	std::cout	<< std::fixed << std::setprecision(2) << "float: " << f << "f" << std::endl;
}

void	ScalarConverter::displayDouble(double d)
{
	std::cout	<< std::fixed << std::setprecision(2) << "double: " << d << std::endl;
}


// Functions called by convert
void	ScalarConverter::displayType(std::string const &s)
{
	std::cout << "\033[1;33mParameter identified as a " << s << "\033[0m" << std::endl;
}

void	ScalarConverter::handleChar(char* const str)
{
	char	c = *str;
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	ScalarConverter::displayType("CHAR");
	ScalarConverter::displayChar(c);
	ScalarConverter::displayInt(i);
	ScalarConverter::displayFloat(f);
	ScalarConverter::displayDouble(d);
}

void	ScalarConverter::handleInt(char * const str)
{
	int		i = std::atoi(str);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	ScalarConverter::displayType("INT");
	ScalarConverter::convertToChar(i);
	ScalarConverter::displayInt(i);
	ScalarConverter::displayFloat(f);
	ScalarConverter::displayDouble(d);
}

void	ScalarConverter::handleFloat(char* const str)
{
	float	f = std::strtof(str, NULL);
	double	d = static_cast<double>(f);

	ScalarConverter::displayType("FLOAT");
	ScalarConverter::convertToChar(f);
	ScalarConverter::convertToInt(f);
	ScalarConverter::displayFloat(f);
	ScalarConverter::displayDouble(d);
}

void	ScalarConverter::handleDouble(char* const str)
{
	double	d = std::strtod(str, NULL);

	ScalarConverter::displayType("DOUBLE");
	ScalarConverter::convertToChar(d);
	ScalarConverter::convertToInt(d);
	ScalarConverter::convertToFloat(d);
	ScalarConverter::displayDouble(d);
}

void	ScalarConverter::incorrectValue(char* const str)
{
	ScalarConverter::displayType("UNDEFINED TYPE");
	std::cout	<< "char: incorrect value " << str << "\n"
				<< "int: incorrect value " << str << "\n"
				<< "float: incorrect value " << str << "\n"
				<< "double: incorrect value " << str << std::endl;
}


// Public function
void	ScalarConverter::convert(char *const str)
{
	void	(*f[5])(char* const str) = 
	{
		&ScalarConverter::handleChar,
		&ScalarConverter::handleInt,
		&ScalarConverter::handleFloat,
		&ScalarConverter::handleDouble,
		&ScalarConverter::incorrectValue
	};
	int	type = static_cast<int>(getLitType(str));
	f[type](str);
}