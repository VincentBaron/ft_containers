/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:49:43 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/05 20:11:41 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
    template <typename T>
    class vector
    {

    public:
        //typedefs

        // Constructors and destructor
        vector(void) {};
        vector(const vector<T> &src) {};
        virtual ~vector() {};

        // Operator overloads
        vector<T> &operator=(const vector &rhs) {};

        // Getters / Setters

        // Member functions

    protected:
        // Attributes

    private:
        // Attributes
        vector<T> *_array;
    };
}

#endif