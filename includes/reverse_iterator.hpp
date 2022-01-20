/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:47:59 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/20 11:37:57 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
	template <typename Iterator>
	class reverse_iterator
	{

	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::size_type size_type;

		// Constructors and destructor
		reverse_iterator(void) : _data(0){};
		explicit reverse_iterator(iterator_type it) : _data(it){};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _data(rev_it.base()){};
		virtual ~reverse_iterator(){};
		// Operator overloads
		reverse_iterator &operator=(const reverse_iterator &rhs);

		// Getters / Setters

		// Member functions
		iterator_type base(void) const {return _data;};
		
		reference operator*(void) const 
		{
			iterator_type tmp = _data;
			return (*(--tmp));
		};

	protected:
		// Attributes

	private:
		// Attributes
		iterator_type _data;
	};
}

#endif