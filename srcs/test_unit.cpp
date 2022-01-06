/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/06 14:59:24 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/acutest.hpp"
#include "../includes/vector.hpp"
#include <vector>

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
    ft::vector<int> v(10);
    std::vector<int> vreal(10);


    TEST_CHECK_(v.at(3) == vreal.at(3), "test v.at(3)");
    // TEST_CHECK_(tryOutOfRange(v) == tryOutOfRange(vreal), "test v.at(12)");
    // TEST_CHECK_(v.at(-1) == vreal.at(-1), "test v.at(-1)");
}

TEST_LIST = {
        {"TEST v.at()", test_vector},
        {}
    };