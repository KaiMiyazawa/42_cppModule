#include "easyfind.hpp"
#include <algorithm>

int main()
{
	std::vector<int> vect;
	for (int i = 0; i < 10; i++)
		vect.push_back(i);
	std::list<int> list;
	for (int i = 0; i < 10; i++)
		list.push_back(i);
	std::deque<int> deque;
	for (int i = 0; i < 10; i++)
		deque.push_back(i);
	std::forward_list<int> forward_list;
	for (int i = 0; i < 10; i++)
		forward_list.push_front(i);
	std::array<int, 10> array;
	for (int i = 0; i < 10; i++)
		array[i] = i;
	std::stack<int> stack;
	for (int i = 0; i < 10; i++)
		stack.push(i);
	std::queue<int> queue;
	for (int i = 0; i < 10; i++)
		queue.push(i);
	
	try {
		std::cout << "Vector: " << *easyfind(vect, 5) << std::endl;
		std::cout << "List: " << *easyfind(list, 5) << std::endl;
		std::cout << "Deque: " << *easyfind(deque, 5) << std::endl;
		std::cout << "Forward List: " << *easyfind(forward_list, 10) << std::endl;
		std::cout << "Array: " << *easyfind(array, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}