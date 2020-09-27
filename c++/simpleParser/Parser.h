#pragma once
#include "Lexer.h"

namespace Parser
{
	/* 
	
		recursive descent parser

		// root of the descent parser tree
		calculator:
			end // end of the stream or eof
			expr_list end

		expr_list:
			expression ';'			
			expr_list expression ';'  // left recursion

		expression:
			term
			term '+' expression
			term '-' expression

		term:
			primary
			primary '*' term
			primary '/' term

		primary:
			number
			variable
			variable '=' expression
			'-' primary
			'(' expression )

		


	*/

	class CParser
	{

	private:

		// parser constists of lexer
		Lexer::ClassLexer m_lexer;

		// parser consists of symbol table
		Lexer::varable_t symboltable;

	public:
		// addition and substraction
		double expression();


		// handle multiplication and division
		double term();


		// extracting a number  from a stream token
		// assign expression to a variable
		// handle unary minus
		// handle paranthesis
		double primary();

		void calculate();

	};
}