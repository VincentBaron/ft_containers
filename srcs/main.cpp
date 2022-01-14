
# include <iostream>
# include "../includes/vector.hpp"
# include <vector>

template <typename T>
void displayVector(T vect)
{
	typename T::iterator iter = vect.begin();
	int x = 0;
	while (iter < vect.end())
	{
		std::cout << *iter << std::endl;
		x++;
		iter++;
		if (x > 10)
			break ;
	}
}

int main()
{
	   std::vector<int> v(10, 5);
	   v.assign(20, 7);
	   displayVector(v);
}