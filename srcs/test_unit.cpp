/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:01:30 by vbaron            #+#    #+#             */
/*   Updated: 2022/02/24 17:42:59 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/VectorTestUnit.hpp"
#include "../includes/RandomAccessIteTest.hpp"
#include "../includes/StackTestUnit.hpp"
#include "../includes/map.hpp"
#include "../includes/MapTestUnit.hpp"

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
	// // ft::map<char, int> test;
	// ft::pair<char, int> elem('e', 42);
	// ft::map<char, int> myMap;
	// myMap.insert(elem);

	// ft::pair<char, int> elem2('g', 41);
	// myMap.insert(elem2);
	// ft::pair<char, int> elem3('h', 41);
	// myMap.insert(elem3);
	
	// ft::pair<ft::map<char, int>::iterator, bool> ret = myMap.insert(ft::make_pair<char, int>('n', 10));
	// print_tree(myMap._head, 0);

	// myMap.erase('i');

	// print_tree(myMap._head, 0);

	ft::map<char, int> myMap;
	myMap.insert(ft::make_pair<char, int>('b', 10));
	// myMap.insert(ft::make_pair<char, int>('a', 10));
	// myMap.insert(ft::make_pair<char, int>('c', 10));
	
	
	print_tree(myMap._root, 0);
}

int main(void)
{ 
	
	///////////////////////////////////////VECTOR TESTING
	// vectorTimeTestsStd();
	// vectorTimeTestsFt();
	// vectorTesting();
	//////////////////////////////////////////////////////
	
	///////////////////////////////////////STACK TESTING
	// stackTesting();
	//////////////////////////////////////////////////////

	///////////////////////////////////////MAP TESTING
	mapRandomTests();
	// mapConstructors();
	// mapIterators();
	//////////////////////////////////////////////////////
	return (0);
}