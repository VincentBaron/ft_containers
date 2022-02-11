/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/02/11 15:18:32 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/VectorTestUnit.hpp"
#include "../includes/RandomAccessIteTest.hpp"
#include "../includes/StackTestUnit.hpp"
#include "../includes/map.hpp"

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

void vectorTimeTestsStd(void)
{
	std::vector<int> vct(100000000, 42);
	std::vector<int> vct2(10000000, 45);

	vct.insert(vct.begin() + 345, vct2.begin(), vct2.end());
}

void vectorTimeTestsFt(void)
{
	ft::vector<int> vct(100000000, 42);
	ft::vector<int> vct2(10000000, 45);

	vct.insert(vct.begin() + 345, vct2.begin(), vct2.end());
}

void mapRandomTests(void)
{
	// ft::map<char, int> test;
	std::pair<char, int> elem('a', 42);
	ft::Node<std::pair<char, int> > tree(elem);

	print_tree(&tree, 0);
}

int main(void)
{
	// vectorTimeTestsStd();
	// vectorTimeTestsFt();
	
	// vectorTesting();
	// stackTesting();

	mapRandomTests();
}