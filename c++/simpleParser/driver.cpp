#include<iostream>
#include "Lexer.h"
#include "Parser.h"

void test_lexer()
{
	
	using namespace Lexer;

	// creating a lexer object 
	ClassLexer lexer;

	

	while (lexer.fetch_next_token().kind != Kind::end)
	{
		switch (lexer.get_current_token().kind)
		{
		case Kind::varaible:
			std::cout << "Variable: "
				<< lexer.get_current_token().variable_name << std::endl;
			break;

		case Kind::number:
			std::cout << "Number: "
				<< lexer.get_current_token().number << std::endl;
			break;
		default:
			std::cout << "Operator: "
				<<(char) lexer.get_current_token().kind << std::endl;

		}

	}

	if (lexer.get_current_token().kind == Kind::end)
	{
		std::cout << "program ended" << std::endl;
	}


}


void test_primary()
{
	Parser::CParser parser;
	parser.calculate();
}


int main()
{
	test_primary();
}