/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:20:45 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/13 14:48:30 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iterator>

namespace ft {

template<typename>
struct isIntegral {static const bool value = false;};
template<>
struct isIntegral<bool> {static const bool value = true;};
template<>
struct isIntegral<char> {static const bool value = true;};
template<>
struct isIntegral<char16_t> {static const bool value = true;};
template<>
struct isIntegral<char32_t> {static const bool value = true;};
template<>
struct isIntegral<wchar_t> {static const bool value = true;};
template<>
struct isIntegral<short> {static const bool value = true;};
template<>
struct isIntegral<int> {static const bool value = true;};
template<>
struct isIntegral<long> {static const bool value = true;};
template<>
struct isIntegral<long long> {static const bool value = true;};

template<bool B, class T = void>
struct enable_if {};
template<class T>
struct enable_if<true, T> {typedef T type;};

}

#endif