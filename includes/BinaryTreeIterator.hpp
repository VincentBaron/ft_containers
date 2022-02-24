/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTreeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:02:26 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/24 16:19:59 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREEITERATOR_HPP
#define BINARYTREEITERATOR_HPP
#include "utils.hpp"
#include "iterator.hpp"
#include "redBlackTree.hpp"

namespace ft
{
	template <typename Node>
	class binary_tree_const_iterator : ft::iterator<std::bidirectional_iterator_tag, Node>
	{
	public:
		typedef Node value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename Node::value_type *pointer;
		typedef typename Node::value_type reference;

		binary_tree_const_iterator() : _head(NULL), _nillNode(NULL){};

		binary_tree_const_iterator(Node *head, Node *nillNode) : _head(head), _nillNode(nillNode){};

		binary_tree_const_iterator(const binary_tree_const_iterator &srcs) : _head(srcs._head), _nillNode(srcs._nillNode){};

		virtual ~binary_tree_const_iterator() {}

		binary_tree_const_iterator &operator=(const binary_tree_const_iterator &srcs)
		{
			if (*this == srcs)
				return (*this);
			this->_head = srcs._head;
			this->_nillNode = srcs._nillNode;
			return (*this);
		}

		bool operator==(const binary_tree_const_iterator &rhs)
		{
			return (this->_head == rhs._head);
		}

		bool operator!=(const binary_tree_const_iterator &rhs)
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

		binary_tree_const_iterator &operator++(void)
		{
			if (_head->right != _nillNode)
			{
				_head = _head->right;
				while (_head->left != _nillNode)
					_head = _head->left;
				return (*this);
			}

			Node *y = _head->parent;
			while (y != NULL && _head == y->right)
			{
				_head = y;
				y = y->parent;
			}
			if (y == NULL)
				_head = _nillNode;
			else
				_head = y;
			return (*this);
		}

		binary_tree_const_iterator operator++(int)
		{
			binary_tree_const_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		binary_tree_const_iterator &operator--(void)
		{
			if (_head == _nillNode)
			{
				_head = _head->parent;
				return (*this);
			}

			if (_head->left != _nillNode)
			{
				_head = _head->left;
				while (_head->right != _nillNode)
					_head = _head->right;
				return (*this);
			}

			Node *y = _head->parent;
			while (y != NULL && _head == y->left)
			{
				_head = y;
				y = y->parent;
			}
			_head = y;
			return (*this);
		}

		binary_tree_const_iterator operator--(int)
		{
			binary_tree_const_iterator tmp(*this);
			operator--();
			return (tmp);
		}

	public:
		Node *_head;
		Node *_nillNode;
	};

	template <typename Node>
	class binary_tree_iterator : ft::iterator<std::bidirectional_iterator_tag, Node>
	{
	public:
		typedef Node value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename Node::value_type *pointer;
		typedef typename Node::value_type reference;
		typedef ft::binary_tree_const_iterator<Node> const_iterator;

		binary_tree_iterator() : _head(NULL), _nillNode(NULL){};

		binary_tree_iterator(Node *head, Node *nillNode) : _head(head), _nillNode(nillNode){};

		binary_tree_iterator(const binary_tree_iterator &srcs) : _head(srcs._head), _nillNode(srcs._nillNode){};

		virtual ~binary_tree_iterator() {}

		binary_tree_iterator &operator=(const binary_tree_iterator &srcs)
		{
			if (*this == srcs)
				return (*this);
			this->_head = srcs._head;
			this->_nillNode = srcs._nillNode;
			return (*this);
		}

		bool operator==(const binary_tree_iterator &rhs)
		{
			return (this->_head == rhs._head);
		}

		bool operator!=(const binary_tree_iterator &rhs)
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

		binary_tree_iterator &operator++(void)
		{
			if (_head->right != _nillNode)
			{
				_head = _head->right;
				while (_head->left != _nillNode)
					_head = _head->left;
				return (*this);
			}

			Node *y = _head->parent;
			while (y != NULL && _head == y->right)
			{
				_head = y;
				y = y->parent;
			}
			if (y == NULL)
				_head = _nillNode;
			else
				_head = y;
			return (*this);
		}

		binary_tree_iterator operator++(int)
		{
			binary_tree_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		binary_tree_iterator &operator--(void)
		{
			if (_head == _nillNode)
			{
				_head = _head->parent;
				return (*this);
			}

			if (_head->left != _nillNode)
			{
				_head = _head->left;
				while (_head->right != _nillNode)
					_head = _head->right;
				return (*this);
			}

			Node *y = _head->parent;
			while (y != NULL && _head == y->left)
			{
				_head = y;
				y = y->parent;
			}
			_head = y;
			return (*this);
		}

		binary_tree_iterator operator--(int)
		{
			binary_tree_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		operator const_iterator() const
		{
			const_iterator tmp(_head, _nillNode);
			return tmp;
		}

	public:
		Node *_head;
		Node *_nillNode;
	};

	template <typename It>
	bool operator==(ft::binary_tree_iterator<It> lhs, ft::binary_tree_iterator<It> rhs)
	{
		return (lhs._head == rhs._head);
	}

	template <typename It>
	bool operator==(ft::binary_tree_const_iterator<It> lhs, ft::binary_tree_const_iterator<It> rhs)
	{
		return (lhs._head == rhs._head);
	}
}

#endif