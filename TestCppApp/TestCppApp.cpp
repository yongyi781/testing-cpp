// TestCppApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

template<class F0>
double timeFunc(F0 f, int repetitions = 1)
{
	auto t = chrono::system_clock::now();
	for (int i = 0; i < repetitions; ++i)
		f();
	auto x = chrono::system_clock::now() - t;
	return (double)chrono::duration_cast<chrono::nanoseconds>(x).count() / repetitions / 1000000000;
}

_ULonglong f(int a, _ULonglong b = 0, _ULonglong c = 1)
{
	return a <= 1 ? c : f(a - 1, c, b + c);
}

_ULonglong f_slow(int n)
{
	return n <= 1 ? n : f_slow(n - 1) + f_slow(n - 2);
}

class X : std::list<int>
{
public:
	size_t mf1() const { return list::size(); }
	size_t mf2() const { return std::list<int>::size(); }
};

void f(const string* s)
{
	cout << *s << endl;
}

class A
{
public:
	A(string s) : _s(s) { }
	string s() { return this->_s; }
private:
	string& _s;
};

void printBinary(__int64 val)
{
	while (val != 0)
	{
		putchar((val & 0x1) + '0');
		val >>= 1;
	}
	cout << endl;
}

void toStringPow2(int n)
{
	double logn = n * log10(2);
	double fracPart = pow(10, logn - (int)floor(logn));
	cout << setprecision(100) << fracPart;
}

void toString(int inputint, char **str)
{
	int j = 0;

	if (inputint < 0){
		inputint = -inputint;
		j = 1;
	}

	int logged = (int)(log(inputint) / log(10));
	char* string = (char*)malloc(logged + j + 1);

	if (j) {
		string[logged + 1] = 0;
		string[0] = '-';
	}
	else {
		string[logged] = 0;
	}

	while (inputint){
		string[j] = 0x30 + (inputint - (inputint / 10) * 10);
		inputint = inputint / 10;
		j++;
	}

	*str = string;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 1231231;
	char *eh;
	toString(i, &eh);
	printf(eh);
	printf("\n");
}
