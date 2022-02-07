/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTestUnit.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:11:55 by vscode            #+#    #+#             */
/*   Updated: 2022/02/07 16:32:39 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "VectorTestUnit.hpp"
# include "stack.hpp"
# include "vector.hpp"
# include <stack>

void stackConstructorsTesting(void)
{
	std::cout << BOLDMAGENTA << "\nStack Default Constructor..." << RESET << std::endl;

	ft::stack<int, ft::vector<int> > ctnr;
	std::stack<int, std::vector<int> > ctnrReal;

	checkOutput(ctnr.empty(), ctnrReal.empty(), "Checking if stack is empty...");

	std::cout << BOLDMAGENTA << "\nStack Parametrized Constructor..." << RESET << std::endl;

	ft::vector<int> vect(5, 42);
	std::vector<int> vectReal(5, 42);
	ft::stack<int, ft::vector<int> > ctnr2(vect);
	std::stack<int, std::vector<int> > ctnrReal2(vectReal);

	checkOutput(ctnr.empty(), ctnrReal.empty(), "Checking empty()...");
	checkOutput(ctnr.size(), ctnrReal.size(), "Checking size()...");
}