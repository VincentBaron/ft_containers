/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:47:59 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/01/20 12:39:49 by vincentbaro      ###   ########.fr       */
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
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _data(rev_it._data){};
		virtual ~reverse_iterator(){};
		// Operator overloads
		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_data - n)); };
		reverse_iterator operator-(difference_type i) const { return (reverse_iterator(_data - i)); }

		reference operator*(void) const
		{
			iterator_type tmp = _data;
			return (*(--tmp));
		};

		reverse_iterator &operator++()
		{
			_data--;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator ret = *this;
			_data--;
			return ret;
		}

		reverse_iterator &operator--()
		{
			_data++;
			return *this;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator ret = *this;
			_data++;
			return ret;
		}

		reverse_iterator &operator+=(difference_type i)
		{
			_data -= i;
			return (*this);
		}

		reverse_iterator &operator-=(difference_type i)
		{
			_data += i;
			return (*this);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[](difference_type n) const { return base()[-n - 1]; };
		// Getters / Setters

		// Member functions
		iterator_type base(void) const { return _data; };

	protected:
		// Attributes

	private:
		// Attributes
		iterator_type _data;
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return lhs.base() == rhs.base(); };

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return lhs.base() != rhs.base(); };

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) { return lhs.base() > rhs.base(); };

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return lhs.base() >= rhs.base(); };

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) { return lhs.base() < rhs.base(); };

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return lhs.base() <= rhs.base(); };

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it){return (rev_it + n);};

	template <class Iterator>
	reverse_iterator<Iterator> operator-(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it){return (rev_it - n);};

}

#endif