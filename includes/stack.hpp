/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:22 by vscode            #+#    #+#             */
/*   Updated: 2022/02/03 17:17:52 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
		typedef typename Container container_type;
		
		explicit stack(const container_type& ctnr = container_type()) _ctnr(ctnr) {};

		bool empty() const
		{
			return (_ctnr.empty());
		};
	};

private:
	container_type _ctnr;

}

#endif