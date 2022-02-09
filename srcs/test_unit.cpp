/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/02/09 12:01:57 by vscode           ###   ########.fr       */
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
	// vectorAssign();
	// vectorPushBack();
	// vectorPopBack();
	// vectorEmpty();
	// vectorResize();
	// vectorRandomAccessIterator();
	// vectorReverseIterator();
	vectorInsert();
	// vectorErase();
	// vectorSwap();
	// vectorOperators();
}

void stackTesting(void)
{
	stackConstructorsTesting();
}

void randomTests(void)
{
	ft::vector<int> v(5, 42);
	
	ft::vector<int>::const_iterator ite = v.begin();
}

int main(void)
{
	randomTests();
	
	// vectorTesting();
	// stackTesting();
}