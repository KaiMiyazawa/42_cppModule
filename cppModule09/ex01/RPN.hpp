// RPN.hpp
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN {
private:
	std::stack<int> _stack;

	// スタックの上位2つの要素を取り出して演算し、結果をプッシュする
	typedef int (*BinaryOp)(int, int);
	bool hasEnoughOperands() const;
	void applyOperator(BinaryOp op);
	
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	// expression を受け取り、結果を出力する
	void calculate(const std::string &expression);
};

#endif
