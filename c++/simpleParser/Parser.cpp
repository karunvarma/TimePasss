#include "Parser.h"


namespace Parser
{

	// 5 + 9

	double CParser::expression()
	{
		// nextToken it will has false for the first time;
		double left = this->term();

		// for the further prcoessing
		
		switch (this->m_lexer.get_current_token().kind)
		{
		case Lexer::Kind::plus :
			this->m_lexer.fetch_next_token();
			left += this->expression();
			return left;
		case Lexer::Kind::minus :
			this->m_lexer.fetch_next_token();
			left -= this->expression();
			return left;
		default :
			return left;
		}
		
	}



	double CParser::term( )
	{

		double primary = this->primary();

		switch (this->m_lexer.get_current_token().kind)
		{
		case Lexer::Kind::mul :
			this->m_lexer.fetch_next_token();
			primary *= this->term();
			break;

		case Lexer::Kind::div :
			this->m_lexer.fetch_next_token();
			primary /= this->term();
			break;
		}
		return primary;
	}

	double CParser::primary()
	{
		
		// we can directly use the get current token because before comming to this 
		//fucntion  some other fucntion has already got the pointer incremeneted for us
		switch (this->m_lexer.get_current_token().kind)
		{
			case Lexer::Kind::number :
			{
				double curr_num = this->m_lexer.get_current_token().number;
				this->m_lexer.fetch_next_token();
				return curr_num;
			}
			case Lexer::Kind::varaible :
			{

				// get current token will actuall given the name
				double& v = this->symboltable[this->m_lexer.get_current_token().variable_name];


				// to check for equal sign we need to incremnt the pointer
				if (this->m_lexer.fetch_next_token().kind == Lexer::Kind::assign)
				{

					// this is for parsing the expression
					this->m_lexer.fetch_next_token();
					v = this->expression();
				}

				return v;
			}
		

			case Lexer::Kind::minus :
			{
				// to parse the primary we need to incremnt the pointer
				this->m_lexer.fetch_next_token();
				return (-1) * (this->primary());
			}



			case Lexer::Kind::left_open :
			{

				// for expression parsing we need to increment the pointer
				this->m_lexer.fetch_next_token();

				// v contains the expression value
				double v = this->expression();

				// check for right paranthesis
				if (this->m_lexer.get_current_token().kind != Lexer::Kind::right_open)
				{
					std::cerr << "Syntax Error:\')\' is expected" << std::endl;
					// need to raise an exception
					return 0;
				}
				// before  returning increment pointer
				this->m_lexer.fetch_next_token();
				return v;
			}


			default :
				std::cerr << "Syntax Error" << std::endl;
				// stop program excution
				return 0;
		} // end of switch
	} // end of primary


	// AS PER THE RULE -> BEFORE RETURNIG RESULT POINT TO THE NEXT TOKEN

	void CParser::calculate()
	{

		do
		{

			
			// for the first token from the buffer
			this->m_lexer.fetch_next_token();

			// parse  the expression with no need to again fet
			std::cout << this->expression() << std::endl;

		}
		// we need to check for the next input not the current one, for that 
		while (this->m_lexer.get_current_token().kind != Lexer::Kind::end);

	}
	
	



}