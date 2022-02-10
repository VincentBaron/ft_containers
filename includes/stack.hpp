/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:22 by vscode            #+#    #+#             */
/*   Updated: 2022/02/09 21:47:01 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container container_type;
		typedef T value_type;
		typedef size_t size_type;

		explicit stack(const container_type &ctnr = container_type()) : _ctnr(ctnr){};

		virtual ~stack(){};

		bool empty() const { return (_ctnr.empty()); };
		size_type size() const { return (_ctnr.size()); };

		value_type &top() { return _ctnr.back(); };
		const value_type &top() const { return _ctnr.back(); };

		void push(const value_type &val) { _ctnr.push_back(val); };

		void pop(void) { _ctnr.pop_back(); };

		template <class Tx, class Containerx>
		friend bool operator==(const stack<Tx, Containerx> &lhs, const stack<Tx, Containerx> &rhs)
		{
			return (lhs._ctnr == rhs._ctnr);
		};

		template <class Tx, class Containerx>
		friend bool operator!=(const stack<Tx, Containerx> &lhs, const stack<Tx, Containerx> &rhs)
		{
			return (lhs._ctnr != rhs._ctnr);
		};

		template <class Tx, class Containerx>
		friend bool operator<(const stack<Tx, Containerx> &lhs, const stack<Tx, Containerx> &rhs)
		{
			return (lhs._ctnr < rhs._ctnr);
		};

		template <class Tx, class Containerx>
		friend bool operator<=(const stack<Tx, Containerx> &lhs, const stack<Tx, Containerx> &rhs)
		{
			return (lhs._ctnr <= rhs._ctnr);
		};

		template <class Tx, class Containerx>
		friend bool operator>(const stack<Tx, Containerx> &lhs, const stack<Tx, Containerx> &rhs)
		{
			return (lhs._ctnr > rhs._ctnr);
		};

		template <class Tx, class Containerx>
		friend bool operator>=(const stack<Tx, Containerx> &lhs, const stack<Tx, Containerx> &rhs)
		{
			return (lhs._ctnr >= rhs._ctnr);
		};

	private:
		container_type _ctnr;
	};
}

#endif