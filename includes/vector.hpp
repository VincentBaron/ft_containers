/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:49:43 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/06 12:18:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# define MAX_SIZE 2305843009213693951

namespace ft
{
    typedef unsigned long long int size_type;
    template <typename T>
    class vector
    {

    public:
        //typedefs
        typedef vector<T> vector_type;

        // Constructors and destructor
        vector(void) : _size(0), _capacity(0) {}; 
        vector(size_type initial_size) : _array(init_array_null(initial_size)), _size(initial_size), _capacity(initial_size) {
            std::cout << "parameter constructor called." << std::endl;
        }
        vector(const vector<T> &src) {};
        virtual ~vector() {};

        // Operator overloads
        // vector_type &operator=(const vector &rhs) {};

        // Getters / Setters

        // Member functions
        T at(size_type index)
        {
            return (this->_array[index]);
        }

    protected:
        // Attributes

    private:
        // Attributes
        T *_array;
        size_type _size;
        size_type _capacity;

        //Member functions
        T *init_array_null(size_type initial_size) const
        {
            T *arr = new T[initial_size];
            for (size_type i = 0; i < initial_size; i++)
                arr[i] = 0;
            return (arr);
        };
        
    };
}

#endif