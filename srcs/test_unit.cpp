/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/20 13:00:01 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/VectorTestUnit.hpp"
#include "../includes/RandomAccessIteTest.hpp"

void vectorTesting(void)
{
	vectorDefaultConstructor();
	vectorSizeParameterConstructor();
	vectorSizeParameterAndValueConstructor();
	vectorPushBack();
	vectorPopBack();
	vectorEmpty();
	vectorResize();
	vectorRandomAccessIterator();
	vectorReverseIterator();
	vectorInsert();
}

int main(void)
{
	vectorTesting();
}