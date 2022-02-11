/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redTBlackTree.hpp                                   :+: _     :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:49:21 by vscode            #+#    #+#             */
/*   Updated: 2022/02/11 13:20:07 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#define REDT 1
#define BLACKT 0
#include <functional>
#include <memory>

namespace ft
{
	template <class Pair, class Alloc = std::allocator<Pair> >
	class Node
	{
		typedef Alloc allocator_type;
		typedef typename allocator_type::pointer pointer;

	public:
		Node(Pair elem, const allocator_type &alloc = allocator_type()) : _color(REDT), _data(alloc), _left(NULL), _right(NULL)
		{
			_dataPtr = _data.allocate(1);
			_data.construct(_dataPtr, elem);
		};

		~Node(void)
		{
			_data.destroy(_dataPtr);
			_data.deallocate(_dataPtr, 1);
		}

	public:
		typedef typename allocator_type::template rebind<Node>::other _node_allocator;
		typedef typename _node_allocator::pointer _node_pointer;

		bool _color;
		allocator_type _data;
		pointer _dataPtr;
		_node_pointer _left;
		_node_pointer _right;
		_node_pointer _parent;
	};
}

#endif