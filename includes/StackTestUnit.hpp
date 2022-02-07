/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTestUnit.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:11:55 by vscode            #+#    #+#             */
/*   Updated: 2022/02/07 15:08:41 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "VectorTestUnit.hpp"
# include "stack.hpp"
# include "vector.hpp"
# include <stack>

void stackConstructorsTesting(void)
{
	std::cout << BOLDMAGENTA << "\nStack Default Constructor..." << RESET << std::endl;

	ft::stack<int> ctnr;

	std::cout << "" << ctnr.empty() << std::endl;
}