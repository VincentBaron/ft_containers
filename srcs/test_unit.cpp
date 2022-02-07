/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/02/07 19:30:47 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/VectorTestUnit.hpp"
#include "../includes/RandomAccessIteTest.hpp"
#include "../includes/StackTestUnit.hpp"

void vectorTesting(void)
{
	// vectorDefaultConstructor();
	// vectorSizeParameterConstructor();
	// vectorSizeParameterAndValueConstructor();
	vectorAssign();
	// vectorPushBack();
	// vectorPopBack();
	// vectorEmpty();
	// vectorResize();
	// vectorRandomAccessIterator();
	// vectorReverseIterator();
	// vectorInsert();
	// vectorErase();
	// vectorSwap();
	// vectorOperators();
}

void stackTesting(void)
{
	stackConstructorsTesting();
}

int main(void)
{
	vectorTesting();
	// stackTesting();
}