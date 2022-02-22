/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTestUnit.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:07:19 by vscode            #+#    #+#             */
/*   Updated: 2022/02/22 17:15:36 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPTESTUNIT_HPP
#define MAPTESTUNIT_HPP
#include "map.hpp"
#include "VectorTestUnit.hpp"
#include <map>
#include "utils.hpp"

template <typename T1, typename T2>
void checkOutputMap(T1 res1, T2 res2, std::string mssg)
{
	std::string offset = "";
	std::cout << YELLOW << mssg << RESET;
	if (res1 == res2)
		std::cout << BOLDGREEN << offset.insert(0, OFFSET - mssg.size(), ' ') << "SUCCESS!" << RESET << std::endl;
	else
	{
		std::cout << BOLDRED << offset.insert(0, OFFSET - mssg.size(), ' ') << "FAILURE!" << RESET << std::endl;
		std::cout << CYAN << "Output myVector: " << res1 << RESET << std::endl;
		std::cout << BLUE << "Output realVector: " << res2 << RESET << std::endl
				  << std::endl;
	}
}

template <typename T1, typename T2>
void checkArrayMap(T1 &v, T2 &vreal)
{
	std::cout << "\n"
			  << BRIGHTBLACK << "Checking _array...    " << RESET << std::endl;
	typename T1::iterator ite1 = v.begin();
	typename T2::iterator ite2 = vreal.begin();
	for (; ite2 != vreal.end(), ite1 != v.end(); ite2++, ite1++)
	{
		checkOutputMap((*ite2).first, (*ite1).first, "Checking map[" + to_string((*ite2).first) + "]: ");
		checkOutputMap((*ite2).second, (*ite1).second, to_string((*ite2).second));
	}
}

template <typename T1, typename T2>
void checkBasicAttrMap(T1 &v, T2 &vreal)
{
	// checkOutputMap(v.capacity(), vreal.capacity(), "Checking Capacity...    ");
	checkOutputMap(v.size(), vreal.size(), "Checking Size...");
	checkArrayMap(v, vreal);
}

void mapInsert(void)
{
	std::cout << BOLDMAGENTA << "\nmap insert() single value testing..." << RESET << std::endl;

	ft::map<char, int> myMap;

	myMap.insert(ft::make_pair<char, int>('i', 10));
	myMap.insert(ft::make_pair<char, int>('j', 10));
	myMap.insert(ft::make_pair<char, int>('k', 10));
	myMap.insert(ft::make_pair<char, int>('l', 10));
	myMap.insert(ft::make_pair<char, int>('m', 10));
}

void mapConstructors(void)
{
	std::cout << BOLDMAGENTA << "\nmap Default Constructor testing..." << RESET << std::endl;

	ft::map<char, int> myMap;
	std::map<char, int> realMap;
	checkBasicAttrMap(myMap, realMap);

	std::cout << BOLDMAGENTA << "\nmap Iterators Constructor testing..." << RESET << std::endl;

	ft::map<char, int> tmp;
	tmp.insert(ft::make_pair('a', 10));
	// tmp.insert(ft::make_pair('b', 10));
	// tmp.insert(ft::make_pair('c', 10));
	print_tree(tmp._head, 0);
	ft::map<char, int>::iterator ite = tmp.begin();
	for (; ite != tmp.end(); ite++)
	{
		std::cout << "_head" << ite._head << std::endl;
		std::cout << "_end" << tmp.end()._head << std::endl;
		std::cout << "tmp index:" << (*ite).first << std::endl;
		std::cout << "tmp value:" << (*ite).second << std::endl;
	}
	// std::map<char, int> tmpReal;
	// tmpReal.insert(std::make_pair('a', 10));
	// tmpReal.insert(std::make_pair('b', 10));
	// tmpReal.insert(std::make_pair('c', 10));
	// tmpReal.insert(std::make_pair('d', 10));
	// tmpReal.insert(std::make_pair('e', 10));

	// print_tree(tmp._head, 0);
	// ft::map<char, int> myMap2(tmp.begin(), tmp.end());
	// std::map<char, int> realMap2(tmpReal.begin(), tmpReal.end());
	// checkBasicAttrMap(myMap2, realMap2);
}

#endif