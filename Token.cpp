#include "Token.h"

#include <string>

std::string TokenTypeToString(TokenType type)
{
	switch (type)
	{
	case TokenType::Keyword:
		return "Keyword";

	case TokenType::Identifier:
		return "Identifier";

	case TokenType::Number:
		return "Number";

	case TokenType::String:
		return "String";

	case TokenType::Operator:
		return "Operator";

	case TokenType::LeftParenthesis:
		return "LeftParenthesis";

	case TokenType::RightParenthesis:
		return "RightParenthesis";

	case TokenType::LeftBracket:
		return "LeftBracket";

	case TokenType::RightBracket:
		return "RightBracket";

	case TokenType::EndOfFile:
		return "EndOfFile";

	default:
		return "Unknown";
	}
}