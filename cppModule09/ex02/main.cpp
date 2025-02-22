#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
		return 1;
	}
	
	// argc > 3 の場合は、argv[1] 以降をスペース区切りで連結
	// exapmle:
	// ./PmergeMe "3 5 9 7 4"
	// ./PmergeMe 3 5 9 7 4
	// ./PmergeMe "3" "5 9" "7 4"
	// でも動くようにしている。
	std::string concatenated_argvs = std::string(argv[1]);
	for (int i = 2; i < argc; ++i) {
		concatenated_argvs += " " + std::string(argv[i]);
	}
	
	try {
		PmergeMe<std::vector<int> > v(concatenated_argvs);
		v.sort();
		
		PmergeMe<std::deque<int> > d(concatenated_argvs);
		d.sort();
		
		std::cout << "Before:\t";
		std::stringstream ss(concatenated_argvs);
		int n;
		while (ss >> n) {
			std::cout << n << " ";
		}
		std::cout << std::endl;
		std::cout << "After:\t";
		v.printSequence();
		v.benchmark();
		d.benchmark();
	} catch (std::out_of_range &e) {
		// stoll
		std::cerr << "Error: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	// // sort check
	// try {
	// 	PmergeMe<std::vector<int> > v(concatenated_argvs);
	// 	v.sort();
	// 	PmergeMe<std::deque<int> > d(concatenated_argvs);
	// 	d.sort();
		
	// 	std::vector<int> vec;
	// 	std::deque<int> deq;
	// 	std::stringstream ss(concatenated_argvs);
	// 	std::string s;
	// 	while (ss >> s) {
	// 		int n;
	// 		std::stringstream(s) >> n;
	// 		vec.push_back(n);
	// 		deq.push_back(n);
	// 	}
	// 	std::sort(vec.begin(), vec.end());
	// 	std::sort(deq.begin(), deq.end());
		
	// 	std::cout << "std::sort check: ";
	// 	// vec == v ? true : false
	// 	if (vec == v.getSequence()) {
	// 		std::cout << "true" << std::endl;
	// 	} else {
	// 		std::cout << "false" << std::endl;
	// 		// 違う部分を表示
	// 		for (size_t i = 0; i < vec.size(); ++i) {
	// 			if (vec[i] != v.getSequence()[i]) {
	// 				std::cout << "vec[" << i << "] = " << vec[i] << ", v[" << i << "] = " << v.getSequence()[i] << std::endl;
	// 			}
	// 		}
	// 	}
	// 	// deq == d ? true : false
	// 	if (deq == d.getSequence()) {
	// 		std::cout << "std::sort check: true" << std::endl;
	// 	} else {
	// 		std::cout << "std::sort check: false" << std::endl;
	// 		// 違う部分を表示
	// 		for (size_t i = 0; i < deq.size(); ++i) {
	// 			if (deq[i] != d.getSequence()[i]) {
	// 				std::cout << "deq[" << i << "] = " << deq[i] << ", d[" << i << "] = " << d.getSequence()[i] << std::endl;
	// 			}
	// 		}
	// 	}
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	return 0;
}

/*

$>./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

$>./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
    		OR
$>./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us

$>./PmergeMe "-1" "2"
Error
*/