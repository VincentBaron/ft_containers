/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:22:12 by vscode            #+#    #+#             */
/*   Updated: 2022/02/26 09:12:52 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include <functional>
#include <memory>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "redBlackTree.hpp"
#include "BinaryTreeIterator.hpp"

namespace ft
{
	template <class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const T, T> > >
	class set
	{
	public:
		typedef T key_type;
		typedef T value_type;
		typedef T mapped_type;
		typedef Compare key_compare;
		typedef ft::Node<value_type> Node;
		typedef size_t size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map<T, Compare, Alloc>;

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
		typedef class ft::binary_tree_iterator<value_type, Node> iterator;
		typedef class ft::binary_tree_const_iterator<value_type, Node> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator> difference_type;

		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _comp(comp), _root(NULL), _alloc(alloc), _size(0){};

		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
			: _comp(comp), _root(NULL), _alloc(alloc), _size(0)
		{
			insert(first, last);
		};

		set(const set &x) : _comp(x._comp), _root(NULL), _alloc(x._alloc), _size(0)
		{
			insert(x.begin(), x.end());
		};

		set &operator=(const set &x)
		{
			if (this == &x)
				return (*this);
			clear();
			_comp = x._comp;
			_root = NULL;
			_alloc = x._alloc;
			_size = 0;
			insert(x.begin(), x.end());
			return (*this);
		};

		~map(void)
		{
			clear();
		}

		iterator begin()
		{
			if (!_size)
				return (iterator());
			return (iterator(minimum(_root)));
		};

		const_iterator begin() const
		{
			if (!_size)
				return (const_iterator());
			return (const_iterator(minimum(_root)));
		};

		iterator end()
		{
			if (!_size)
				return (iterator());
			nodePtr last = maximum(_root);
			return (iterator(last->right));
		};

		const_iterator end() const
		{
			if (!_size)
				return (const_iterator());
			nodePtr last = maximum(_root);
			return (const_iterator(last->right));
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		};

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		};

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		};

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		};

		bool empty() const
		{
			return (!_size ? true : false);
		};

		size_type size(void) const
		{
			return (_size);
		};

		size_type max_size() const
		{
			return (_node_alloc.max_size());
		};

		pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<key_type, value_type> duo(val, val);
			return (insertTree(duo));
		};

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			ft::pair<key_type, value_type> duo(val, val);
			return (insertTree(duo).first);
		};

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
		{
			for (; first != last; ++first)
				insert(*first);
		};

		void erase(iterator position)
		{
			if (position == end())
				return;
			erase((*position).first);
		};

		size_type erase(const value_type &k)
		{
			iterator pos = find(k);
			if (pos == end())
				return (0);
			deleteTree(pos._head);
			return (1);
		};

		void erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		};

		void swap(map &x)
		{
			key_compare _compTmp;
			_node_allocator _node_allocTmp;
			nodePtr _rootTmp;
			allocator_type _allocTmp;
			size_type _sizeTmp;

			_compTmp = _comp;
			_node_allocTmp = _node_alloc;
			_rootTmp = _root;
			_allocTmp = _alloc;
			_sizeTmp = _size;
			
			_comp = x._comp;
			_node_alloc = x._node_alloc;
			_root = x._root;
			_alloc = x._alloc;
			_size = x._size;

			x._comp = _compTmp;
			x._node_alloc = _node_allocTmp;
			x._root = _rootTmp;
			x._alloc = _allocTmp;
			x._size = _sizeTmp;
		};

		key_compare key_comp() const { return _comp; }

		value_compare value_comp() const
		{
			value_compare ret(_comp);

			return ret;
		}

		void clear(void)
		{
			erase(begin(), end());
		}

		iterator find(const key_type &k)
		{
			iterator first = begin();
			iterator last = end();

			for (; first != last; ++first)
			{
				if (first->first == k)
					return first;
			}
			return NULL;
		};

		const_iterator find(const key_type &k) const
		{
			const_iterator first = begin();
			const_iterator last = end();

			for (; first != last; ++first)
			{
				if (first->first == k)
					return first;
			}
			return NULL;
		};

		size_type count(const key_type &k) const
		{
			const_iterator ite = find(k);

			if (ite == end() || ite == NULL)
				return 0;
			else
				return 1;
		}

		iterator lower_bound(const key_type &k)
		{
			iterator start = begin();
			iterator endIte = end();

			while (start != endIte)
			{
				if (!_comp((*start).first, k))
					break;
				start++;
			}
			return (start);
		}

		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator start = begin();
			const_iterator endIte = end();

			while (start != endIte)
			{
				if (!_comp((*start).first, k))
					break;
				start++;
			}
			return (start);
		}

		iterator upper_bound(const key_type &k)
		{
			iterator start = begin();
			iterator endIte = end();

			while (start != endIte)
			{
				if (_comp(k, (*start).first))
					break;
				start++;
			}
			return (start);
		}

		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator start = begin();
			const_iterator endIte = end();

			while (start != endIte)
			{
				if (_comp(k, (*start).first))
					break;
				start++;
			}
			return (start);
		}

		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

	public:
		typedef typename allocator_type::template rebind<Node>::other _node_allocator;
		typedef typename _node_allocator::pointer nodePtr;

		key_compare _comp;
		_node_allocator _node_alloc;
		nodePtr _root;
		allocator_type _alloc;
		size_type _size;

		nodePtr newNode(value_type elem)
		{
			nodePtr newNode = _node_alloc.allocate(1);
			_node_alloc.construct(newNode, Node(elem));
			newNode->left = newNillChild(newNode);
			newNode->right = newNillChild(newNode);
			return (newNode);
		}

		nodePtr newNillChild(nodePtr parent)
		{
			nodePtr child = _node_alloc.allocate(1);
			_node_alloc.construct(child, Node());
			child->parent = parent;
			return (child);
		}

		void deleteNode(nodePtr node)
		{
			_node_allocator(_alloc).destroy(node);
			_node_allocator(_alloc).deallocate(node, 1);
		}

		void deleteNodeAndChild(nodePtr node)
		{
			deleteNode(node->right);
			deleteNode(node->left);
			deleteNode(node);
		}

		ft::pair<iterator, bool> insertTree(const value_type &value)
		{
			nodePtr node = newNode(value);
			if (_root == NULL)
				_root = newNillChild(NULL);
			if (_root->nill)
			{
				deleteNode(_root);
				_root = node;
				_root->color = 0;
			}
			else
			{
				nodePtr tmp = _root;
				while (!tmp->nill)
				{
					if (node->value.first == tmp->value.first)
					{
						deleteNodeAndChild(node);
						return (ft::make_pair(iterator(tmp), false));
					}
					else if (!_comp(node->value.first, tmp->value.first))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				node->parent = tmp->parent;
				deleteNode(tmp);
				if (!_comp(node->parent->value.first, node->value.first))
					node->parent->left = node;
				else
					node->parent->right = node;
				balanceTreeInsert(node);
			}
			_size++;
			return (ft::make_pair(iterator(node), true));
		}

		void balanceTreeInsert(nodePtr node)
		{
			nodePtr u;
			while (node->parent->color == 1)
			{
				if (node->parent->parent->right == node->parent)
				{
					u = node->parent->parent->left;
					if (u->color == 1)
					{
						u->color = 0;
						node->parent->color = 0;
						node->parent->parent->color = 1;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = 0;
						node->parent->parent->color = 1;
						leftRotate(node->parent->parent);
					}
				}
				else
				{
					u = node->parent->parent->right;
					if (u->color == 1)
					{
						u->color = 0;
						node->parent->color = 0;
						node->parent->parent->color = 1;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = 0;
						node->parent->parent->color = 1;
						rightRotate(node->parent->parent);
					}
				}
				if (node == _root)
					break;
			}
			_root->color = 0;
		}

		void deleteTree(nodePtr nodeToDelete)
		{
			if (_size == 1 && nodeToDelete == _root)
			{
				deleteNodeAndChild(nodeToDelete);
				_root = NULL;
				_size--;
				return;
			}
			bool originalColor = nodeToDelete->color;
			nodePtr x, y;

			if (nodeToDelete->left->nill)
			{
				x = nodeToDelete->right;
				deleteNode(nodeToDelete->left);
				rbTransplant(nodeToDelete, x);
			}
			else if (nodeToDelete->right->nill)
			{
				x = nodeToDelete->left;
				deleteNode(nodeToDelete->right);
				rbTransplant(nodeToDelete, x);
			}
			else
			{
				y = minimum(nodeToDelete->right);
				deleteNode(y->left);
				originalColor = y->color;
				x = y->right;
				if (y->parent == nodeToDelete)
					x->parent = y;
				else
				{
					rbTransplant(y, y->right);
					y->right = nodeToDelete->right;
					y->right->parent = y;
				}
				rbTransplant(nodeToDelete, y);
				y->left = nodeToDelete->left;
				y->left->parent = y;
				y->color = nodeToDelete->color;
			}
			deleteNode(nodeToDelete);
			_size--;
			if (originalColor == 0)
				balanceTreeDelete(x);
		}

		void balanceTreeDelete(nodePtr x)
		{
			nodePtr s;
			while (x != _root && x->color == 0)
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
						x = _root;
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
						x = _root;
					}
				}
			}
			x->color = 0;
		}

		void rbTransplant(nodePtr u, nodePtr v)
		{
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->right)
				u->parent->right = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			v->parent = u->parent;
		}

		void leftRotate(nodePtr x)
		{
			nodePtr y = x->right;
			x->right = y->left;
			y->left->parent = x;
			if (!y->left->nill)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
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
			y->right->parent = x;
			if (!y->right->nill)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		nodePtr minimum(nodePtr node) const
		{
			while (!node->left->nill)
				node = node->left;
			return (node);
		}

		nodePtr maximum(nodePtr node) const
		{
			while (!node->right->nill)
				node = node->right;
			return (node);
		}

		nodePtr keySearch(nodePtr start, const key_type &key) const
		{
			while (start && !start->nill && key != start->value.first)
			{
				if (_comp(key, start->value.first))
					start = start->left;
				else
					start = start->right;
			}
			return (start);
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		else
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}
}

#endif