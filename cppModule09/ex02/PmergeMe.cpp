#include "PmergeMe.hpp"

// template <typename T> : std::vector<int> or std::deque<int>

static bool is_digit_string(std::string s) {
	for (std::string::iterator it = s.begin(); it != s.end(); it++) {
		if (isdigit(*it) == 0) {
			return false;
		}
	}
	return true;
}

static long getMicroseconds() {
	struct timeval tv;
	if (gettimeofday(&tv, NULL) != 0) {
		throw std::runtime_error("Error: gettimeofday failed");
	}
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

// MARK: - PmergeMe class

template <typename T>
PmergeMe<T>::PmergeMe() {
	_time_start = getMicroseconds();
	
	std::stringstream ss("1 2 3 4 5 6 7 8 9 10");
	std::string s;
	while (ss >> s) {
		if (is_digit_string(s) == false) {
			throw std::invalid_argument("Error: invalid sequence");
		}
		long long lln = std::stoll(s);
		if (lln > INT_MAX || lln < 0) {
			throw std::invalid_argument("Error: invalid sequence");
		}
		int n = std::stoi(s);
		_sequence.push_back(n);
	}
}

template <typename T>
PmergeMe<T>::PmergeMe(std::string sequence) {
	_time_start = getMicroseconds();
	
	std::stringstream ss(sequence);
	std::string s;
	while (ss >> s) {
		if (is_digit_string(s) == false) {
			throw std::invalid_argument("Error: invalid sequence");
		}
		long lln = std::stoll(s);
		if (lln > INT_MAX || lln < 0) {
			throw std::invalid_argument("Error: invalid sequence");
		}
		int n = std::stoi(s);
		_sequence.push_back(n);
	}
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &src) {
	*this = src;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		_sequence = rhs._sequence;
		_time_start = rhs._time_start;
		_time_elapsed = rhs._time_elapsed;
	}
	return *this;
}

template <typename T>
T PmergeMe<T>::getSequence() const {
	return _sequence;
}

template <typename T>
void PmergeMe<T>::printSequence() {
	for (typename T::iterator it = _sequence.begin(); it != _sequence.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

struct PendingPair {
	int bigger;
	int smaller;
	PendingPair(const int & b, const int & s) : bigger(b), smaller(s) {}
};

template <typename T>
static void binaryInsert(T & S, const typename T::value_type & val) {
	typedef typename T::iterator Iterator;
	Iterator it = std::lower_bound(S.begin(), S.end(), val);
	S.insert(it, val);
}

template <typename T>
void PmergeMe<T>::sort() {
	typedef typename T::size_type Size;

	if (_sequence.size() <= 1) {
		_time_elapsed = getMicroseconds() - _time_start;
		return;
	}
	
	// odd number of elements
	if (_sequence.size() % 2 == 1) {
		int odd_extra = _sequence.back();
		_sequence.pop_back();
		sort();
		binaryInsert(_sequence, odd_extra);
		return;
	}
	
	Size n = _sequence.size();
	T biggers;
	std::vector<PendingPair> pendings;
	
	// first pair
	int special_smaller;
	if (_sequence[0] > _sequence[1]) {
		special_smaller = _sequence[1];
		biggers.push_back(_sequence[0]);
	} else {
		special_smaller = _sequence[0];
		biggers.push_back(_sequence[1]);
	}
	
	// pair making
	for (int i = 1; i < n/2; ++i) {
		Size idx0 = 2*i;
		Size idx1 = 2*i + 1;
		if (_sequence[idx0] > _sequence[idx1]) {
			biggers.push_back(_sequence[idx0]);
			pendings.push_back(PendingPair(_sequence[idx0], _sequence[idx1]));
		} else {
			biggers.push_back(_sequence[idx1]);
			pendings.push_back(PendingPair(_sequence[idx1], _sequence[idx0]));
		}
	}
	
	// recursive sort
	this->sort();
	
	// special insert
	biggers.insert(biggers.begin(), special_smaller);
	
	// devide and decide insertion order
	Size Pn = pendings.size();
	std::vector<Size> insertionOrder;
	
	const int groupSizes[] = {2, 2, 6, 10, 22, 42, 86, 170};// あとでハードコードから変更
	const int numGroupSizes = sizeof(groupSizes) / sizeof(groupSizes[0]);
	Size processed = 0;
	for (int g = 0; g < numGroupSizes && processed < Pn; ++g) {
		int currentGroup = groupSizes[g];
		int actualGroupSize = (processed + currentGroup <= Pn) ? currentGroup : (Pn - processed);
		for (int j = 0; j < actualGroupSize; ++j) {
			insertionOrder.push_back(processed + actualGroupSize - 1 - j);
		}
		processed += currentGroup;
	}
	
	if (insertionOrder.size() < Pn) {
		for (Size i = Pn; i > insertionOrder.size(); --i) {
			insertionOrder.push_back(i - 1);
		}
	}
	if (insertionOrder.size() > Pn)
		insertionOrder.resize(Pn);
	
	
	// insert pending
	for (Size k = 0; k < insertionOrder.size(); ++k) {
		Size idx = insertionOrder[k];
		if (idx >= pendings.size())
			continue;
		const PendingPair & p = pendings[idx];
		typename T::iterator it = std::lower_bound(biggers.begin(), biggers.end(), p.bigger);
		typename T::iterator pos = std::upper_bound(biggers.begin(), it, p.smaller);
		biggers.insert(pos, p.smaller);
	}
	
	// copy
	_sequence = biggers;
	
	// timer stop
	_time_elapsed = getMicroseconds() - _time_start;
}

template <>
void PmergeMe<std::vector<int> >::sort() {
	std::sort(_sequence.begin(), _sequence.end());
	_time_elapsed = getMicroseconds() - _time_start;
}

template <>
void PmergeMe<std::deque<int> >::sort() {
	std::sort(_sequence.begin(), _sequence.end());
	_time_elapsed = getMicroseconds() - _time_start;
}

template <typename T>
void PmergeMe<T>::benchmark() {
	std::string type_name(typeid(_sequence).name());
	std::string container_type;
	if (type_name.find("vector") != std::string::npos) {
		container_type = "vector<int>";
	} else if (type_name.find("deque") != std::string::npos) {
		container_type = "deque<int>";
	} else {
		container_type = "unknown";
	}
	
	// time in "us"
	std::cout << "Time to process a range of " << _sequence.size()
		<< " elements with std::" << container_type << " : "
		<< std::fixed << std::setprecision(5) << _time_elapsed << " us" << std::endl;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;