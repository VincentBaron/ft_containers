/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:41:17 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/09 20:00:23 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include <iterator>
#include "utils.hpp"
#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference reference;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;
		typedef typename ft::random_access_iterator<const T> const_iterator;
		// Constructors and destructor
		random_access_iterator(void) : _data(0){};
		random_access_iterator(pointer ptr) : _data(ptr){};
		random_access_iterator(const random_access_iterator &src) : _data(src._data){};
		virtual ~random_access_iterator(){};

		// Operator overloads
		// random_access_iterator &operator=(const value_type value) {*(this->_data) = value;}
		random_access_iterator &operator=(const random_access_iterator &rhs)
		{
			if (*this == rhs)
				return (*this);
			this->_data = rhs._data;
			return (*this);
		};

		reference &operator*(void) { return *_data; };
		reference &operator[](difference_type idx) { return *(_data + idx); }
		const reference &operator*(void) const { return *_data; };
		const pointer operator->(void) const { return &(*_data); };

		bool operator==(const random_access_iterator &rhs) const { return (_data == rhs._data); }
		bool operator!=(const random_access_iterator &rhs) const { return (_data != rhs._data); }
		// bool operator!=(const_iterator &rhs) const { return (_data != rhs.base()); }
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
		difference_type operator-(const random_access_iterator &other) const { return (_data - other._data); }
		random_access_iterator operator+(difference_type i) const { return (_data + i); }
		random_access_iterator operator-(difference_type i) const { return _data - i; }
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

		operator const_iterator() const
		{
			const_iterator tmp(_data);
			return (tmp);
		};

		pointer base(void) { return (_data); };

	private:
		// Attributes
		pointer _data;
	};

	template <typename T>
	inline random_access_iterator<T> operator+(
		typename random_access_iterator<T>::difference_type i,
		const random_access_iterator<T> &other)
	{
		return other + i;
	}

	template <typename IteL, typename IteR>
	bool operator!=(ft::random_access_iterator<IteL> lhs, ft::random_access_iterator<IteR> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator==(ft::random_access_iterator<IteL> lhs, ft::random_access_iterator<IteR> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator<(ft::random_access_iterator<IteL> lhs, ft::random_access_iterator<IteR> rhs)
	{
		return (lhs.base() < rhs.base());
	}

		template <typename IteL, typename IteR>
	bool operator<=(ft::random_access_iterator<IteL> lhs, ft::random_access_iterator<IteR> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator>(ft::random_access_iterator<IteL> lhs, ft::random_access_iterator<IteR> rhs)
	{
		return (lhs.base() > rhs.base());
	}

		template <typename IteL, typename IteR>
	bool operator>=(ft::random_access_iterator<IteL> lhs, ft::random_access_iterator<IteR> rhs)
	{
		return (lhs.base() >= rhs.base());
	}
}

#endif