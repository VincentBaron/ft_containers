/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:22:12 by vscode            #+#    #+#             */
/*   Updated: 2022/02/17 15:07:49 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include <memory>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "redBlackTree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef ft::Node<key_type, mapped_type, value_type> Node;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map<Key, T, Compare, Alloc>;

		protected:
			key_compare comp;
			value_compare(key_compare c) : comp(c) {}

		public:
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};

		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		// typedef ft::bidirectional_iterator<value_type> iterator;
		// typedef ft::bidirectional_iterator<const value_type> const_iterator;
		// typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		// typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// typedef typename ft::iterator_traits<iterator> difference_type;
		typedef typename Alloc::size_type size_type;

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _comp(comp), _head(NULL), _alloc(alloc){};

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		map(const map &x);

		bool insert(const value_type &val)
		{
			if (keySearch(_head, val.first) != NULL)
				return (false);
			insertTree(val);
			return (true);
		};

		// iterator insert(iterator position, const value_type &val);

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last);

	public:
		typedef typename allocator_type::template rebind<Node>::other _node_allocator;
		typedef typename _node_allocator::pointer nodePtr;

		key_compare _comp;
		_node_allocator _node_alloc;
		nodePtr _head;
		nodePtr TNULL;
		allocator_type _alloc;

		nodePtr newNode(value_type elem)
		{
			nodePtr newNode = _node_alloc.allocate(1);
			_node_alloc.construct(newNode, Node(elem));
			newNode->left = TNULL;
			newNode->right = TNULL;
			return (newNode);
		}

		nodePtr keySearch(nodePtr start, key_type key)
		{
			while (start != NULL && key != start->key)
			{
				if (key < start->key)
					start = start->left;
				else
					start = start->right;
			}
			return (start);
		}

		void insertTree(value_type value)
		{
			if (_head == NULL)
			{
				TNULL = _node_alloc.allocate(1);
				_node_alloc.construct(TNULL, Node());
				_head = TNULL;
			}
			nodePtr y = NULL;
			nodePtr node = newNode(value);
			nodePtr x = _head;
			while (x != TNULL)
			{
				y = x;
				if (node->key < x->key)
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == NULL)
				_head = node;
			else if (node->key < y->key)
				y->left = node;
			else
				y->right = node;
			if (node->parent == NULL)
			{
				node->color = BLACKT;
				return;
			}
			balanceTreeInsert(node);
		}

		void balanceTreeInsert(nodePtr k)
		{
			nodePtr u;
			while (k->parent->color == 1)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (u->color == 1)
					{
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;

					if (u->color == 1)
					{
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							leftRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						rightRotate(k->parent->parent);
					}
				}
				if (k == _head)
				{
					break;
				}
			}
			_head->color = 0;
		}

		void leftRotate(nodePtr x)
		{
			nodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				_head = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void rightRotate(nodePtr x)
		{
			nodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				_head = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
	};
}

#endif