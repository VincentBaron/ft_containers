/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/15 15:33:07 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/acutest.hpp"
#include "../includes/vector.hpp"
#include <vector>
#define SIZE 10

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

template <typename T>
void checkBasicAttr(ft::vector<T> v, std::vector<T> vreal)
{
	TEST_CHECK_(v.capacity() == vreal.capacity(), "Parameter Constructor capacity wrong");
	TEST_CHECK_(v.size() == vreal.size(), "Parameter Constructor size Wrong");
	if (v.size() && vreal.size())
	{
		// for (ft::size_type x = 0; x < v.size(); x++)
		// {
			TEST_CHECK_(v[0] == vreal[0], "_data content not matching...");
			std::cout << v[0] << std::endl;
			std::cout << vreal[0] << std::endl;
		// }
	}
}

void vectorSizeParameterConstructor(void)
{
	ft::vector<int> v(5);
	std::vector<int> vreal(5);

	checkBasicAttr(v, vreal);
}

void vectorSizeParameterAndValueConstructor(void)
{
	ft::vector<int> v(5, 9);
	std::vector<int> vreal(5, 9);

	checkBasicAttr(v, vreal);
}

void vectorPushBack(void)
{
	ft::vector<int> v(5);
	std::vector<int> vreal(5);

	v.push_back(42);
	vreal.push_back(42);
	checkBasicAttr(v, vreal);
}

void vectorDefaultConstructor(void)
{
	ft::vector<int> v;
	std::vector<int> vreal;

	checkBasicAttr(v, vreal);
}

TEST_LIST = {
	{"Default Vector Constructor...", vectorDefaultConstructor},
	{"Size Parameter Constructor...", vectorSizeParameterConstructor},
	{"Size Parameter and Values Constructor...", vectorSizeParameterAndValueConstructor},
	{"Push Back test...", vectorPushBack},
	{0, 0}};