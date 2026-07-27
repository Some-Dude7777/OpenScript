// I am so sorry for whoever is reading this.
// If you're here, something has gone terribly wrong.

#include <vector>
#include <string>
#include <cctype>
#include <unordered_set>
#include "Lexer.h"
#include <iostream>

std::unordered_set<std::string> keywords = {
	"var",
	"func",
	"if",
	"else",
	"elif",
	"repeat",
	"while",
	"return",
	"use",
	"from",
	"lambda",
	"end"
};

Lexer::Lexer(const std::string& source)
	: source(source) 
{
}

// C++ constructor magic. I looked it up so you don't have to.

Token Lexer::ReadIdentifier()
{
	std::string text;

	while (
		position < source.length() &&
		(
			std::isalnum(static_cast<unsigned char>(source[position])) ||
			source[position] == '_'
			)
		)
	{
		text += source[position];
		position++;
		column++;
	}

	if (keywords.find(text) != keywords.end())
	{
		return {
			TokenType::Keyword,
			text,
			line,
			column
		};
	}

	return {
		TokenType::Identifier,
		text,
		line,
		column
	};
}

Token Lexer::ReadNumber()
{
	std::string text;
	bool hasDecimalPoint = false;

	while (position < source.length())
	{
		char c = source[position];

		if (std::isdigit(static_cast<unsigned char>(c)))
		{
			text += c;
			position++;
			column++;
		}
		else if (c == '.' && !hasDecimalPoint)
		{
			hasDecimalPoint = true;
			text += c;
			position++;
			column++;
		}
		else
		{
			break;
		}
	}

	return {
		TokenType::Number,
		text,
		line,
		column
	};
}

Token Lexer::ReadString()
{
	std::string text;

	position++;
	column++;

	while (
		position < source.length() &&
		source[position] != '"'
		)
	{
		if (source[position] == '\n')
		{
			line++;
			column = 1;
		}
		else
		{
			column++;
		}

		text += source[position];
		position++;
	}

	if (position >= source.length())
	{
		return {
			TokenType::Error,
			"Unterminated string",
			line,
			column
		};
	}

	position++;
	column++;

	return {
		TokenType::String,
		text,
		line,
		column
	};
}

std::vector<Token> Lexer::Tokenize() {
	std::vector<Token> tokens;

	while (position < source.length()) {
		char c = source[position];

		switch(c)
		{

			// This switch statement is slowly becoming a small operating system.

			case ' ':
			case '\t':
			case '\n':
				position++;
				break;

			case '(':
				tokens.push_back({ TokenType::LeftParenthesis, "(", line, column });
				position++;
				break;

			case ')':
				tokens.push_back({ TokenType::RightParenthesis, ")", line, column });
				column++;
				position++;
				break;

			case '[':
				tokens.push_back({ TokenType::LeftBracket, "[", line, column });
				position++;
				break;

			case ']':
				tokens.push_back({ TokenType::RightBracket, "]", line, column });
				position++;
				break;

			case '+':
				tokens.push_back({ TokenType::Operator, "+", line, column });
				position++;
				break;

			case '-':
				tokens.push_back({ TokenType::Operator, "-", line, column });
				position++;
				break;

			case '*':
				tokens.push_back({ TokenType::Operator, "*", line, column });
				position++;
				break;

			case '/':
				tokens.push_back({ TokenType::Operator, "/", line, column });
				position++;
				break;

			case '=':
				tokens.push_back({ TokenType::Operator, "=", line, column });
				position++;
				break;

			default:
				if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') {
					tokens.push_back(ReadIdentifier());
				}
				else if (c == '"') {
					tokens.push_back(ReadString());
				}
				else if (std::isdigit(static_cast<unsigned char>(c))) {
					tokens.push_back(ReadNumber());
				}
				else {
					position++;
				}

				break;
		};
	};

	tokens.push_back({
		TokenType::EndOfFile,
		"",
		line,
		column
		});

	return tokens;
}