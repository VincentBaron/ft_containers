/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:20:45 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/17 09:11:21 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iterator>
#include <sstream>

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

}

template <class T>
inline std::string to_string(const T &t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

#endif