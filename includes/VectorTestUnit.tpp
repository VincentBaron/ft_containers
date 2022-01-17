/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTestUnit.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:13:07 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/17 11:04:04 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTUNIT_TPP
# define VECTORTESTUNIT_TPP
# include <vector>
# include "vector.hpp"
# include "utils.hpp"
# define SIZE 10
# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

template <typename T>
bool tryOutOfRange(T vect)
{
	try
	{
		vect.at(12);
	}
	catch (const std::out_of_range &e)
	{
		return (true);
	}
	return (false);
}

template<typename T1, typename T2>
void checkOutput(T1 res1, T2 res2, std::string mssg)
{
	std::cout << YELLOW << mssg << RESET;
	if (res1 == res2)
		std::cout << BOLDGREEN << "SUCCESS!" << RESET << std::endl;
	else
	{
		std::cout << BOLDRED << "FAILURE!" << RESET << std::endl;
		std::cout << CYAN << "Output myVector: " << res1 << RESET << std::endl;
		std::cout << BLUE << "Output realVector: " << res2 << RESET << std::endl << std::endl;
	}
}

template<typename T>
void checkArray(ft::vector<T> v, std::vector<T> vreal)
{
	std::cout << YELLOW << "Checking _array...    " << RESET << std::endl;
	for (unsigned long long x = 0; x < v.size(); x++)
		checkOutput(v[x], vreal[x], "Checking _data[" + to_string(x) + "]...    ");
}

template <typename T>
void checkBasicAttr(ft::vector<T> v, std::vector<T> vreal)
{
	// checkOutput(v.capacity(), vreal.capacity(), "Checking Capacity...    ");
	checkOutput(v.size(), vreal.size(), "Checking Size...    ");
	checkArray(v, vreal);
}

void vectorSizeParameterConstructor(void)
{
	std::cout << BOLDMAGENTA << "\nVector Size constructor testing..." << RESET << std::endl;
	
	ft::vector<int> v(5);
	std::vector<int> vreal(5);

	checkBasicAttr(v, vreal);
}

void vectorSizeParameterAndValueConstructor(void)
{
	std::cout << BOLDMAGENTA << "\nVector Size and Value constructor testing..." << RESET << std::endl;

	ft::vector<int> v(5, 9);
	std::vector<int> vreal(5, 9);

	checkBasicAttr(v, vreal);
}

void vectorPushBack(void)
{
	std::cout << BOLDMAGENTA << "\nVector Push Back testing..." << RESET << std::endl;

	ft::vector<int> v(5);
	std::vector<int> vreal(5);

	v.push_back(42);
	vreal.push_back(42);
	checkBasicAttr(v, vreal);
}

void vectorPopBack(void)
{
	std::cout << BOLDMAGENTA << "\nVector Pop Back testing..." << RESET << std::endl;

	ft::vector<int> v(5, 42);
	std::vector<int> vreal(5, 42);

	try
	{
		vreal.pop_back();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		v.pop_back();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	checkBasicAttr(v, vreal);
}

void vectorDefaultConstructor(void)
{
	std::cout << BOLDMAGENTA << "\nVector default constructor testing..." << RESET << std::endl;
	
	ft::vector<int> v;
	std::vector<int> vreal;

	checkBasicAttr(v, vreal);
}

#endif

