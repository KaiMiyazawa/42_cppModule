#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	this->_stack = other._stack;
	return *this;
}

bool RPN::hasEnoughOperands() const {
	return this->_stack.size() >= 2;
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div_op(int a, int b) {
	if (b == 0) {
		std::cerr << "Error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return a / b;
}

void RPN::applyOperator(BinaryOp op) {
	if (!hasEnoughOperands()) {
		std::cerr << "Error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();
	_stack.push(op(a, b));
	return ;
}

void RPN::calculate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token) {
		if (token.size() > 1) {
			std::cerr << "Error" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		else if (token == "+") {
			applyOperator(add);
		}
		else if (token == "-") {
			applyOperator(sub);
		}
		else if (token == "*") {
			applyOperator(mul);
		}
		else if (token == "/") {
			applyOperator(div_op);
		}
		else if (!token.empty() && std::isdigit(token[0])) {
			_stack.push(std::stoi(token));
		} else {
			std::cerr << "Error" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	std::cout << this->_stack.top() << std::endl;
	return ;
}