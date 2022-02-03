/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTestUnit.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:11:55 by vscode            #+#    #+#             */
/*   Updated: 2022/02/03 17:15:52 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "VectorTestUnit.hpp"

void stackConstructorsTesting(void)
{
	std::cout << BOLDMAGENTA << "\nStack Default Constructor..." << RESET << std::endl;

	ft::stack<> stack();
}