/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:39:33 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/14 19:16:05 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main() {
    using std::cout;
    using std::vector;

    //Create a vector with values 1 .. 10
    vector<int> v(10);
    std::cout << "v has size " << v.size() << " and capacity " << v.capacity() << "\n";
    std::cout << v.at(12) << std::endl;

    // Now add 90 values, and print the size and capacity after each insert
    for(int i = 0; i <= 100; ++i)
    {
        v.push_back(i);
        std::cout << "v has size " << v.size() << " and capacity " << v.capacity() 
            << ". Memory range: " << &v.front() << " -- " << &v.back() << "\n"; 
    }
    // std::cout << v.max_size() << std::endl;

	// testing assign()

	// vector<int> vAss;
	// int x = 5;
	// vAss.assign(3, x);
	// std::cout << vAss[2] << std::endl;
	// x  = 3;
	// std::cout << vAss[2] << std::endl;


    return 0;
}