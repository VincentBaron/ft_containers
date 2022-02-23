/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:22:12 by vscode            #+#    #+#             */
/*   Updated: 2022/02/23 14:58:22 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <functional>
#include <memory>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "redBlackTree.hpp"
#include "BinaryTreeIterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef ft::Node<value_type> Node;
		typedef size_t size_type;

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
		typedef typename ft::binary_tree_iterator<Node> iterator;
		typedef typename ft::binary_tree_iterator<Node> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator> difference_type;

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _comp(comp), _head(NULL), TNULL(NULL), _alloc(alloc), _size(0){};

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
			: _comp(comp), _head(NULL), TNULL(NULL), _alloc(alloc), _size(0)
		{
			insert(first, last);
		};

		map(const map &x) : _comp(x._comp), _head(NULL), TNULL(NULL), _alloc(x._alloc), _size(0)
		{
			this->insert(x.begin(), x.end());
		};

		~map(void)
		{
			clear();
			_node_allocator(_alloc).destroy(TNULL);
			_node_allocator(_alloc).deallocate(TNULL, 1);
		}

		iterator begin()
		{
			return (iterator(minimum(_head), TNULL));
		};

		const_iterator begin() const
		{
			return (const_iterator(minimum(_head), TNULL));
		};

		iterator end()
		{
			if (!_size)
				return (begin());
			return (iterator(maximum(_head)->right, TNULL));
		};

		const_iterator end() const
		{
			if (!_size)
				return (begin());
			return (const_iterator(maximum(_head)->right, TNULL));
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(maximum(_head), TNULL));
		};

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(maximum(_head), TNULL));
		};

		reverse_iterator rend()
		{
			if (!_size)
				return (rbegin());
			return (reverse_iterator(minimum(_head)->left, TNULL));
		};

		const_reverse_iterator rend() const
		{
			if (!_size)
				return (rbegin());
			return (const_reverse_iterator(minimum(_head)->left, TNULL));
		};

		bool empty() const
		{
			return (!_size ? true : false);
		};

		size_type size(void)
		{
			return (_size);
		};

		size_type max_size() const
		{
			return (_node_alloc.max_size());
		};

		mapped_type &operator[](const key_type &k)
		{
			return (*(treeInsert(ft::make_pair(k, mapped_type())).first).second);
		};

		pair<iterator, bool> insert(const value_type &val)
		{
			return (insertTree(val));
		};

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return (insertTree(val).first);
		};

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
		{
			for (; first != last; ++first)
				insert(*first);
		};

		void erase(iterator position)
		{
			deleteTree((*position).first);
		};

		size_type erase(const key_type &k)
		{
			return (deleteTree(k));
		};

		void erase(iterator first, iterator last)
		{
			for (; first != last; first++)
				deleteTree((*first).first);
		};

		void clear(void)
		{
			erase(begin(), end());
		}

		iterator find(const key_type &k)
		{
			nodePtr ret = keySearch(_head, k);
			if (ret == TNULL)
				return (end());
			return (iterator(ret, TNULL));
		};

		const_iterator find(const key_type &k) const;

	public:
		typedef typename allocator_type::template rebind<Node>::other _node_allocator;
		typedef typename _node_allocator::pointer nodePtr;

		key_compare _comp;
		_node_allocator _node_alloc;
		nodePtr _head;
		nodePtr TNULL;
		allocator_type _alloc;
		size_type _size;

		nodePtr newNode(value_type elem)
		{
			nodePtr newNode = _node_alloc.allocate(1);
			_node_alloc.construct(newNode, Node(elem));
			newNode->left = TNULL;
			newNode->right = TNULL;
			newNode->parent = TNULL;
			return (newNode);
		}

		void deleteNode(nodePtr node)
		{
			_node_allocator(_alloc).destroy(node);
			_node_allocator(_alloc).deallocate(node, 1);
			_size--;
		}

		nodePtr keySearch(nodePtr start, key_type key)
		{
			while (start != TNULL && key != start->value.first)
			{
				if (key < start->value.first)
					start = start->left;
				else
					start = start->right;
			}
			return (start);
		}

		ft::pair<iterator, bool> insertTree(value_type value)
		{
			if (_head == NULL)
			{
				TNULL = _node_alloc.allocate(1);
				_node_alloc.construct(TNULL, Node());
				_head = TNULL;
				_head->right = TNULL;
				_head->left = TNULL;
			}
			nodePtr y = NULL;
			nodePtr node = newNode(value);
			nodePtr x = _head;
			while (x != TNULL)
			{
				y = x;
				if (node->value.first == x->value.first)
					return (ft::make_pair(iterator(node, TNULL), false));
				else if (node->value.first < x->value.first)
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == NULL)
				_head = node;
			else if (node->value.first < y->value.first)
				y->left = node;
			else
				y->right = node;
			if (node->parent == NULL)
			{
				node->color = BLACKT;
				_size++;
				if (node == maximum(_head))
					TNULL->parent = node;
				return (ft::make_pair(iterator(node, TNULL), true));
			}
			balanceTreeInsert(node);
			_size++;
			if (node == maximum(_head))
				TNULL->parent = node;
			return (ft::make_pair(iterator(node, TNULL), true));
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

		size_type deleteTree(const key_type &key)
		{
			nodePtr node = _head;
			nodePtr z = TNULL;
			nodePtr x, y;
			while (node != TNULL)
			{
				if (node->value.first == key)
					z = node;
				if (node->value.first <= key)
					node = node->right;
				else
					node = node->left;
			}

			if (z == TNULL)
				return 0;

			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				rbTransplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			deleteNode(z);
			if (y_original_color == 0)
				balanceTreeDelete(x);
			return (1);
		}

		void balanceTreeDelete(nodePtr x)
		{
			nodePtr s;
			while (x != _head && x->color == 0)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == 1)
					{
						s->color = 0;
						x->parent->color = 1;
						leftRotate(x->parent);
						s = x->parent->right;
					}

					if (s->left->color == 0 && s->right->color == 0)
					{
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->right->color == 0)
						{
							s->left->color = 0;
							s->color = 1;
							rightRotate(s);
							s = x->parent->right;
						}

						s->color = x->parent->color;
						x->parent->color = 0;
						s->right->color = 0;
						leftRotate(x->parent);
						x = _head;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == 1)
					{
						s->color = 0;
						x->parent->color = 1;
						rightRotate(x->parent);
						s = x->parent->left;
					}

					if (s->right->color == 0 && s->right->color == 0)
					{
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->left->color == 0)
						{
							s->right->color = 0;
							s->color = 1;
							leftRotate(s);
							s = x->parent->left;
						}

						s->color = x->parent->color;
						x->parent->color = 0;
						s->left->color = 0;
						rightRotate(x->parent);
						x = _head;
					}
				}
			}
			x->color = 0;
		}

		void rbTransplant(nodePtr u, nodePtr v)
		{
			if (u->parent == NULL)
				_head = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void leftRotate(nodePtr x)
		{
			nodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
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
			if (x->parent == NULL)
				_head = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		nodePtr minimum(nodePtr node) const
		{
			while (node != NULL && node->left != TNULL)
				node = node->left;
			return (node);
		}

		nodePtr maximum(nodePtr node) const
		{
			while (node != NULL && node->right != TNULL)
				node = node->right;
			return (node);
		}
	};
}

#endif