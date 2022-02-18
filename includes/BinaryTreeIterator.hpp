/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTreeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:02:26 by vincentbaro       #+#    #+#             */
/*   Updated: 2022/02/18 16:10:52 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREEITERATOR_HPP
# define BINARYTREEITERATOR_HPP
#include "utils.hpp"

namespace ft
{
	template <typename T, class Compare>
	class binary_tree_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;

			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

			binary_tree_iterator(const Compare& comp = Compare()) : _head(), niilNode(), _comp(comp) {};

			binary_tree_iterator(T * node_p, T * last_head, const Compare& comp = Compare()) : _head(node_p), niilNode(last_head), _comp(comp) {};

			binary_tree_iterator(const binary_tree_iterator& bst_it): _head(bst_it._head), niilNode(bst_it.niilNode), _comp() {};

			virtual ~binary_tree_iterator() { }

			binary_tree_iterator &operator=(const binary_tree_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_head = bst_it._head;
				this->niilNode = bst_it.niilNode;
				this->_comp = bst_it._comp;
				return (*this);
			}

			bool operator==(const binary_tree_iterator& bst_it)
			{ return (this->_head == bst_it._head); }

			bool operator!=(const binary_tree_iterator& bst_it)
			{ return (this->_head != bst_it._head); }

			reference operator*() const
			{ return (this->_head->value); }

			pointer operator->() const
			{ return (&this->_head->value); }

			binary_tree_iterator& operator++(void)
			{
				T* cursor = _head;

				if (_head->right == niilNode)
				{
					cursor = _head->parent;
					while (cursor != niilNode
						&& _comp(cursor->value.first, _head->value.first))
						cursor = cursor->parent;
					_head = cursor;
				}
				else if (cursor == niilNode)
					_head = niilNode->right;
				else
				{
					cursor = _head->right;
					if (cursor == niilNode->parent
						&& cursor->right == niilNode)
						_head = cursor;
					else
					{
						while (cursor->left != niilNode)
							cursor = cursor->left;
					}
					_head = cursor;
				}
				return (*this);
			}

			binary_tree_iterator operator++(int)
			{
				binary_tree_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			binary_tree_iterator& operator--(void)
			{
				T* cursor = _head;

				if (_head->left == niilNode)
				{
					cursor = _head->parent;
					while (cursor != niilNode
						&& !_comp(cursor->value.first, _head->value.first))
						cursor = cursor->parent;
					_head = cursor;
				}
				else if (cursor == niilNode)
					_head = niilNode->right;
				else
				{
					cursor = _head->left;
					if (cursor == niilNode->parent
						&& cursor->left == niilNode)
						_head = cursor;
					else
					{
						while (cursor->right != niilNode)
							cursor = cursor->right;
					}
					_head = cursor;
				}
				return (*this);
			}

			binary_tree_iterator operator--(int)
			{
				binary_tree_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			private:         

			T *			_head;
			T *			niilNode;
			Compare     _comp;
	};

	template <typename T, class Compare >
	class binary_tree_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type    value_type;

			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;


			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type   difference_type;

			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer   pointer;

			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

			
			binary_tree_const_iterator(const Compare& comp = Compare())
			:
				_head(),
				niilNode(),
				_comp(comp)
			{}

			binary_tree_const_iterator(T * node_p, T * last_head,
						const Compare& comp = Compare())
			:
				_head(node_p),
				niilNode(last_head),
				_comp(comp)
			{}

			binary_tree_const_iterator(const binary_tree_const_iterator& bst_it)
			:
				_head(bst_it._head),
				niilNode(bst_it.niilNode),
				_comp()
			{}

			binary_tree_const_iterator(const binary_tree_iterator<T, Compare>& bst_it)
			:
				_head(bst_it._head),
				niilNode(bst_it.niilNode),
				_comp()
			{}

			virtual ~binary_tree_const_iterator() { }

			binary_tree_const_iterator &operator=(const binary_tree_const_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				this->_head = bst_it._head;
				this->niilNode = bst_it.niilNode;
				this->_comp = bst_it._comp;
				return (*this);
			}
			
			bool operator==(const binary_tree_const_iterator& bst_it)
			{ return (this->_head == bst_it._head); }

			bool operator!=(const binary_tree_const_iterator& bst_it)
			{ return (this->_head != bst_it._head); }

			reference operator*() const
			{ return (this->_head->value); }

			pointer operator->() const
			{ return (&this->_head->value); }

			binary_tree_const_iterator& operator++(void)
			{
				T * cursor = _head;

				if (_head->right == niilNode)
				{
					cursor = _head->parent;
					while (cursor != niilNode
						&& _comp(cursor->value.first, _head->value.first))
						cursor = cursor->parent;
					_head = cursor;
				}
				else if (cursor == niilNode)
					_head = niilNode->right;
				else
				{
					cursor = _head->right;
					if (cursor == niilNode->parent
						&& cursor->right == niilNode)
						_head = cursor;
					else
					{
						while (cursor->left != niilNode)
							cursor = cursor->left;
					}
					_head = cursor;
				}
				return (*this);
			}

			binary_tree_const_iterator operator++(int)
			{
				binary_tree_const_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			binary_tree_const_iterator& operator--(void)
			{
				T * cursor = _head;

				if (_head->left == niilNode)
				{
					cursor = _head->parent;
					while (cursor != niilNode
						&& !_comp(cursor->value.first, _head->value.first))
						cursor = cursor->parent;
					_head = cursor;
				}
				else if (cursor == niilNode)
					_head = niilNode->right;
				else
				{
					cursor = _head->left;
					if (cursor == niilNode->parent
						&& cursor->left == niilNode)
						_head = cursor;
					else
					{
						while (cursor->right != niilNode)
							cursor = cursor->right;
					}
					_head = cursor;
				}
				return (*this);
			}

			binary_tree_const_iterator operator--(int)
			{
				binary_tree_const_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			private:       

			T *         _head;
			T *         niilNode;
			Compare     _comp;
	};
}

#endif