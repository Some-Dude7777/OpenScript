#include "Parser.h"
#include <iostream>

Parser::Parser(std::vector<Token> tokens)
	: tokens(tokens)
{

}


Token Parser::Current()
{
	return tokens[position];
}


Token Parser::Advance()
{
	return tokens[position++];
}

Token Parser::Expect(TokenType expected)
{
	Token token = Current();

	if (token.type != expected)
	{
		std::cerr
			<< "Parser Error\n"
			<< "Line " << token.line
			<< ", Column " << token.column
			<< ": Expected "
			<< TokenTypeToString(expected)
			<< ", got "
			<< TokenTypeToString(token.type)
			<< " (\"" << token.value << "\")\n";

		std::exit(EXIT_FAILURE);
	}

	return Advance();
}

std::unique_ptr<Expression> Parser::ParseExpression()
{
	return ParseAddition();
}

std::unique_ptr<Expression> Parser::ParseAddition()
{
	auto left = ParseMultiplication();

	while (
		Current().type == TokenType::Operator &&
		(Current().value == "+" || Current().value == "-")
		)
	{
		std::string operation = Advance().value;
		auto right = ParseMultiplication();

		left = std::make_unique<BinaryExpression>(
			std::move(left),
			operation,
			std::move(right)
			);
	}

	return left;
}

std::unique_ptr<Expression> Parser::ParseMultiplication()
{
	auto left = ParsePrimary();

	while (
		Current().type == TokenType::Operator &&
		(Current().value == "*" || Current().value == "/")
		)
	{
		std::string operation = Advance().value;
		auto right = ParsePrimary();

		left = std::make_unique<BinaryExpression>(
			std::move(left),
			operation,
			std::move(right)
			);
	}

	return left;
}

std::unique_ptr<Expression> Parser::ParsePrimary()
{
	Token token = Current();

	switch (token.type)
	{
	case TokenType::Number:
		Advance();
		return std::make_unique<NumberExpression>(token.value);

	case TokenType::String:
		Advance();
		return std::make_unique<StringExpression>(token.value);

	case TokenType::Identifier:
		Advance();
		return std::make_unique<IdentifierExpression>(token.value);

	case TokenType::LeftParenthesis:
	{
		Advance();

		auto expression = ParseExpression();

		Expect(TokenType::RightParenthesis);

		return expression;
	}

	default:
		Error(
			token,
			"Expected an expression, got " +
			TokenTypeToString(token.type) +
			" (\"" + token.value + "\")"
		);
	}
}

std::unique_ptr<VariableDeclaration> Parser::ParseVariable()
{

	Expect(TokenType::Keyword);

	Token name = Expect(TokenType::Identifier);

	Expect(TokenType::Operator);

	Token value = Expect(TokenType::Number);


	auto expression =
		std::make_unique<NumberExpression>(value.value);


	return std::make_unique<VariableDeclaration>(
		name.value,
		std::move(expression)
		);
}