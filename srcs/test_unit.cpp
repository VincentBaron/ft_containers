/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/10 12:43:05 by vincentbaro      ###   ########.fr       */
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

void test_vector(void)
{
    ft::vector<int> v;
    std::vector<int> vreal;


    v.reserve(100);
	vreal.reserve(100);
	TEST_CHECK_(v.capacity() == vreal.capacity(), "Capacity after reserve(100):\nv.capacity() = %llu\nvreal.capacity() = %lu", v.capacity(), vreal.capacity());
	// for (unsigned long long int x = 0; x < 10; x++)
	// 	TEST_CHECK_(v[x] == vreal[x], "checking value at %lld", x);

    // TEST_CHECK_(tryOutOfRange(v) == tryOutOfRange(vreal), "test v.at(12)");
    // TEST_CHECK_(v.at(-1) == vreal.at(-1), "test v.at(-1)");
}

TEST_LIST = {
        {"Vector", test_vector},
        {0, 0}
    };