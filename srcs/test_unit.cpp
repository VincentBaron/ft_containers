/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/21 15:39:30 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/VectorTestUnit.hpp"
#include "../includes/RandomAccessIteTest.hpp"

void vectorTesting(void)
{
	vectorDefaultConstructor();
	vectorSizeParameterConstructor();
	vectorSizeParameterAndValueConstructor();
	vectorAssign();
	vectorPushBack();
	vectorPopBack();
	vectorEmpty();
	vectorResize();
	vectorRandomAccessIterator();
	vectorReverseIterator();
	vectorInsert();
	vectorErase();
	vectorSwap();
	vectorOperators();
}

int main(void)
{
	vectorTesting();
}