/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/14 19:12:28 by vincentbaro      ###   ########.fr       */
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

void test_vector_constructors(void)
{
	ft::vector<int> v;
	std::vector<int> vreal;

	TEST_CHECK_(v.capacity() == vreal.capacity(), "Default Constructor capacity wrong");
	TEST_CHECK_(v.size() == vreal.size(), "Default Constructor size Wrong");

	v = ft::vector<int>(4);
	vreal = std::vector<int>(4);

	TEST_CHECK_(v.capacity() == vreal.capacity(), "Parameter Constructor capacity wrong");
	TEST_CHECK_(v.size() == vreal.size(), "Parameter Constructor size Wrong");

	std::cout << "PUSH BACK ----" << std::endl;

	std::cout << vreal.capacity() << std::endl;
	v.push_back(5);
	vreal.push_back(5);

	TEST_CHECK_(v.capacity() == vreal.capacity(), "Push Back capacity wrong");
	std::cout << v.capacity() << std::endl;
	std::cout << vreal.capacity() << std::endl;
	TEST_CHECK_(v.size() == vreal.size(), "Push Back size Wrong");
	for (int x = 0; x < 5; x++)
	{
		TEST_CHECK_(v[x] == vreal[x], "_data content not matching...");
		// std::cout << v[x] << std::endl;
		// std::cout << vreal[x] << std::endl;
	}

	// std::cout << v[2] << std::endl;
	// std::cout << vreal[2] << std::endl;
	// TEST_CHECK_(v.capacity() == vreal.capacity(), "Parameter with value Constructor capacity wrong");
	// TEST_CHECK_(v.size() == vreal.size(), "Parameter with value Constructor size Wrong");
	// TEST_CHECK_(v[2] == vreal[2], "Parameter with value Constructor size Wrong");

	// TEST_CHECK_(v.capacity() == vreal.capacity(), "Capacity after reserve(100):\nv.capacity() = %llu\nvreal.capacity() = %lu", v.capacity(), vreal.capacity());
	//  for (unsigned long long int x = 0; x < 10; x++)
	//  	TEST_CHECK_(v[x] == vreal[x], "checking value at %lld", x);

	// TEST_CHECK_(tryOutOfRange(v) == tryOutOfRange(vreal), "test v.at(12)");
	// TEST_CHECK_(v.at(-1) == vreal.at(-1), "test v.at(-1)");
}

TEST_LIST = {
	{"Vector Constructor", test_vector_constructors},
	{0, 0}};