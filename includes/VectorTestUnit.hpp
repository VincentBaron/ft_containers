/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTestUnit.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:13:07 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/07 18:23:03 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTUNIT_TPP
# define VECTORTESTUNIT_TPP
# include <vector>
# include <cstdlib>
# include "vector.hpp"
# include "utils.hpp"
# define SIZE 10
# define OFFSET 60
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

template <typename T>
bool tryOutOfRange(T vect)
{
	try
	{
		vect.at(12);
	}
	catch (const std::out_of_range &e)
	{
		return (true);
	}
	return (false);
}

template<typename T1, typename T2>
void checkOutput(T1 res1, T2 res2, std::string mssg)
{
	std::string offset = "";
	std::cout << YELLOW << mssg << RESET;
	if (res1 == res2)
		std::cout << BOLDGREEN << offset.insert(0, OFFSET - mssg.size(), ' ') << "SUCCESS!" << RESET << std::endl;
	else
	{
		std::cout << BOLDRED << offset.insert(0, OFFSET - mssg.size(), ' ') << "FAILURE!" << RESET << std::endl;
		std::cout << CYAN << "Output myVector: " << res1 << RESET << std::endl;
		std::cout << BLUE << "Output realVector: " << res2 << RESET << std::endl << std::endl;
	}
}

template<typename T>
void checkArray(ft::vector<T> &v, std::vector<T> &vreal)
{
	std::cout << "\n" << BRIGHTBLACK << "Checking _array...    " << RESET << std::endl;
	for (unsigned long long x = 0; x < vreal.size(); x++)
		checkOutput(v.at(x), vreal.at(x), "Checking _data[" + to_string(x) + "]...");
}

// template<typename Ite>
// void checkArray(Ite *vIte, Ite *vrealIte)
// {
// 	std::cout << "\n" << BRIGHTBLACK << "Checking _array...    " << RESET << std::endl;
// 	while (vIte)
// 		checkOutput(v.at(x), vreal.at(x), "Checking _data[" + to_string(x) + "]...");
// }

template <typename T>
void checkBasicAttr(ft::vector<T> &v, std::vector<T> &vreal)
{
	// checkOutput(v.capacity(), vreal.capacity(), "Checking Capacity...    ");
	checkOutput(v.size(), vreal.size(), "Checking Size...");
	checkArray(v, vreal);
}

void vectorSizeParameterConstructor(void)
{
	std::cout << BOLDMAGENTA << "\nVector Size constructor testing..." << RESET << std::endl;
	
	ft::vector<int> v(5);
	std::vector<int> vreal(5);

	checkBasicAttr(v, vreal);
}

void vectorSizeParameterAndValueConstructor(void)
{
	std::cout << BOLDMAGENTA << "\nVector Size and Value constructor testing..." << RESET << std::endl;

	ft::vector<int> v(5, 9);
	std::vector<int> vreal(5, 9);

	checkBasicAttr(v, vreal);
}

void vectorPushBack(void)
{
	std::cout << BOLDMAGENTA << "\nVector push_back() testing..." << RESET << std::endl;

	ft::vector<int> v;
	std::vector<int> vreal;

	v.push_back(42);
	v.push_back(43);
	v.push_back(44);
	vreal.push_back(42);
	vreal.push_back(43);
	vreal.push_back(44);
	checkBasicAttr(v, vreal);
}

void vectorPopBack(void)
{
	std::cout << BOLDMAGENTA << "\nVector pop_back() testing..." << RESET << std::endl;

	ft::vector<int> v(5, 42);
	std::vector<int> vreal(5, 42);

	try
	{
		vreal.pop_back();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		v.pop_back();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	checkBasicAttr(v, vreal);
}

void vectorGetAllocator(void)
{
	std::string mssg = "\nVector get_allocator() testing...";
	std::cout << BOLDMAGENTA << mssg << RESET << std::endl;
	
	ft::vector<int> v(5, 42);

	// std::cout << (v.get_allocator()) << std::endl;
	// if (v.get_allocator() == 42)
	// 	std::cout << BOLDGREEN << offset.insert(0, OFFSET - mssg.size(), ' ') << "SUCCESS!" << RESET << std::endl;
	// else
	// 	std::cout << BOLDRED << offset.insert(0, OFFSET - mssg.size(), ' ') << "FAILURE!" << RESET << std::endl;
}

void vectorEmpty(void)
{
	std::cout << BOLDMAGENTA << "\nVector empty() testing..." << RESET << std::endl;
	
	ft::vector<int> v;
	std::vector<int> vreal;

	checkOutput(v.empty(), vreal.empty(), "Checking on default Cosntructor...");
	v.push_back(42);
	vreal.push_back(42);
	checkOutput(v.empty(), vreal.empty(), "Checking not empty after push back...");
}

void vectorResize(void)
{
	std::cout << BOLDMAGENTA << "\nVector resize() testing..." << RESET << std::endl;
	
	ft::vector<int> v(2, 42);
	std::vector<int> vreal(2, 42);

	// v.resize(5);
	// vreal.resize(5);

	// checkBasicAttr(v, vreal);

	v.resize(3, 50);
	vreal.resize(3, 50);

	checkBasicAttr(v, vreal);

}

void vectorInsert(void)
{
	std::cout << BOLDMAGENTA << "\nVector insert() single value testing..." << RESET << std::endl;

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

	v.insert(vIte + 2, 78);
	vreal.insert(vrealIte + 2, 78);
	checkOutput(*(vIte + 2), *(vrealIte + 2), "Checking insert iterator value");
	checkBasicAttr(v, vreal);

	std::cout << BOLDMAGENTA << "\nVector insert() n count testing..." << RESET << std::endl;

	// v = ft::vector<int>();
	// vreal = std::vector<int>();

	v.insert(v.begin() + 2, 5, 78);
	vreal.insert(vreal.begin() + 2, 5, 78);
	checkBasicAttr(v, vreal);

	std::cout << BOLDMAGENTA << "\nVector insert() iterators testing..." << RESET << std::endl;

	v = ft::vector<int>();
	vreal = std::vector<int>();
	
	std::vector<int> tmp;
	for (long long x = 0; x < size; x++)
	{
		v.push_back(x);
		vreal.push_back(x);
		int val = rand() % 20;
		tmp.push_back(val);
	}
	
	v.insert(v.end() - 1, tmp.begin(), tmp.end() - 1);
	vreal.insert(vreal.end() - 1, tmp.begin(), tmp.end());
	checkBasicAttr(v, vreal);
}

void vectorAssign(void)
{
	std::cout << BOLDMAGENTA << "\nVector assign with count and value testing..." << RESET << std::endl;

	ft::vector<int> v;
	std::vector<int> vreal;

	v.assign(3, 42);
	vreal.assign(3, 42);
	
	// checkBasicAttr(v, vreal);

	// std::cout << BOLDMAGENTA << "\nVector assign with Iterators testing..." << RESET << std::endl;

	// ft::vector<int> tmp;
	// std::vector<int> tmpReal;

	// srand(time(NULL));
	// long long size = 6;

	// for (long long x = 0; x < size; x++)
	// {
	// 	int val = rand() % 20;
	// 	tmp.push_back(val);
	// 	tmpReal.push_back(val);
	// }
	// vreal.assign(tmpReal.begin(), tmpReal.begin() + 1);
	
	// checkBasicAttr(v, vreal);
	// checkArray(v, vreal);
}

void vectorErase(void)
{
	std::cout << BOLDMAGENTA << "\nVector erase() single position..." << RESET << std::endl;

	srand(time(NULL));
	long long size = 6;
	ft::vector<int> v;
	std::vector<int> vreal;

	for (long long x = 0; x < size; x++)
	{
		// int val = rand() % 20;
		v.push_back(x);
		vreal.push_back(x);
	} 
	v.erase(v.begin() + 2);
	vreal.erase(vreal.begin() + 2);

	checkBasicAttr(v, vreal);
	checkArray(v, vreal);

	std::cout << BOLDMAGENTA << "\nVector erase() iterators..." << RESET << std::endl;

	v.erase(v.begin() + 1, v.begin() + 2);
	vreal.erase(vreal.begin() + 1, vreal.begin() + 2);

	checkBasicAttr(v, vreal);
}

void vectorSwap(void)
{
	std::cout << BOLDMAGENTA << "\nVector swap..." << RESET << std::endl;

	srand(time(NULL));
	long long size = 6;
	ft::vector<int> v;
	ft::vector<int> vSwap;
	std::vector<int> vreal;
	std::vector<int> vrealSwap;

	for (long long x = 0; x < size; x++)
	{
		int val = rand() % 20;
		int valSwap = rand() % 20;
		v.push_back(val);
		vreal.push_back(val);
		vSwap.push_back(valSwap);
		vrealSwap.push_back(valSwap);
	}

	v.swap(vSwap);
	vreal.swap(vrealSwap);
	checkBasicAttr(v, vreal);
	checkBasicAttr(vSwap, vrealSwap);
	ft::swap(v, vSwap);
	std::swap(vreal, vrealSwap);
	std::cout << BOLDMAGENTA << "\nVector non-member swap..." << RESET << std::endl;
	checkBasicAttr(v, vreal);
	checkBasicAttr(vSwap, vrealSwap);
}

void vectorOperators(void)
{
	std::cout << BOLDMAGENTA << "\nVector erase() single position..." << RESET << std::endl;

	srand(time(NULL));
	long long size = 6;
	ft::vector<int> v;
	ft::vector<int> vComp;

	for (long long x = 0; x < size; x++)
	{
		int val = rand() % 20;
		v.push_back(val);
		vComp.push_back(val);
	}
	checkOutput(v == vComp, true, "Checking == operator");
	checkOutput(v != vComp, false, "Checking != operator");
	v.push_back(42);
	checkOutput(v == vComp, false, "Checking == operator");
	checkOutput(v != vComp, true, "Checking != operator");

	checkOutput(v < vComp, false, "Checking < operator");
	checkOutput(v <= vComp, false, "Checking <= operator");
	checkOutput(v > vComp, true, "Checking > operator");
	checkOutput(v >= vComp, true, "Checking >= operator");

}

void vectorDefaultConstructor(void)
{
	std::cout << BOLDMAGENTA << "\nVector default constructor testing..." << RESET << std::endl;
	
	ft::vector<int> v;
	std::vector<int> vreal;

	checkBasicAttr(v, vreal);
}

#endif

