/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:16:05 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/19 11:48:07 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "RandomAccessIterator.hpp"

namespace ft
{
	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator : public Category 
	{
	
		public:
	
			typedef Category iterator_category;
			typedef Distance difference_type;
			typedef T value_type;
			typedef typename T::pointer pointer;
			typedef typename T::reference reference;

			// Constructors and destructor
			iterator() : Category() {};
			iterator(pointer ptr) : Category(ptr) {};
			iterator(const iterator &src) : Category(src) {};
			virtual ~iterator();
	
			// Operator overloads
			iterator&	operator=(const iterator &rhs)
			{
				if (*this == rhs)
					return (*this);
				this->_data = rhs._data;
				return (*this);
			};
	
			// Getters / Setters
	
			// Member functions
	
		protected:
	
			// Attributes
	
		private:
	
			// Attributes

	
	};
}

#endif