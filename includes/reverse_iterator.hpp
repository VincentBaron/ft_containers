/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:47:59 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/23 17:29:44 by vscode           ###   ########.fr       */
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
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::value_type value_type;

		// Constructors and destructor
		reverse_iterator(void) : _data(){};
		explicit reverse_iterator(iterator_type it) : _data(it){};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _data(rev_it.base()){};
		virtual ~reverse_iterator(){};
		// Operator overloads
		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_data - n)); };
		reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_data + n)); }

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

	template <typename IteL, typename IteR>
	bool operator!=(ft::reverse_iterator<IteL> lhs, ft::reverse_iterator<IteR> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator==(ft::reverse_iterator<IteL> lhs, ft::reverse_iterator<IteR> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator<(ft::reverse_iterator<IteL> lhs, ft::reverse_iterator<IteR> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator<=(ft::reverse_iterator<IteL> lhs, ft::reverse_iterator<IteR> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator>(ft::reverse_iterator<IteL> lhs, ft::reverse_iterator<IteR> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename IteL, typename IteR>
	bool operator>=(ft::reverse_iterator<IteL> lhs, ft::reverse_iterator<IteR> rhs)
	{
		return (lhs.base() <= rhs.base());
	}


	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it) { return (rev_it + n); };

    template <class Ite>
        typename reverse_iterator<Ite>::difference_type operator-(
            const reverse_iterator<Ite>& lhs,
            const reverse_iterator<Ite>& rhs) { return (lhs.base() - rhs.base()); }

    template <class IteL, class IteR>
        typename reverse_iterator<IteL>::difference_type operator-(const reverse_iterator<IteL>& lhs,
                        const reverse_iterator<IteR>& rhs) { return -1 * (lhs.base() - rhs.base()); }

}

#endif