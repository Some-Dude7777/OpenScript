#pragma once

#include <string>
#include <vector>

#include "Token.h"

class Lexer {
	public:
		Lexer(const std::string& source);

		std::vector<Token> Tokenize();

	private:
		Token ReadIdentifier();
		Token ReadNumber();
		Token ReadString();

		std::string source;
		std::size_t position = 0;
		std::size_t line = 1;
		std::size_t column = 1;
};