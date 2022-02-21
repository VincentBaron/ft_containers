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
	template <class Pair>
	struct Node
	{

	public:
		
		typedef Pair value_type;
		
		Node() : color(BLACKT), value(Pair()), left(NULL), right(NULL), parent(NULL), nill(1) {};
		Node(Pair elem) : color(REDT), value(elem), left(NULL), right(NULL), parent(NULL), nill(0) {};
		// Node(Node &srcs) : color(srcs.color), key(srcs.key), value(srcs.value), left(srcs.left), right(srcs.right), left(srcs.right), parent(srcs.parent), nill(0) {};
	
		bool color;
		Pair value;
		Node* left;
		Node* right;
		Node* parent;
		bool nill;
	};
}

#endif