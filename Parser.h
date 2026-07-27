#pragma once

#include "Token.h"
#include "AST.h"

#include <vector>
#include <memory>


class Parser
{
private:

	std::vector<Token> tokens;
	size_t position = 0;


	Token Current();

	Token Advance();

	Token Expect(TokenType expected);

	std::unique_ptr<Expression> ParseAddition();

	std::unique_ptr<Expression> ParseMultiplication();

public:

	Parser(std::vector<Token> tokens);

	std::unique_ptr<VariableDeclaration> ParseVariable();
};