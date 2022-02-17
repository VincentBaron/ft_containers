/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTreeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:37:50 by vscode            #+#    #+#             */
/*   Updated: 2022/02/17 16:49:45 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREEITERATOR_HPP
# define BINARYTREEITERATOR_HPP

namespace ft
{
	template<typename T>
	class binary_tree_iterator : public ft::iterator<std::binary_iterator_tag, T>
	{
	public:
		
		binary_tree_iterator(void) : _data(0){};
		binary_tree_iterator(pointer ptr) : _data(ptr){};
		binary_tree_iterator(const binary_tree_iterator &src) : _data(src._data){};
		virtual ~binary_tree_iterator(){};

	private:
		
		
	}
}

#endif