/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:22:12 by vscode            #+#    #+#             */
/*   Updated: 2022/02/24 17:44:32 by vincentbaro      ###   ########.fr       */
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
		typedef class ft::binary_tree_iterator<Node> iterator;
		typedef class ft::binary_tree_const_iterator<Node> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator> difference_type;

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _comp(comp), _root(NULL), TNULL(NULL), _alloc(alloc), _size(0){};

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
			: _comp(comp), _root(NULL), TNULL(NULL), _alloc(alloc), _size(0)
		{
			insert(first, last);
		};

		map(const map &x) : _comp(x._comp), _root(NULL), TNULL(NULL), _alloc(x._alloc), _size(0)
		{
			insert(x.begin(), x.end());
		};

		map &operator=(const map &x)
		{
			if (this == &x)
				return (*this);
			// clear();
			_node_allocator(_alloc).destroy(TNULL);
			_node_allocator(_alloc).deallocate(TNULL, 1);
			_comp = x._comp;
			_root = NULL;
			TNULL = NULL;
			_alloc = x._alloc;
			_size = 0;
			insert(x.begin(), x.end());
			return (*this);
		};

		~map(void)
		{
			// clear();
			_node_allocator(_alloc).destroy(TNULL);
			_node_allocator(_alloc).deallocate(TNULL, 1);
		}

		// iterator begin()
		// {
		// 	if (!_size)
		// 		return (iterator(TNULL, TNULL));
		// 	return (iterator(minimum(_root), TNULL));
		// };

		// const_iterator begin() const
		// {
		// 	if (!_size)
		// 		return (iterator(TNULL, TNULL));
		// 	return (const_iterator(minimum(_root), TNULL));
		// };

		// iterator end()
		// {
		// 	if (!_size)
		// 		return (iterator(TNULL, TNULL));
		// 	nodePtr max = maximum(_root);
		// 	iterator it(max->right, TNULL);
		// 	++it;
		// 	return (it);
		// };

		// const_iterator end() const
		// {
		// 	if (!_size)
		// 		return (const_iterator(TNULL, TNULL));
		// 	nodePtr max = maximum(_root);
		// 	const_iterator it(max, TNULL);
		// 	++it;
		// 	return (it);
		// };

		// reverse_iterator rbegin()
		// {
		// 	return (reverse_iterator(end()));
		// };

		// const_reverse_iterator rbegin() const
		// {
		// 	return (const_reverse_iterator(end()));
		// };

		// reverse_iterator rend()
		// {
		// 	return (reverse_iterator(begin()));
		// };

		// const_reverse_iterator rend() const
		// {
		// 	return (const_reverse_iterator(begin()));
		// };

		// bool empty() const
		// {
		// 	return (!_size ? true : false);
		// };

		// size_type size(void) const
		// {
		// 	return (_size);
		// };

		// size_type max_size() const
		// {
		// 	return (_node_allocator(_alloc).max_size());
		// };

		// mapped_type &operator[](const key_type &k)
		// {
		// 	nodePtr node = keySearch(_root, k);
		// 	if (node != TNULL)
		// 		return (node->value.second);
		// 	value_type tmp = ft::make_pair(k, mapped_type());
		// 	insert(tmp);
		// 	nodePtr tmp2 = keySearch(_root, k);
		// 	return (tmp2->value.second);
		// };

		pair<iterator, bool> insert(const value_type &val)
		{
			return (insertTree(val));
		};

		// iterator insert(iterator position, const value_type &val)
		// {
		// 	(void)position;
		// 	return (insertTree(val).first);
		// };

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::isIntegral<InputIterator>::value, InputIterator>::type * = 0)
		// {
		// 	for (; first != last; ++first)
		// 		insert(*first);
		// };

		// void erase(iterator position)
		// {
		// 	if (position == end())
		// 		return;
		// 	deleteTree((*position).first);
		// };

		// size_type erase(const key_type &k)
		// {
		// 	iterator pos = find(k);
		// 	if (pos == end())
		// 		return (0);
		// 	return (deleteTree(k));
		// };

		// void erase(iterator first, iterator last)
		// {
		// 	int i = 0;
		// 	while (first != last)
		// 	{
		// 		// std::cout << "first._root: " << first._root << std::endl;
		// 		// std::cout << "first._root.key: " << first._root->value.first << std::endl;
		// 		// std::cout << "last._root: " << last._root << std::endl;
		// 		// std::cout << "last._root.key: " << last._root->value.first << std::endl;
		// 		erase(first++);
		// 		i++;
		// 		if (i > 6)
		// 			break;
		// 	}
		// };

		// void swap(map &x)
		// {
		// 	key_compare _compTmp;
		// 	_node_allocator _node_allocTmp;
		// 	nodePtr _rootTmp;
		// 	nodePtr TNULLTmp;
		// 	allocator_type _allocTmp;
		// 	size_type _sizeTmp;

		// 	_comp = x._comp;
		// 	_node_alloc = x._node_alloc;
		// 	_root = x._root;
		// 	TNULL = x.TNULL;
		// 	_alloc = x._alloc;
		// 	_size = x._size;

		// 	x._comp = _compTmp;
		// 	x._node_alloc = _node_allocTmp;
		// 	x._root = _rootTmp;
		// 	x.TNULL = TNULLTmp;
		// 	x._alloc = _allocTmp;
		// 	x._size = _sizeTmp;
		// };

		// key_compare key_comp() const { return _comp; }

		// value_compare value_comp() const
		// {
		// 	value_compare ret(_comp);

		// 	return ret;
		// }

		// void clear(void)
		// {
		// 	erase(begin(), end());
		// }

		// iterator find(const key_type &k)
		// {
		// 	iterator first = begin();
		// 	iterator last = end();

		// 	for (; first != last; ++first)
		// 	{
		// 		if (first->first == k)
		// 			return first;
		// 	}
		// 	return last;
		// };

		// const_iterator find(const key_type &k) const
		// {
		// 	const_iterator first = begin();
		// 	const_iterator last = end();

		// 	for (; first != last; ++first)
		// 	{
		// 		if (first->first == k)
		// 			return first;
		// 	}
		// 	return last;
		// };

		// size_type count(const key_type &k) const
		// {
		// 	const_iterator ite = find(k);

		// 	if (ite == end())
		// 		return 0;
		// 	else
		// 		return 1;
		// }

		// iterator lower_bound(const key_type &k)
		// {
		// 	iterator start = begin();
		// 	iterator endIte = end();

		// 	while (start != endIte)
		// 	{
		// 		if (!_comp((*start).first, k))
		// 			break;
		// 		start++;
		// 	}
		// 	return (start);
		// }

		// const_iterator lower_bound(const key_type &k) const
		// {
		// 	const_iterator start = begin();
		// 	const_iterator endIte = end();

		// 	while (start != endIte)
		// 	{
		// 		if (!_comp((*start).first, k))
		// 			break;
		// 		start++;
		// 	}
		// 	return (start);
		// }

		// iterator upper_bound(const key_type &k)
		// {
		// 	iterator start = begin();
		// 	iterator endIte = end();

		// 	while (start != endIte)
		// 	{
		// 		if (_comp(k, (*start).first))
		// 			break;
		// 		start++;
		// 	}
		// 	return (start);
		// }

		// const_iterator upper_bound(const key_type &k) const
		// {
		// 	const_iterator start = begin();
		// 	const_iterator endIte = end();

		// 	while (start != endIte)
		// 	{
		// 		if (_comp(k, (*start).first))
		// 			break;
		// 		start++;
		// 	}
		// 	return (start);
		// }

		// ft::pair<iterator, iterator> equal_range(const key_type &k)
		// {
		// 	return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		// }

		// ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		// {
		// 	return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		// }

		// allocator_type get_allocator() const
		// {
		// 	return (_alloc);
		// }

	public:
		typedef typename allocator_type::template rebind<Node>::other _node_allocator;
		typedef typename _node_allocator::pointer nodePtr;

		key_compare _comp;
		_node_allocator _node_alloc;
		nodePtr _root;
		nodePtr TNULL;
		allocator_type _alloc;
		size_type _size;

		nodePtr newNode(value_type elem)
		{
			nodePtr newNode = _node_alloc.allocate(1);
			_node_alloc.construct(newNode, Node(elem));
			return (newNode);
		}

		void deleteNode(nodePtr node)
		{
			_node_allocator(_alloc).destroy(node);
			_node_allocator(_alloc).deallocate(node, 1);
			_size--;
		}

		ft::pair<iterator, bool> insertTree(const value_type &value)
		{
			(void)value;
			if (_root == NULL)
			{
				TNULL = newNode(value_type());
				TNULL->color = 0;
				TNULL->nill = 1;
				_root = TNULL;
			}
			return (ft::make_pair(iterator(), bool()));
		}
	};
}

#endif