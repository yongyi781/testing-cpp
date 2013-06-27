// TestCppApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void printAll()
{
	cout << endl;
}

template<typename First, typename... Rest>
void printAll(First car, Rest... cdr)
{
	cout << car << " ";
	printAll(cdr...);
}

template<typename T = int>
T f() { return T(5); }

int __vectorcall add(int a, int b, int c, int d)
{
	return a + b + c + d;
}

int _tmain(int argc, _TCHAR* argv[])
{
	mt19937 eng;
	int a = eng(), b = eng(), c = eng(), d = eng();
	cout << add(a, b, c, d) << endl;
	
}
