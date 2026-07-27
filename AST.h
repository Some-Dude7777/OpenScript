#pragma once

#include <string>
#include <memory>


class Expression
{
public:
	virtual ~Expression() = default;
};


class NumberExpression : public Expression
{
public:
	std::string value;

	NumberExpression(std::string value)
		: value(value)
	{}
};

class StringExpression : public Expression
{
public:
	std::string value;

	StringExpression(std::string value)
		: value(value)
	{}
};

class BinaryExpression : public Expression
{
public:
	std::unique_ptr<Expression> left;
	std::string operation;
	std::unique_ptr<Expression> right;

	BinaryExpression(
		std::unique_ptr<Expression> left,
		std::string operation,
		std::unique_ptr<Expression> right
	)
		: left(std::move(left)),
		operation(std::move(operation)),
		right(std::move(right))
	{
	}
};


class VariableDeclaration
{
public:
	std::string name;
	std::unique_ptr<Expression> value;

	VariableDeclaration(
		std::string name,
		std::unique_ptr<Expression> value
	)
		: name(name),
		value(std::move(value))
	{}
};