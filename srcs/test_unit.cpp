/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/05 20:01:35 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/acutest.hpp"
#include "../includes/util.hpp"

void test_add(void)
{
    TEST_CHECK_(add(2, 2)==(2+2), "add(%d,%d)==%d", 2, 2, (2+2));
}

TEST_LIST = {
        {"int add(int, int);", test_add },
        {}
    };