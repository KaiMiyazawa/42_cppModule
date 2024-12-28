#include "Array.hpp"

void printArray(Array<int> &arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	Array<int> numbers(10);
	Array<int> numbers2(5);
	Array<int> numbers3(0);
	Array<int> numbers4;
	
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = i * 2;
	}
		
	printArray(numbers);
	printArray(numbers2);
	printArray(numbers3);
	printArray(numbers4);
	
	numbers2 = numbers;
	numbers3 = numbers;
	numbers4 = numbers;
	
	printArray(numbers);
	printArray(numbers2);
	printArray(numbers3);
	printArray(numbers4);
	
	numbers2[5] = 100;
	
	printArray(numbers2);
	
	try
	{
		std::cout << "Accessing a valid index: " << numbers[5] << std::endl;
		std::cout << "Accessing an invalid index: " << numbers[10] << std::endl;
	}
	catch (Array<int>::OutOfBoundsException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}

/*
期待される出力

0 2 4 6 8 10 12 14 16 18
0 2 4 6 8 10 12 14 16 18
0 2 4 6 8 10 12 14 16 18
0 2 4 6 8 10 12 14 16 18

*/