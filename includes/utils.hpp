/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:20:45 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/25 11:13:50 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iterator>
#include <sstream>
#include <sys/time.h>
#define RESET "\033[0m"
#define BLACK "\033[30m"	   /* Black */
#define RED "\033[31m"		   /* Red */
#define BRIGHTBLACK "\033[90m" /* White */

namespace ft
{

	template <typename>
	struct isIntegral
	{
		static const bool value = false;
	};
	template <>
	struct isIntegral<bool>
	{
		static const bool value = true;
	};
	template <>
	struct isIntegral<char>
	{
		static const bool value = true;
	};
	// template<>
	// struct isIntegral<char16_t> {static const bool value = true;};
	// template<>
	// struct isIntegral<char32_t> {static const bool value = true;};
	template <>
	struct isIntegral<wchar_t>
	{
		static const bool value = true;
	};
	template <>
	struct isIntegral<short>
	{
		static const bool value = true;
	};
	template <>
	struct isIntegral<int>
	{
		static const bool value = true;
	};
	template <>
	struct isIntegral<long>
	{
		static const bool value = true;
	};
	template <>
	struct isIntegral<long long>
	{
		static const bool value = true;
	};

	template <bool B, class T = void>
	struct enable_if
	{
	};
	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		typedef typename T::difference_type difference_type;
		typedef typename T::value_type value_type;
		typedef typename T::pointer pointer;
		typedef typename T::reference reference;
		typedef typename T::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
		typedef typename T::difference_type difference_type;
		typedef typename T::value_type value_type;
		typedef typename T::pointer pointer;
		typedef typename T::reference reference;
		typedef typename T::iterator_category iterator_category;
	};

	template <typename T>
	void display(T begin, T end, std::string mssg)
	{
		std::cout << mssg << std::endl;
		for (; begin < end; begin++)
			std::cout << *begin << std::endl;
		std::cout << std::endl;

		std::cout << "------------" << std::endl;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class T1, class T2>
	struct pair
	{
	public:
		T1 first;
		T2 second;

		pair() : first(), second(){};

		pair(const T1 &x, const T2 &y) : first(x), second(y){};

		template <class X, class Y>
		pair(const pair<X, Y> &srcs) : first(srcs.first), second(srcs.second){};

		pair &operator=(const pair &rhs)
		{
			if (*this == rhs)
				return (*this);
			first = rhs.first;
			second = rhs.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
}

template <class T>
inline std::string to_string(const T &t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

long get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec / 1000000 + tv.tv_usec);
}

void padding(char ch, int n)
{
	int i;

	for (i = 0; i < n; i++)
		std::cout << ch;
}

template <typename T>
void print_treeBis(T *root, int level)
{
	if (root == NULL)
		return;
	if (root->nill)
	{
		padding('\t', level);
		std::cout << "[nill]" << std::endl;
		// std::cout << (root->color == 1 ? RED : BRIGHTBLACK) << "R: " << root->right << RESET;
	}
	else
	{
		print_treeBis(root->right, level + 1);
		padding('\t', level);
		std::cout << (root->color == 1 ? RED : BRIGHTBLACK) << "[" << root->value.first << "]"
				  << ":" << root->value.second << RESET;
		// std::cout << (root->color == 1 ? RED : BRIGHTBLACK) << "P: " << root << RESET;
		std::cout << std::endl;
		print_treeBis(root->left, level + 1);
	}
}

template<typename T>
void print_tree(T *root, int level)
{
	std::cout << "----------------------------------------" << std::endl;
	print_treeBis(root, level);
	std::cout << "----------------------------------------" << std::endl;
}

#endif