#pragma once

#include <string>

enum class TokenType
{
	Identifier,
	Number,
	String,
	Operator,
	LeftParenthesis,
	RightParenthesis,
	LeftBracket,
	RightBracket,
	Keyword,
	Error,
	EndOfFile
};

struct Token
{
	TokenType type;
	std::string value;
	std::size_t line;
	std::size_t column;
};

std::string TokenTypeToString(TokenType type);