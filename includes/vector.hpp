/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:49:43 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/10 20:25:28 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#define MAX_SIZE 2305843009213693951
#include <iostream>
#include <string>

namespace ft
{
	//////////////////////////////////////////////////////////////////////////////////////////////// NAMESPACE TYPEDEFS
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef unsigned long long int size_type;
	template <class T, class Alocator = std::allocator<T> >
	class vector
	{

	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////CLASS TYPEDEFS
		typedef vector<T> vector_type;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTOR && DESTRUCTORS

		explicit vector( const Allocator& alloc ) : _data(alloc), _start(u_nullptr), _end(u_nullptr), _endCapacity(u_nullptr) {};

		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _data(alloc), _start(u_nullptr), _end(u_nullptr), _endCapacity(u_nullptr)
		{
			_start = _data.allocate(count);
			_end = _start;
			_endCapacity = _start + count;
			while (n--)
			{
				_alloc.construct(_end, value);
				_end++;
			}
		};

		// template< class InputIt >
		// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );

		vector( const vector& other )
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
			this->_data.alocate(rhs.capacity());
			this->_start = rhs._start;
			this->_end = rhs._end;
			this->_endCapacity = rhs._endCapacity;
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
		T& at(size_type index)
		{
			rangeCheck(index);
			return (this->_data[index]);
		}

		T& data(void) const {return this->_data;}

		T& operator[](size_type idx) const {return this->_data[idx];}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// ITERATORS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////////////// CAPACITY
		size_type size(void) const {return (this->_end - this->_begin);}

		size_type capacity(void) const {return (this->_endCapacity - this->_start);}

		size_type max_size(void) const {return MAX_SIZE;}

		void reserve(size_type n)
		{
			if (n > this->capacity())
			{
				if (n > MAX_SIZE)
					throw std::length_error("Required memory exceeds vector maximum storage");
				vector_type newVector;
				newVector._start = newVector._data.alocate(n);
				newVector._end = newVector._start;
				newVector._endCapacity = n;
				for (size_t x = 0; x < this->size(); x++)
					newAlocator[x] = this->Alocator.;
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////// MODIFIERS
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		void push_back(T elem)
		{
			reserve();
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	protected:
	private:
		//////////////////////////////////////////////////////////////////////////////////////////////////////// ATTRIBUTES
		Alocator<T> *_data;
		Alocator<T>::pointer _start;
		Alocator<T>::pointer _end;
		Alocator<T>::pointer _endCapacity;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////// MEMBER FUNCTIONS
		T *initArrayNull(size_type initial_size) const
		{
			T *arr = new T[initial_size];
			for (size_type i = 0; i < initial_size; i++)
				arr[i] = 0;
			return (arr);
		};

		void rangeCheck(size_type index)
		{
			if (index >= this->size())
				throw std::out_of_range("Out of range");
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};
}

#endif