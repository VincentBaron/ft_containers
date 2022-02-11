/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:22:12 by vscode            #+#    #+#             */
/*   Updated: 2022/02/11 18:14:40 by vscode           ###   ########.fr       */
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
		typedef ft::Node<value_type> Node;

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

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc) {};

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		map(const map &x);

		void insert(const value_type &val)
		{
			_head = newNode(val);
		};

		// iterator insert(iterator position, const value_type &val);

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last);

	public:

		typedef typename allocator_type::template rebind<Node<value_type> >::other _node_allocator;
		typedef typename _node_allocator::pointer _node_pointer;

		key_compare _comp;
		_node_allocator _node_alloc;
		_node_pointer _head;
		allocator_type _alloc;

		_node_pointer newNode(value_type elem)
		{
			_node_pointer newNode = _node_alloc.allocate(1);
			_node_alloc.construct(newNode, Node(elem));
			return (newNode);
		}
	};
}

#endif