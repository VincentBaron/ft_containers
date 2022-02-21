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
	template <class Key, class T, class Pair>
	struct Node
	{

	public:

		typedef typename T::value_type value_type;
		
		Node() : color(BLACKT), key(Key()), value(T()), left(NULL), right(NULL), parent(NULL), nill(1) {};
		Node(Pair elem) : color(REDT), key(elem.first), value(elem.second), left(NULL), right(NULL), parent(NULL), nill(0) {};
	
		bool color;
		Key key;
		T value;
		Node* left;
		Node* right;
		Node* parent;
		bool nill;
	};
}

#endif