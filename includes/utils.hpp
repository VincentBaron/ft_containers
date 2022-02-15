/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:20:45 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/15 17:01:21 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iterator>
#include <sstream>
# include <sys/time.h>

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
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec / 1000000 + tv.tv_usec);
}

void padding(char ch, int n)
{
	int i;

	for (i = 0; i < n; i++)
		std::cout << ch;
}

template<typename T>
void print_tree(T *root, int level)
{
	if (root == NULL)
	{
		padding('\t', level);
		std::cout << "[nill]" << std::endl;
	}
	else
	{
		print_tree(root->right, level + 1);
		padding('\t', level);
		std::cout << "[" << root->key << "]" << ":" << root->value;	
		std::cout << std::endl;
		print_tree(root->left, level + 1);
	}
}

#endif