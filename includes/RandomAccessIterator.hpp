/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:41:17 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/19 13:42:15 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR
#define RANDOMACCESSITERATOR

#include <iterator>

namespace ft
{
	template <typename T>
	class random_access_iterator_tag
	{

	public:
		typedef T difference_type;
		typedef typename T::pointer pointer;
		typedef typename T::reference reference;
		typedef typename T::value_type value_type;

		// Constructors and destructor
		random_access_iterator_tag(void) : _data(0) {};
		random_access_iterator_tag(pointer ptr) : _data(ptr) {};
		random_access_iterator_tag(const random_access_iterator_tag &src) : _data(src._data) {};
		virtual ~random_access_iterator_tag() {};

		// Operator overloads
		void operator=(const T value) {*(this->_data) = value;}
		random_access_iterator_tag &operator=(const random_access_iterator_tag &rhs)
		{
			if (*this == rhs)
				return (*this);
			this->_data = rhs._data;
			return (*this);
		};

		value_type &operator*(void) { return *_data; };
		const value_type &operator*(void) const { return *_data; };
		const pointer operator->(void) const { return &(*_data); };

		bool operator==(const random_access_iterator_tag &rhs) const { return (_data == rhs._data); }
		bool operator!=(const random_access_iterator_tag &rhs) const { return (_data != rhs._data); }
		bool operator<(const random_access_iterator_tag &rhs) const { return (_data < rhs._data); }
		bool operator>(const random_access_iterator_tag &rhs) const { return (_data > rhs._data); }
		bool operator<=(const random_access_iterator_tag &rhs) const { return (_data <= rhs._data); }
		bool operator>=(const random_access_iterator_tag &rhs) const { return (_data >= rhs._data); }
		random_access_iterator_tag &operator++()
		{
			_data++;
			return *this;
		}
		random_access_iterator_tag operator++(int)
		{
			random_access_iterator_tag ret = *this;
			_data++;
			return ret;
		}
		random_access_iterator_tag &operator--()
		{
			_data--;
			return *this;
		}
		random_access_iterator_tag operator--(int)
		{
			random_access_iterator_tag ret = *this;
			_data--;
			return ret;
		}
		difference_type operator-(const random_access_iterator_tag &other) const { return _data - other._data; }
		pointer operator+(difference_type i) const { return(_data + i); }
		pointer operator+(int i) const { return (_data + i); }
		random_access_iterator_tag operator-(difference_type i) const { _data - i; }
		random_access_iterator_tag &operator+=(difference_type i)
		{
			_data += i;
			return (*this);
		}
		random_access_iterator_tag &operator-=(difference_type i)
		{
			_data -= i;
			return (*this);
		}

	private:
		// Attributes
		pointer _data;
	};

	template <typename T>
	inline random_access_iterator_tag<T> operator+(
		typename random_access_iterator_tag<T>::difference_type i,
		const random_access_iterator_tag<T> &other)
	{
		return other + i;
	}
}

#endif