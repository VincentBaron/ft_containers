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
#include <iostream>
#include <string>
#include "utils.hpp"
#include "iterator.hpp"
#include "RandomAccessIterator.hpp"
#include "reverse_iterator.hpp"

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
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTOR && DESTRUCTORS

		explicit vector(const allocator_type &alloc = allocator_type()) : _data(alloc)
		{
			_start = 0;
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

		virtual ~vector()
		{
			clear();
			_data.deallocate(_start, capacity());
		};
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
			_endCapacity = _start + rhs.capacity();
			_end = _start;
			pointer tmp = rhs._start;
			while (tmp != rhs._end)
			{
				_data.construct(_end, *tmp);
				tmp++;
				_end++;
			}
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
		template<class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
		{
			reallocate(last - first);

			pointer tmpStart = _start;
			while (tmpStart != _end && first != last)
			{
				_data.destroy(tmpStart);
				_data.construct(tmpStart, *first);
				tmpStart++;
				first++;
			}
			while (_end > tmpStart)
			{
				_end--;
				_data.destroy(_end);
			}
			while (first != last)
			{
				_data.construct(_end, *first);
				_end++;
				first++;
			}
		};
		
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
			while (_end > tmpStart)
			{
				_end--;
				_data.destroy(_end);
			}
			while (count > 0)
			{
				_data.construct(_end, value);
				_end++;
				count--;
			}
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

		iterator begin(void)
		{
			iterator tmp(_start);
			return (tmp);
		}

		const_iterator begin(void) const
		{
			const iterator tmp(_start);
			return (tmp);
		}

		iterator end(void)
		{
			iterator tmp(_end);
			return (tmp);
		}

		const_iterator end(void) const
		{
			const iterator tmp(_end);
			return (tmp);
		}

		reverse_iterator rbegin(void)
		{
			reverse_iterator tmp(_end);
			return (tmp);
		}

		const_reverse_iterator rbegin(void) const
		{
			const reverse_iterator tmp(_end);
			return (tmp);
		}

		reverse_iterator rend(void)
		{
			reverse_iterator tmp(_start);
			return (tmp);
		}

		const_reverse_iterator rend(void) const
		{
			const reverse_iterator tmp(_start);
			return (tmp);
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////////////// CAPACITY
		size_type size(void) const { return (this->_end - this->_start); };

		size_type capacity(void) const { return (this->_endCapacity - this->_start); };

		size_type max_size(void) const { return _data.max_size(); };

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
				pointer tmp = _start;
				while (tmp < _end)
				{
					_data.destroy(tmp);
					tmp++;
				}
			}
		};

		iterator insert (iterator position, const value_type& val)
		{
			size_type d = position - _start;
			reallocate(size() + 1);
			pointer newPos = _start + d;
			pointer tmp = _end - 1;
			while (tmp > newPos)
			{
				_data.construct(tmp, *(tmp - 1));
				--tmp;
			}
			_data.destroy(newPos);
			_data.construct(newPos, val);
			return (newPos);
		};

		void push_back(T elem)
		{
			reallocate(size() + 1);
			_data.construct(_end, elem);
			_end++;
		};

		void pop_back(void)
		{
			if (!size())
				throw std::length_error("Length error");
			_data.destroy(_end--);
		};

		void resize(size_type n, value_type val = value_type())
		{
			size_type originalSize = size();
			if (n < size())
			{
				while (n++ < originalSize)
				{
					_end--;
					_data.destroy(_end);
				}
			}
			else if (n > size())
			{
				reallocate(n);
				while (n > originalSize)
				{
					_data.construct(_end, val);
					_end++;
					n--;
				}
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
			else if (capacity() * 2 > _data.max_size())
				newCapacity = _data.max_size();
			else
				newCapacity = capacity() * 2;
			return (newCapacity);
		}

		void reallocate(size_t realocSize)
		{
			if (realocSize <= capacity())
				return;
			size_type newCapacity = calculateCapacity();
			reserve(newCapacity);
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};
}

#endif