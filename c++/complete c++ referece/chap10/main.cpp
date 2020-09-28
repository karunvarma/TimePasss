#include<stdio.h>
#include<iostream>

#define MAX 100
#define ACTIVE_COUNTRY US

#define makestr(s) #s
#define concat(a,b)  a ## b


/*
	#if
	#else
	#elif


*/

int main()
{
#if MAX > 99
	std::cout << "if" << std::endl;
#else
	std::cout << "else" << std::endl;
#endif



#if ACTIVE_COUNTRY == US
	char currency[] = "dollar";
#elif ACTIVE_COUNTRY == INR
	char currency[] = "INR";
#else
	char currency[] = "Winnie the Pooh"
#endif

		// ifdef takes macro name

#ifdef ACTIVE_COUNTRY
		std::cout << "defined" << std::endl;
#else
		std::cout << "not defined" << std::endl;
#endif


#undef ACTIVE_COUNTRY

#if defined ACTIVE_COUNTRY
	std::cout << "ACTIVE_COUNTRY is defined" << std::endl;
#else
	std::cout << "ACTIVE_COUNTRY is not defined " << std::endl;
#endif

#if !defined ACTIVE_COUNTRY
	std::cout << "ACTIVE_COUNTRY is defined" << std::endl;
#else
	std::cout << "ACTIVE_COUNTRY is not defined " << std::endl;
#endif



//One reason for using defined is that it allows the existence
//of a macro name to be determined by a #elif statement.


	// stringize operator
	printf(makestr(string without quotes\n));
	

	// pasting operator
	int xy = 20;
	printf("%d", concat(x, y));

}
