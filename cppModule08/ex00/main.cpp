#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> vect;
    std::list<int> lst;
    std::deque<int> dq;

    for (int i = 0; i < 10; ++i) {
        vect.push_back(i);
        lst.push_back(i);
        dq.push_back(i);
    }

    try {
        std::cout << "Vector find 5: " << *easyfind(vect, 5) << std::endl;
        std::cout << "List   find 5: " << *easyfind(lst, 5) << std::endl;
        std::cout << "Deque  find 5: " << *easyfind(dq, 5) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Deque find 42: " << *easyfind(dq, 42) << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Deque find 42: " << e.what() << std::endl;
    }

	try {
		std::cout << "Vector find 42: " << *easyfind(vect, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Vector find 42: " << e.what() << std::endl;
	}

	try {
		std::cout << "List find 42: " << *easyfind(lst, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "List find 42: " << e.what() << std::endl;
	}

    return 0;
}
