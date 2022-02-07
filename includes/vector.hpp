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
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////CLASS TYPEDEFS
		typedef T value_type;
		typedef vector<T, Alloc> vector_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::difference_type difference_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::size_type size_type;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTOR && DESTRUCTORS

		explicit vector(const allocator_type &alloc = allocator_type()) : _data(alloc), _start(0), _end(0), _endCapacity(0)
		{};

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

		vector(const vector &other) : _data(other._data), _start(0), _end(0), _endCapacity(0)
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
		vector &operator=(const vector &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->clear();
			if (capacity())
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
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
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
			const_iterator tmp(_start);
			return (tmp);
		}

		iterator end(void)
		{
			iterator tmp(_end);
			return (tmp);
		}

		const_iterator end(void) const
		{
			const_iterator tmp(_end);
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
			display(tmp.begin(), tmp.end(), "Displaying tmp...");
			std::cout << "tmp.size()" << tmp.size() << std::endl;
			std::cout << "tmp.capacity()" << tmp.capacity() << std::endl;
			*this = tmp;
		};

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// MODIFIERS

		iterator erase(iterator position)
		{
			vector_type tmp;
			tmp.reserve(size() - (position - begin()));
			for (iterator tmpIte = position + 1; tmpIte < end(); tmpIte++)
				tmp.add_back(*tmpIte);
			for (pointer tmpPtr = _start + (position - begin()); tmpPtr < _end; tmpPtr++)
				_data.destroy(tmpPtr);
			_end = _start + (position - begin());
			for (iterator tmpIte = tmp.begin(); tmpIte < tmp.end(); tmpIte++)
				add_back(*tmpIte);
			return (position);
		};

		iterator erase(iterator first, iterator last)
		{
			vector_type tmp;
			tmp.reserve(end() - last - 1);
			for (iterator tmpIte = last; tmpIte < end(); tmpIte++)
				tmp.add_back(*tmpIte);
			for (pointer tmpPtr = _start + (first - begin()); tmpPtr < _end; tmpPtr++)
				_data.destroy(tmpPtr);
			_end = _start + (first - begin());
			for (iterator tmpIte = tmp.begin(); tmpIte < tmp.end(); tmpIte++)
				add_back(*tmpIte);
			return (first);
		};

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

		iterator insert(iterator position, const value_type &val)
		{
			vector_type tmp;
			tmp.reserve(size() - (position - begin()));
			for (iterator ite = end() - 1; ite >= position; ite--)
				tmp.add_back(*ite);
			difference_type dist = position - begin();
			reallocate(size() + 1);
			for (pointer tmpPtr = _start + dist; tmpPtr < _end; tmpPtr++)
				_data.destroy(tmpPtr);
			_end = _start + dist;
			add_back(val);
			for (iterator tmpIte = tmp.end() - 1; tmpIte >= tmp.begin(); tmpIte--)
				add_back(*tmpIte);
			return (_start + dist);
		};

		void insert(iterator position, size_type n, const value_type &val)
		{
			vector_type tmp;
			tmp.reserve(size() - (position - begin()));
			for (iterator ite = end() - 1; ite >= position; ite--)
				tmp.add_back(*ite);
			difference_type dist = position - begin();
			reallocate(size() + n);
			for (pointer tmpPtr = _start + dist; tmpPtr < _end; tmpPtr++)
				_data.destroy(tmpPtr);
			_end = _start + dist;
			for (n; n > 0; n--)
				add_back(val);
			for (iterator tmpIte = tmp.end() - 1; tmpIte >= tmp.begin(); tmpIte--)
				add_back(*tmpIte);
		};

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
		{
			difference_type n = 0;
			for (InputIterator tmp = first; tmp <= last; tmp++)
				n++;
			difference_type dist = position - begin();
			vector_type tmp;
			tmp.reserve(size() - (position - begin()));
			for (iterator ite = end() - 1; ite >= position; ite--)
				tmp.add_back(*ite);
			reallocate(size() + n);
			for (pointer tmpPtr = _start + dist; tmpPtr < _end; tmpPtr++)
				_data.destroy(tmpPtr);
			_end = _start + dist;
			for (first; first <= last; first++)
				add_back(*first);
			for (iterator tmpIte = tmp.end() - 1; tmpIte >= tmp.begin(); tmpIte--)
				add_back(*tmpIte);
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

		void swap(vector &x)
		{
			if (*this == x)
				return;

			pointer tmpStart = _start;
			pointer tmpEnd = _end;
			pointer tmpCapacity = _endCapacity;
			allocator_type tmpData = _data;

			_start = x._start;
			_end = x._end;
			_endCapacity = x._endCapacity;
			_data = x._data;

			x._start = tmpStart;
			x._end = tmpEnd;
			x._endCapacity = tmpCapacity;
			x._data = tmpData;
		}

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

		size_type calculateCapacity(size_type realocSize)
		{
			size_type newCapacity = capacity();
			if (capacity() * 2 > _data.max_size())
				newCapacity = _data.max_size();
			else
			{
				if (capacity() == 0)
					newCapacity = 1;
				while (newCapacity < realocSize)
					newCapacity *= 2;
			}
			return (newCapacity);
		}

		void reallocate(size_t realocSize)
		{
			if (realocSize <= capacity())
				return;
			size_type newCapacity = calculateCapacity(realocSize);
			reserve(newCapacity);
		}

		void add_back(T elem)
		{
			_data.construct(_end, elem);
			_end++;
		};
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		typedef typename vector<T>::const_iterator const_iterator;

		if (lhs.size() != rhs.size())
			return (false);
		for (const_iterator lhsIte = lhs.begin(), rhsIte = rhs.begin(); lhsIte < lhs.end() && rhsIte < rhs.end(); lhsIte++, rhsIte++)
		{
			if (*lhsIte != *rhsIte)
				return (false);
		}
		return (true);
	};

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	};
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ( rhs < lhs);
	};
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);	
	};

}

#endif