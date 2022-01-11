
# include <iostream>
# include "../includes/vector.hpp"
# include <vector>

int main()
{
   	int array[5] = {0, 1, 2, 3, 4};
   
	std::vector<int> vect(std::begin(array), std::end(array));
	std::cout << vect[3] << std::endl;
	ft::vector<int> v(std::begin(array), std::end(array));
	std::cout << v[3] << std::endl;
}