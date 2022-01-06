/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:49:43 by vbaron            #+#    #+#             */
/*   Updated: 2022/01/06 17:51:08 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# define MAX_SIZE 2305843009213693951
# include <iostream>
# include <string>

namespace ft
{
    //////////////////////////////////////////////////////////////////////////////////////////////// NAMESPACE TYPEDEFS
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef unsigned long long int size_type;
    template <typename T>
    class vector
    {

    public:
        
        /////////////////////////////////////////////////////////////////////////////////////////////////////CLASS TYPEDEFS
        typedef vector<T> vector_type;
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////// CONSTRUCTOR && DESTRUCTORS
        vector(void) : _size(0), _capacity(0) {};

        vector(size_type initial_size) : _array(initArrayNull(initial_size)), _size(initial_size), _capacity(initial_size)
        {
            std::cout << "parameter constructor called." << std::endl;
        }

        vector(const vector<T> &src) {};
        
        virtual ~vector() {};
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////// GETTERS && SETTERS
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////// OPERATOR OVERLOADS
        // vector_type &operator=(const vector &rhs) {};
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////////////////////////////////////////////  MEMBER FUNCTIONS
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////// ELEMENT ACCESS
        T at(size_type index)
        {
            rangeCheck(index);
            return (this->_array[index]);
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////////////////////////////////// ITERATORS
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////// CAPACITY
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////////////////////////////////// MODIFIERS
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void push_back(T elem)
        {
            manageCapacity();
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    protected:


    private:
        //////////////////////////////////////////////////////////////////////////////////////////////////////// ATTRIBUTES
        T *_array;
        size_type _size; 
        size_type _capacity;
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////// MEMBER FUNCTIONS
        T *initArrayNull(size_type initial_size) const
        {
            T *arr = new T[initial_size];
            for (size_type i = 0; i < initial_size; i++)
                arr[i] = 0;
            return (arr);
        };

        void rangeCheck(size_type index)
        {
            if (index >= this->_size)
                throw std::out_of_range("Out of range");
        }
        void manageCapacity()
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };   
}

#endif