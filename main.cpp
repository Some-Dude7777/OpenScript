#include "Lexer.h"
#include "Parser.h"

#include <iostream>
#include <utility>

int main()
{
	std::string source = R"(
        var counter = 42
    )";

	Lexer lexer(source);
	auto tokens = lexer.Tokenize();

	for (const Token& token : tokens)
	{
		std::cout
			<< TokenTypeToString(token.type)
			<< ": "
			<< token.value
			<< '\n';
	}

	std::cout << "Token count: " << tokens.size() << '\n';

	Parser parser(std::move(tokens));

	auto declaration = parser.ParseVariable();

	std::cout
		<< "Parsed variable declaration: "
		<< declaration->name
		<< '\n';

	return 0;
}