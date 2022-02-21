/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTreeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:02:26 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/21 11:33:10 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREEITERATOR_HPP
#define BINARYTREEITERATOR_HPP
#include "utils.hpp"

namespace ft
{
	template <typename T, class Compare>
	class binary_tree_iterator : ft::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename T::value_type value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;

		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;

		binary_tree_iterator(const Compare &comp = Compare()) : _head(), _nillNode(), _comp(comp){};

		binary_tree_iterator(T *head, T *nillNode, const Compare &comp = Compare()) : _head(head), _nillNode(nillNode), _comp(comp){};

		binary_tree_iterator(const binary_tree_iterator &srcs) : _head(srcs._head), _nillNode(srcs._nillNode), _comp(){};

		virtual ~binary_tree_iterator() {}

		binary_tree_iterator &operator=(const binary_tree_iterator &srcs)
		{
			if (*this == srcs)
				return (*this);
			this->_head = srcs._head;
			this->_nillNode = srcs._nillNode;
			this->_comp = srcs._comp;
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
				return (_head);
			}

			T *y = _head->parent;
			while (y != _nillNode && _head == y->right)
			{
				_head = y;
				y = y->parent;
			}
		}

		binary_tree_iterator operator++(int)
		{
			binary_tree_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		binary_tree_iterator &operator--(void)
		{
			if (_head->left != _nillNode)
			{
				_head = _head->left;
				while (_head->right != _nillNode)
					_head = _head->right;
				return (_head);
			}

			T *y = _head->parent;
			while (y != _nillNode && _head == y->left)
			{
				_head = y;
				y = y->parent;
			}
		}
		}

		binary_tree_iterator operator--(int)
		{
			binary_tree_iterator tmp(*this);
			operator--();
			return (tmp);
		}

	private:
		T *_head;
		T *_nillNode;
		Compare _comp;
	};

	template <typename T, class Compare>
	class binary_tree_const_iterator : ft::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename T::value_type value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;

		typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;

		binary_tree_const_iterator(const Compare &comp = Compare()) : _head(), _nillNode(), _comp(comp){};

		binary_tree_const_iterator(T *head, T *nillNode, const Compare &comp = Compare()) : _head(head), _nillNode(nillNode), _comp(comp){};

		binary_tree_const_iterator(const binary_tree_const_iterator &srcs) : _head(srcs._head), _nillNode(srcs._nillNode), _comp(){};

		binary_tree_const_iterator(const binary_tree_iterator<T, Compare>& srcs) : _node(srcs._node), _last_node(srcs._last_node), _comp() {}
		
		virtual ~binary_tree_const_iterator() {}

		binary_tree_const_iterator &operator=(const binary_tree_const_iterator &srcs)
		{
			if (*this == srcs)
				return (*this);
			this->_head = srcs._head;
			this->_nillNode = srcs._nillNode;
			this->_comp = srcs._comp;
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
				return (_head);
			}

			T *y = _head->parent;
			while (y != _nillNode && _head == y->right)
			{
				_head = y;
				y = y->parent;
			}
		}

		binary_tree_const_iterator operator++(int)
		{
			binary_tree_const_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		binary_tree_const_iterator &operator--(void)
		{
			if (_head->left != _nillNode)
			{
				_head = _head->left;
				while (_head->right != _nillNode)
					_head = _head->right;
				return (_head);
			}

			T *y = _head->parent;
			while (y != _nillNode && _head == y->left)
			{
				_head = y;
				y = y->parent;
			}
		}
		}

		binary_tree_const_iterator operator--(int)
		{
			binary_tree_const_iterator tmp(*this);
			operator--();
			return (tmp);
		}

	private:
		T *_head;
		T *_nillNode;
		Compare _comp;
	};
}

#endif