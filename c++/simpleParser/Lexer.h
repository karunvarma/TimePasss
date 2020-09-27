#pragma once
#include<string>
#include<iostream>
#include<map>

namespace Lexer
{

	// for the purpose of symbol table we use hash table
	using varable_t = std::map<std::string, double>;

	enum class Kind :char
	{
		end, // end of file
		colon			=	';',
		plus			=	'+',
		minus			=	'-',
		mul				=	'*',
		div				=	'/',
		assign			=	'=',
		left_open		=	'(',
		right_open		=	')',
		newline			=	'\n',
		number,
		varaible
	};

	struct Token
	{
		Kind kind;	// if its a kind
		std::string variable_name;  //if its a variable name
		double number;	// if its a number
	};

	class ClassLexer
	{
	private:
		std::istream& m_stream;
		Token m_current_token;

	public:
		
		ClassLexer() : m_stream{ std::cin } {}
		Token& get_current_token();
		Token fetch_next_token();
		void get_next_char(char& chr);
	};

}
