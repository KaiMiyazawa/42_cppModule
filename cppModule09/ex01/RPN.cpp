#include "RPN.hpp"

class invalidExpressionException : public std::exception {
	virtual const char *what() const throw() {
		return "invalid expression";
	}
};

class hasEnoughOperandsException : public std::exception {
	virtual const char *what() const throw() {
		return "has not enough operands";
	}
};

class divisionByZeroException : public std::exception {
	virtual const char *what() const throw() {
		return "division by zero";
	}
};

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		RPN tmp(other);
		tmp.swap(*this);
	}
	return *this;
}

void RPN::swap(RPN &other) {
	std::swap(this->_stack, other._stack);
}

bool RPN::hasEnoughOperands() const {
	return this->_stack.size() >= 2;
}

int add(int a, int b) {
	if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
		(b < 0 && a < std::numeric_limits<int>::min() - b)) {
		throw std::overflow_error("addition overflow");
	}
	return a + b;
}
int sub(int a, int b) {
	if ((b > 0 && a < std::numeric_limits<int>::min() + b) ||
		(b < 0 && a > std::numeric_limits<int>::max() + b)) {
		throw std::overflow_error("subtraction overflow");
	}
	return a - b;
}
int mul(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if (a > std::numeric_limits<int>::max() / b || a < std::numeric_limits<int>::min() / b) {
		throw std::overflow_error("multiplication overflow");
	}
	return a * b;
}
int div_op(int a, int b) {
	if (b == 0) {
		throw divisionByZeroException();
	}
	if (a == std::numeric_limits<int>::min() && b == -1) {
		throw std::overflow_error("division overflow");
	}
	return a / b;
}

void RPN::applyOperator(BinaryOp op) {
	if (!hasEnoughOperands()) {
		std::cerr << "Error" << std::endl;
		throw hasEnoughOperandsException();
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
	try {
		while (iss >> token) {
			if (token.size() > 1) {
				throw invalidExpressionException();
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
				int num;
				std::istringstream(token) >> num;
				_stack.push(num);
			} else {
				throw invalidExpressionException();
				return ;
			}
		}
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
	
	if (_stack.size() != 1) {
		std::cerr << "Error: invalid expression" << std::endl;
		return ;
	}
	std::cout << this->_stack.top() << std::endl;
	return ;
}