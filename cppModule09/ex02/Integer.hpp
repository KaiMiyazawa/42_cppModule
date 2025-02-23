#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include <cstddef>

class Integer {
private:
	int _value;

public:
	static std::size_t count;
	Integer(int value) : _value(value) {}
	int getValue() const { return _value; }
	bool operator<(const Integer &rhs) const {
		count++;
		// デバッグ用に比較内容を出力（不要なら削除可能）
		std::cout << "count: " << _value << " vs " << rhs._value << std::endl;
		return _value < rhs._value;
	}
};

inline std::ostream &operator<<(std::ostream &os, const Integer &obj) {
	os << obj.getValue();
	return os;
}

#endif
