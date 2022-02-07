/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:22 by vscode            #+#    #+#             */
/*   Updated: 2022/02/07 16:20:20 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container container_type;
		
		explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {};

		virtual ~stack() {};

		bool empty() const
		{
			return (_ctnr.empty());
		};
	private:
		container_type _ctnr;
	};
}

#endif