/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/11 16:24:52 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/acutest.hpp"
#include "../includes/vector.hpp"
#include <vector>
# define SIZE 10

template <typename T>
bool tryOutOfRange(T vect)
{
    try
    {
        vect.at(12);
    }
    catch(const std::out_of_range& e)
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

	
	v = ft::vector<int>(10);
    vreal = std::vector<int>(10);

	TEST_CHECK_(v.capacity() == vreal.capacity(), "Parameter Constructor capacity wrong");
	TEST_CHECK_(v.size() == vreal.size(), "Parameter Constructor size Wrong");

	v = ft::vector<int>(10, 5);
    vreal = std::vector<int>(10, 5);

	TEST_CHECK_(v.capacity() == vreal.capacity(), "Parameter with value Constructor capacity wrong");
	TEST_CHECK_(v.size() == vreal.size(), "Parameter with value Constructor size Wrong");
	TEST_CHECK_(v[2] == vreal[2], "Parameter with value Constructor size Wrong");
	
	
	//TEST_CHECK_(v.capacity() == vreal.capacity(), "Capacity after reserve(100):\nv.capacity() = %llu\nvreal.capacity() = %lu", v.capacity(), vreal.capacity());
	// for (unsigned long long int x = 0; x < 10; x++)
	// 	TEST_CHECK_(v[x] == vreal[x], "checking value at %lld", x);

    // TEST_CHECK_(tryOutOfRange(v) == tryOutOfRange(vreal), "test v.at(12)");
    // TEST_CHECK_(v.at(-1) == vreal.at(-1), "test v.at(-1)");
}

TEST_LIST = {
        {"Vector Constructor", test_vector_constructors},
        {0, 0}
    };