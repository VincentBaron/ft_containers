/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIteTest.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:02:14 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/19 13:42:59 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <vector>
# include <cstdlib>
# include "vector.hpp"
# include "utils.hpp"
# define SIZE 10
# define OFFSET 40
# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BRIGHTBLACK   "\033[90m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void vectorIterator(void)
{
	std::cout << BOLDMAGENTA << "\nVector random_access_iterator testing..." << RESET << std::endl;

	srand(time(NULL));
	long long size = 6;
	ft::vector<int> v;
	std::vector<int> vreal;

	for (long long x = 0; x < size; x++)
	{
		int val = rand() % 20;
		v.push_back(val);
		vreal.push_back(val);
	}
	ft::vector<int>::iterator vIte = v.begin();
	std::vector<int>::iterator vrealIte = vreal.begin();

	std::cout << YELLOW << "Testing iterator++...\n" << RESET;
	while (vIte != v.end() && vrealIte != vreal.end())
	{
		checkOutput(*vIte, *vrealIte, "");
		vIte++;
		vrealIte++;
	}
	std::cout << YELLOW << "Testing iterator--...\n" << RESET;
	while (vIte != v.begin() && vrealIte != vreal.begin())
	{
		vIte--;
		vrealIte--;
		checkOutput(*vIte, *vrealIte, "");
	}
	*(v.begin()) = 10;
	*(vreal.begin()) = 10;
	checkOutput(*(v.begin()), *(vreal.begin()), "Testing *Ite = value...");
	*(v.begin())--;
	*(vreal.begin())--;
	checkOutput(*(v.begin()), *(vreal.begin()), "Testing *Ite--...");
	*(v.begin())++;
	*(vreal.begin())++;
	checkOutput(*(v.begin()), *(vreal.begin()), "Testing *Ite++...");
	checkOutput(*(vIte + 2), *(vreal.begin() + 2), "Testing Ite + n...");

	// ft::vector<int>::iterator *vItePtr = &vIte;
	// std::vector<int>::iterator *vrealItePtr = &vrealIte;

	// checkOutput(vItePtr->, vrealItePtr->, "Testing Ite->");


}

#endif