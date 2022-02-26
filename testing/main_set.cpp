/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:25:27 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/26 13:44:06 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/set.hpp"
# include <iostream>
#include <set>

#ifdef STD
	using namespace std;
#else
	using namespace ft;
#endif

void f1()
{
	int myints[] = {12, 82, 37, 64, 15};
	set<int> first(myints, myints + 5); // set with 5 ints
	set<int> second;					 // empty set

	second = first;			 // now second contains the 5 ints
	first = set<int>(); // and first is empty

	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
}

void f2()
{
	int myints[] = {75, 23, 65, 42, 13};
	set<int> myset(myints, myints + 5);

	std::cout << "myset contains:";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void f3()
{
	int myints[] = {75, 23, 65, 42, 13};
	set<int> myset(myints, myints + 5);

	std::cout << "myset contains:";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void f4()
{
	int myints[] = {21, 64, 17, 78, 49};
	set<int> myset(myints, myints + 5);

	set<int>::reverse_iterator rit;

	std::cout << "myset contains:";
	for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
		std::cout << ' ' << *rit;

	std::cout << '\n';
}

void f5()
{
	int myints[] = {21, 64, 17, 78, 49};
	set<int> myset(myints, myints + 5);

	set<int>::reverse_iterator rit;

	std::cout << "myset contains:";
	for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
		std::cout << ' ' << *rit;

	std::cout << '\n';
}

void f6()
{
	set<int> myset;

	myset.insert(20);
	myset.insert(30);
	myset.insert(10);

	std::cout << "myset contains:";
	while (!myset.empty())
	{
		std::cout << ' ' << *myset.begin();
		myset.erase(myset.begin());
	}
	std::cout << '\n';
}

void f7()
{
	set<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 10; ++i)
		myints.insert(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert(100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.erase(5);
	std::cout << "3. size: " << myints.size() << '\n';
}

void f8()
{
	int i;
	set<int> myset;

	if (myset.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			myset.insert(i);
		std::cout << "The set contains 1000 elements.\n";
	}
	else
		std::cout << "The set could not hold 1000 elements.\n";
}

void f9()
{
	set<int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator, bool> ret;

	// set some initial values:
	for (int i = 1; i <= 5; ++i)
		myset.insert(i * 10); // set: 10 20 30 40 50

	ret = myset.insert(20); // no new element inserted

	if (ret.second == false)
		it = ret.first; // "it" now points to element 20

	myset.insert(it, 25); // max efficiency inserting
	myset.insert(it, 24); // max efficiency inserting
	myset.insert(it, 26); // no max efficiency inserting

	int myints[] = {5, 10, 15}; // 10 already in set, not inserted
	myset.insert(myints, myints + 3);

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f10()
{
	set<int> myset;
	set<int>::iterator it;

	// insert some values:
	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	it = myset.begin();
	++it; // "it" points now to 20

	myset.erase(it);

	myset.erase(40);

	it = myset.find(60);
	myset.erase(it, myset.end());

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f11()
{
	int myints[] = {12, 75, 10, 32, 20, 25};
	set<int> first(myints, myints + 3);	  // 10,12,75
	set<int> second(myints + 3, myints + 6); // 20,25,32

	first.swap(second);

	std::cout << "first contains:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (set<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f12()
{
	set<int> myset;

	myset.insert(100);
	myset.insert(200);
	myset.insert(300);

	std::cout << "myset contains:";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myset.clear();
	myset.insert(1101);
	myset.insert(2202);

	std::cout << "myset contains:";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f13()
{
	set<int> myset;
	int highest;

	set<int>::key_compare mycomp = myset.key_comp();

	for (int i = 0; i <= 5; i++)
		myset.insert(i);

	std::cout << "myset contains:";

	highest = *myset.rbegin();
	set<int>::iterator it = myset.begin();
	do
	{
		std::cout << ' ' << *it;
	} while (mycomp(*(++it), highest));

	std::cout << '\n';
}

void f14()
{
	set<int> myset;

	set<int>::value_compare mycomp = myset.value_comp();

	for (int i = 0; i <= 5; i++)
		myset.insert(i);

	std::cout << "myset contains:";

	int highest = *myset.rbegin();
	set<int>::iterator it = myset.begin();
	do
	{
		std::cout << ' ' << *it;
	} while (mycomp(*(++it), highest));

	std::cout << '\n';
}

void f15()
{
	set<int> myset;
	set<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 5; i++)
		myset.insert(i * 10); // set: 10 20 30 40 50

	it = myset.find(20);
	myset.erase(it);
	myset.erase(myset.find(40));

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f16()
{
	set<int> myset;

	// set some initial values:
	for (int i = 1; i < 5; ++i)
		myset.insert(i * 3); // set: 3 6 9 12

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i;
		if (myset.count(i) != 0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
}

void f17()
{
	set<int> myset;
	set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	itlow = myset.lower_bound(30); //       ^
	itup = myset.upper_bound(60);  //                   ^

	myset.erase(itlow, itup); // 10 20 70 80 90

	std::cout << "myset contains:";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f18()
{
	set<int> myset;
	set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	itlow = myset.lower_bound(30); //       ^
	itup = myset.upper_bound(60);  //                   ^

	myset.erase(itlow, itup); // 10 20 70 80 90

	std::cout << "myset contains:";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void f19()
{
	set<int> myset;

	for (int i = 1; i <= 5; i++)
		myset.insert(i * 10); // myset: 10 20 30 40 50

	pair<set<int>::const_iterator, set<int>::const_iterator> ret;
	ret = myset.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}

void f20()
{
}

int main()
{
	f1();
	f2();
	f3();
	f4();
	f5();
	f6();
	f7();
	f8();
	f9();
	f10();
	f11();
	f12();
	f13();
	f14();
	f15();
	f16();
	f17();
	f18();
	f19();
	f20();
}