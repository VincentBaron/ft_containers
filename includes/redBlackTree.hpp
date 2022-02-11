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
		Node(Pair elem, const allocator_type &alloc = allocator_type()) : _color(REDT), _pair(elem), _data(alloc), _left(NULL), _right(NULL)
		{
			pointer tmp = _data.allocate(1);
			_data.construct(tmp, elem);
		};

		void add(Node *child, Pair elem)
		{
			child(elem);
		}

	public:
	
		bool _color;
		Pair _pair;
		allocator_type _data;
		Node* _left;
		Node* _right;
	};
}

#endif