/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:02:26 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/26 11:14:43 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP
#include "utils.hpp"
#include "iterator.hpp"
#include "redBlackTree.hpp"

namespace ft
{
	class ft::set_iterator;
	
	template <typename Pair, typename Node>
	class set_const_iterator : ft::iterator<std::bidirectional_iterator_tag, Node>
	{
	public:
		typedef Node value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef const Pair *pointer;
		typedef const Pair &reference;

		set_const_iterator() : _head(NULL){};

		set_const_iterator(Node *head) : _head(head){};

		set_const_iterator(const set_const_iterator &srcs) : _head(srcs._head){};

		virtual ~set_const_iterator() {}

		bool operator==(const set_const_iterator &rhs)
		{
			return (this->_head == rhs._head);
		}

		bool operator!=(const set_const_iterator &rhs)
		{
			return (this->_head != rhs._head);
		}

		reference operator*() const
		{
			return (this->_head->value);
		}

		pointer operator->() const
		{
			return (&this->_head->value);
		}

		set_const_iterator &operator++(void)
		{
			if (_head->nill)
				return (*this);
			if (_head->right && !_head->right->nill)
			{
				_head = _head->right;
				while (!_head->left->nill)
					_head = _head->left;
				return (*this);
			}

			Node *x = _head;
			Node *y = x->parent;
			while (y != NULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			if (y == NULL)
				_head = _head->right;
			else
				_head = y;
			return (*this);
		}

		set_const_iterator operator++(int)
		{
			set_const_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		set_const_iterator &operator--(void)
		{
			if (_head->left && !_head->left->nill)
			{
				_head = _head->left;
				while (!_head->right->nill)
					_head = _head->right;
				return (*this);
			}

			Node *x = _head;
			Node *y = x->parent;
			while (y != NULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			if (y == NULL)
				return (*this);
			else
				_head = y;
			return (*this);
		}

		set_const_iterator operator--(int)
		{
			set_const_iterator tmp(*this);
			operator--();
			return (tmp);
		}

	public:
		Node *_head;
	};

	template <typename Pair, typename Node>
	class set_iterator : ft::iterator<std::bidirectional_iterator_tag, Node>
	{
	public:
		typedef Node value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef const Pair *pointer;
		typedef const Pair &reference;
		typedef ft::set_const_iterator<Pair, Node> const_iterator;

		set_iterator() : _head(NULL){};

		set_iterator(Node *head) : _head(head){};

		set_iterator(const set_iterator &srcs) : _head(srcs._head){};

		set_iterator &operator=(const set_iterator &srcs)
		{
			if (*this == srcs)
				return (*this);
			this->_head = srcs._head;
			return (*this);
		}

		virtual ~set_iterator() {}

		bool operator==(const set_iterator &rhs)
		{
			return (this->_head == rhs._head);
		}

		bool operator!=(const set_iterator &rhs)
		{
			return (this->_head != rhs._head);
		}

		reference operator*() const
		{
			return (this->_head->value);
		}

		pointer operator->() const
		{
			return (&this->_head->value);
		}

		set_iterator &operator++(void)
		{
			if (_head->nill)
				return (*this);
			if (_head->right && !_head->right->nill)
			{
				_head = _head->right;
				while (!_head->left->nill)
					_head = _head->left;
				return (*this);
			}

			Node *x = _head;
			Node *y = x->parent;
			while (y != NULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			if (y == NULL)
				_head = _head->right;
			else
				_head = y;
			return (*this);
		}

		set_iterator operator++(int)
		{
			set_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		set_iterator &operator--(void)
		{
			if (_head->left && !_head->left->nill)
			{
				_head = _head->left;
				while (!_head->right->nill)
					_head = _head->right;
				return (*this);
			}

			Node *x = _head;
			Node *y = x->parent;
			while (y != NULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			if (y == NULL)
				return (*this);
			else
				_head = y;
			return (*this);
		}

		set_iterator operator--(int)
		{
			set_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		operator const_iterator() const
		{
			const_iterator tmp(_head);
			return tmp;
		}

	public:
		Node *_head;
	};

	template <typename Pair, typename It>
	bool operator==(ft::set_iterator<Pair, It> lhs, ft::set_iterator<Pair, It> rhs)
	{
		return (lhs._head == rhs._head);
	}

	template <typename Pair, typename It>
	bool operator==(ft::set_const_iterator<Pair, It> lhs, ft::set_const_iterator<Pair, It> rhs)
	{
		return (lhs._head == rhs._head);
	}
}

#endif