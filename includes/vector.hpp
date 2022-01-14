/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:49:43 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/14 15:15:52 by vincentbaro      ###   ########.fr       */
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
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////CLASS TYPEDEFS
		typedef vector<T> vector_type;
		typedef Allocator alloc_type;
		typedef typename Allocator::pointer alloc_ptr;
		typedef typename Allocator::reference alloc_ref;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTOR && DESTRUCTORS

		explicit vector(const alloc_type &alloc = alloc_type()) : _data(alloc), _start(0), _end(0), _endCapacity(0){};

		explicit vector(size_type count, const T &value = T(), const alloc_type &alloc = alloc_type()) : _data(alloc), _start(0), _end(0), _endCapacity(0)
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
		vector(InputIt first, InputIt last, alloc_type alloc = alloc_type(), typename ft::enable_if<!ft::isIntegral<InputIt>::value, InputIt>::type* = 0) : _data(alloc)
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
			_data.deallocate(_start, this->capacity());
			_data.allocate(rhs.capacity());
			_start = rhs._start;
			_end = rhs._end;
			_endCapacity = rhs._endCapacity;
			return (*this);
		};
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////////////////////  MEMBER FUNCTIONS
		void assign(size_type count, const T &value)
		{
			this->reserve(this->size() + count);
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////// ELEMENT ACCESS
		// T& at(size_type index)
		// {
		// 	rangeCheck(index);
		// 	return (this[index]);
		// }

		alloc_ref &data(void) const { return this->_data; }

		alloc_ref &operator[](size_type idx) const
		{
			alloc_ref elem = *_start;
			while (idx--)
				elem++;
			return (elem);
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// ITERATORS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////////////// CAPACITY
		size_type size(void) const { return (this->_end - this->_start); }

		size_type capacity(void) const { return (this->_endCapacity - this->_start); }

		size_type max_size(void) const { return MAX_SIZE; }

		void reserve(size_type n)
		{
			if (capacity() > n)
				return ;
			vector_type tmp;
			tmp._start = tmp._data.allocate(n);
			tmp._endCapacity = tmp._start + n;
			tmp._end = tmp._start;
			alloc_ptr oldStart = _start;
			while (size() > 0)
			{
				tmp._data.construct(tmp._end, *_start);
				_data.destroy(_start);
				_start++;
				tmp._end++;
			}
			_data.deallocate(oldStart, tmp.size());
			*this = tmp;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// MODIFIERS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		void clear(void)
		{
			while (this->size())
			{
				_data.destroy(_end);
				_end--;
			}
			_data.destroy(_end);
		}

		void push_back(T elem)
		{
			reallocate();
			_data.construct(_end + 1, elem);
		}


		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private:
		//////////////////////////////////////////////////////////////////////////////////////////////////////// ATTRIBUTES
		alloc_type _data;
		alloc_ptr _start;
		alloc_ptr _end;
		alloc_ptr _endCapacity;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////// MEMBER FUNCTIONS
		void rangeCheck(size_type index)
		{
			if (index >= this->size())
				throw std::out_of_range("Out of range");
		}

		size_type calculateCapacity(void)
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

		void reallocate(void)
		{
			if (size() < capacity())
				return ;
			size_type newCapacity = calculateCapacity();
			reserve(newCapacity);
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};
}

#endif