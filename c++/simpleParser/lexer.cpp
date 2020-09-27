#include "Lexer.h"

namespace Lexer
{
	Token& ClassLexer::get_current_token()
	{
		return this->m_current_token;

	}

	void ClassLexer::get_next_char(char& chr)
	{
		// skip all the blank spaace
		while (this->m_stream.get(chr) && std::isblank(chr))
		{
			//std::cout << "-------------> blank" << std::endl;
		}
	}

	Token ClassLexer::fetch_next_token()
	{
		char nextChar = 0;

		// skip the blank spaces until a new character 
		this->get_next_char(nextChar);

		//std::cout << "--------------- next char is " << (int)nextChar << std::endl;


		
		switch (nextChar)
		{
			// this is an EOF
			case 0:
				
				this->m_current_token = { Kind::end };
				return this->m_current_token;

			// calculator symbols
			case '+':
			case '-':
			case '*':
			case '/':
			case '=':
			case '(':
			case ')':
				this->m_current_token = { static_cast<Kind>(nextChar) };
				return this->m_current_token;

			// in case of numbers
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':

				//std::cout << "Incase of number Putting back " << nextChar << std::endl;
				// put back the next character back to the stream
				this->m_stream.putback(nextChar);

				// if it is a number
				this->m_stream >> this->m_current_token.number;

				// set the token type to a number
				this->m_current_token.kind = Kind::number;
				
				return this->m_current_token;
				std::cout << "is it still there" << std::endl;

			default:
			{
				if (std::isalpha(nextChar))
				{
					// if not a eof or arithmetic or numbers then 
					// we take its as an variable name
					this->m_current_token.variable_name = nextChar;

					while (this->m_stream.get(nextChar) && std::isalnum(nextChar))
					{
						this->m_current_token.variable_name += nextChar;
					}
					
					//std::cout << "Putting back " << nextChar << std::endl;
					this->m_stream.putback(nextChar);
					this->m_current_token.kind = { Kind::varaible };

					return this->m_current_token;
				}
				else
				{

					// we are skipping the /n
					//std::cerr << "Syntax Error " << std::endl;

					if (nextChar == (int) Kind::newline)
					{
						//std::cout << "END" << std::endl;
					}
					this->m_current_token = { Kind::colon };
					return this->m_current_token;
				}
			}  // end of default
			
		}	// end of switch
 	} // end  of fetch_next_token

	
}