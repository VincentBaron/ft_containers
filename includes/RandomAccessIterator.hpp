/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:41:17 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/17 18:50:27 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR
#define RANDOMACCESSITERATOR

#include <iterator>

namespace ft
{
	template <typename T>
	class random_access_iterator
	{

	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T difference_type;

		// Constructors and destructor
		random_access_iterator(void) : _data(0);
		random_access_iterator(T *ptr) : _data(ptr);
		random_access_iterator(const random_access_iterator &src) : _data(src._data);
		virtual ~random_access_iterator();

		// Operator overloads
		random_access_iterator &operator=(const random_access_iterator &rhs)
		{
			if (*this == rhs)
				return (*this);
			this->_data = rhs._data;
			return (*this);
		};

		const T &operator*(void) const { return *_data; };
		const T *operator->(void) const { return &(*_data); };

		bool operator==(const random_access_iterator &rhs) const { return (_data == rhs._data); }
		bool operator!=(const random_access_iterator &rhs) const { return (_data != rhs._data); }
		bool operator<(const random_access_iterator &rhs) const { return (_data < rhs._data); }
		bool operator>(const random_access_iterator &rhs) const { return (_data > rhs._data); }
		bool operator<=(const random_access_iterator &rhs) const { return (_data <= rhs._data); }
		bool operator>=(const random_access_iterator &rhs) const { return (_data >= rhs._data); }
		random_access_iterator &operator++()
		{
			_data++;
			return *this;
		}
		random_access_iterator operator++(int)
		{
			random_access_iterator ret = *this;
			_data++;
			return ret;
		}
		random_access_iterator &operator--()
		{
			_data--;
			return *this;
		}
		random_access_iterator operator--(int)
		{
			random_access_iterator ret = *this;
			_data--;
			return ret;
		}
		difference_type operator-(const random_access_iterator &other) const { return _data - other._data; }
		random_access_iterator operator+(difference_type i) const { _data + i; }
		random_access_iterator operator+(difference_type i) const { _data - i; }
		random_access_iterator &operator+=(difference_type i)
		{
			_data += i;
			return (*this);
		}
		random_access_iterator &operator-=(difference_type i)
		{
			_data -= i;
			return (*this);
		}

	private:
		// Attributes
		T *_data;
	};

	template <typename T>
	inline RandomAccessIterator<T> operator+(
		typename RandomAccessIterator<T>::difference_type i,
		const RandomAccessIterator<T> &other)
	{
		return other + i;
	}
}

#endif