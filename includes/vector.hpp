/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:49:43 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/17 11:50:41 by vincentbaron      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#define MAX_SIZE 2305843009213693951
#include <iostream>
#include <string>
#include "utils.hpp"

namespace ft
{
	//////////////////////////////////////////////////////////////////////////////////////////////// NAMESPACE TYPEDEFS
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef unsigned long long int size_type;
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{

	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////CLASS TYPEDEFS
		typedef T value_type;
		typedef vector<T> vector_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::reference reference;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTOR && DESTRUCTORS

		explicit vector(const allocator_type &alloc = allocator_type()) : _data(alloc)
		{
			_start = _data.allocate(0);
			_end = _start;
			_endCapacity = _start;
		};

		explicit vector(size_type count, const T &value = T(), const allocator_type &alloc = allocator_type()) : _data(alloc)
		{
			_start = _data.allocate(count);
			_end = _start;
			_endCapacity = _start + count;
			while (count--)
			{
				_data.construct(_end, value);
				_end++;
			}
		};

		template <class InputIt>
		vector(InputIt first, InputIt last, allocator_type alloc = allocator_type(), typename ft::enable_if<!ft::isIntegral<InputIt>::value, InputIt>::type * = 0) : _data(alloc)
		{
			size_type count = last - first;
			_start = _data.allocate(count);
			_end = _start;
			_endCapacity = _start + count;
			while (count--)
			{
				_data.construct(_end, *first);
				_end++;
				first++;
			}

			_start = _data.allocate();
		};

		vector(const vector &other)
		{
			*this = other;
		};

		virtual ~vector(){};
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////// GETTERS && SETTERS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////// OPERATOR OVERLOADS
		vector_type &operator=(const vector &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->clear();
			_data.deallocate(_start, capacity());
			_start = _data.allocate(rhs.capacity());
			_end = _start;
			_endCapacity = rhs._start + rhs.capacity();
			pointer tmp = rhs._start;
			while (size() <= rhs.size())
			{
				_data.construct(_end, *tmp);
				tmp++;
				_end++;
			}
			_end--;
			return (*this);
		};

		reference operator[](size_type n)
		{
			rangeCheck(n);
			return (*(_start + n));
		}

		const reference operator[](size_type n) const
		{
			rangeCheck(n);
			return (*(_start + n));
		};
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////////////////////  MEMBER FUNCTIONS
		void assign(size_type count, const T &value)
		{
			reallocate(count);

			pointer tmpStart = _start;
			while (tmpStart != _end && count > 0)
			{
				_data.destroy(tmpStart);
				_data.construct(tmpStart, value);
				tmpStart++;
				count--;
			}
			while (tmpStart != _end)
				_data.destroy(_end--);
			while (count > 0)
				_data.construct(++_end, value);
		};

		allocator_type get_allocator() const { return _data; };
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////// ELEMENT ACCESS
		reference at(size_type n)
		{
			rangeCheck(n);
			return (*(_start + n));
		};

		const reference at(size_type n) const
		{
			rangeCheck(n);
			return (*(_start + n));
		};

		reference front(size_type n)
		{
			rangeCheck(n);
			return (*_start);
		};

		const reference front(size_type n) const
		{
			rangeCheck(n);
			return (*_start);
		};

		reference back(size_type n)
		{
			rangeCheck(n);
			return (*_end);
		};

		const reference back(size_type n) const
		{
			rangeCheck(n);
			return (*_end);
		};

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// ITERATORS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////////////// CAPACITY
		size_type size(void) const { return (this->_end - this->_start); };

		size_type capacity(void) const { return (this->_endCapacity - this->_start); };

		size_type max_size(void) const { return MAX_SIZE; };

		bool empty() const { return (!size() ? true : false); };

		void reserve(size_type n)
		{
			if (capacity() > n)
				return;
			vector_type tmp;
			tmp._start = tmp._data.allocate(n);
			tmp._end = tmp._start;
			tmp._endCapacity = tmp._start + n;
			pointer tmpStartPtr = _start;
			while (tmpStartPtr != _end)
			{
				tmp._data.construct(tmp._end, *tmpStartPtr);
				tmpStartPtr++;
				tmp._end++;
			}
			*this = tmp;
		};

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// MODIFIERS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		void clear(void)
		{
			if (size())
			{
				pointer tmp = _end;
				while (tmp >= _start)
				{
					_data.destroy(tmp);
					tmp--;
				}
			}
		};

		void push_back(T elem)
		{
			reallocate(size() + 1);
			_data.construct(_end++, elem);
		};

		void pop_back(void)
		{
			if (!size())
				throw std::length_error("Length error");
			_data.destroy(_end);
			_end--;
		};

		void resize (size_type n, value_type val = value_type())
		{
			size_type originalSize = size();
			if (n < size())
			{
				while (n++ < originalSize)
				{
					_data.destroy(_end);
					_end--;
				}
			}
			else if (n > size())
			{
				reallocate(n);
				while (n-- > originalSize)
					_data.construct(_end++, val);
			}
		};
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private:
		//////////////////////////////////////////////////////////////////////////////////////////////////////// ATTRIBUTES
		allocator_type _data;
		pointer _start;
		pointer _end;
		pointer _endCapacity;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////// MEMBER FUNCTIONS
		void rangeCheck(size_type index) const
		{
			if (index >= this->size())
				throw std::out_of_range("Out of range");
		}

		size_type calculateCapacity()
		{
			size_type newCapacity;
			if (capacity() == 0)
				newCapacity = 1;
			else if (capacity() * 2 > MAX_SIZE)
				newCapacity = MAX_SIZE;
			else
				newCapacity = capacity() * 2;
			return (newCapacity);
		}

		void reallocate(size_t realocSize)
		{
			if (realocSize < capacity())
				return;
			size_type newCapacity = calculateCapacity();
			reserve(newCapacity);
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};
}

#endif