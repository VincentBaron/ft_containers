/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/02/17 12:57:57 by vincentbaro      ###   ########.fr       */
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
	std::pair<char, int> elem('e', 42);
	ft::map<char, int> myMap;
	myMap.insert(elem);

	// std::pair<char, int> elem2('g', 41);
	// myMap.insert(elem2);
	// std::pair<char, int> elem3('h', 41);
	// myMap.insert(elem3);
	// std::pair<char, int> elem3('a', 41);
	// myMap.insert(std::make_pair<char, int>('i', 10));
	print_tree(myMap._head, 0);
}

int main(void)
{
	// vectorTimeTestsStd();
	// vectorTimeTestsFt();
	
	// vectorTesting();
	// stackTesting();

	mapRandomTests();
}