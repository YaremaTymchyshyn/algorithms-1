#include <iostream>
#include <stdexcept>
using namespace std;

bool check1(string a)
{
	bool check_b = true;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != '0' &&  a[i] != '1')
		{
			check_b = false;
		}
	}
	return check_b;
}

bool check2(string a)
{
	bool check_b = true;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != '|' && a[i] != '*')
		{
			check_b = false;
		}
	}
	return check_b;
}

string binaryConvert(string expression)
{
	if (!check1(expression))
	{
		throw invalid_argument("error: invalid expression");
	}

	string rezult = expression;
link:
	for (int i = 0; i < rezult.size(); i++)
	{
		if (rezult[i] == '1')
		{
			rezult.erase(i, 1);
			rezult.insert(i, "0|");
		}
	}
	for (int i = 0; i < rezult.size() - 1; i++)
	{
		if (rezult[i] == '|' && rezult[i + 1] == '0')
		{
			rezult.erase(i, 2);
			rezult.insert(i, "0||");
			goto link;
		}
	}
	for (int i = 0; i < rezult.size(); i++)
	{
		if (rezult[i] == '0')
		{
			rezult.erase(i, 1);
			goto link;
		}
	}
	return rezult;
}

string mult(string expression)
{
	if (!check2(expression))
	{
		throw invalid_argument("error: invalid expression");
	}

	string rezult = expression;
link:

	for (int i = 0; i < rezult.size()-1; i++)
	{
		if (rezult[i] == '|' && rezult[i+1] == 'b')
		{
			rezult.erase(i, 2);
			rezult.insert(i, "ba|");
			goto link;
		}
	}

	for (int i = 0; i < rezult.size()-1; i++)
	{
		if (rezult[i] == 'a' && rezult[i+1] == 'b')
		{
			rezult.erase(i, 2);
			rezult.insert(i, "ba");
			goto link;
		}
	}

	for (int i = 0; i < rezult.size(); i++)
	{
		if (rezult[i] == 'b')
		{
			rezult.erase(i, 1);
			goto link;
		}
	}

	for (int i = 0; i < rezult.size()-1; i++)
	{
		if (rezult[i] == '*' && rezult[i+1] == '|')
		{
			rezult.erase(i, 2);
			rezult.insert(i, "b*");
			goto link;
		}
	}

	for (int i = 0; i < rezult.size(); i++)
	{
		if (rezult[i] == '*')
		{
			rezult.erase(i, 1);
			rezult.insert(i, "c");
			goto link;
		}
	}

	for (int i = 0; i < rezult.size()-1; i++)
	{
		if (rezult[i] == '|' && rezult[i+1] == 'c')
		{
			rezult.erase(i, 2);
			rezult.insert(i, "c");
			goto link;
		}
	}

	for (int i = 0; i < rezult.size()-1; i++)
	{
		if (rezult[i] == 'a' && rezult[i+1] == 'c')
		{
			rezult.erase(i, 2);
			rezult.insert(i, "c|");
			goto link;
		}
	}

	for (int i = 0; i < rezult.size(); i++)
	{
		if (rezult[i] == 'c')
		{
			rezult.erase(i, 1);
			goto link;
		}
	}

	return rezult;
}

bool test1()
{
	bool passed = true;
	string str1("101");
	string str2("||*||");
	if (!check1(str1) || !check2(str2))
	{
		passed = false;
	}
	if (check1(str2) || check2(str1))
	{
		passed = false;
	}
	return passed;
}

bool test2()
{
	bool passed = true;
	string str1("10");
	string str2("1");
	if (binaryConvert(str1) != "||" || binaryConvert(str2) != "|")
	{
		passed = false;
	}
	return passed;
}

bool test3()
{
	bool passed = true;
	string str1("|||*||");
	if (mult(str1) != "||||||")
	{
		passed = false;
	}
	return passed;
}

int main()
{
	try
	{
		cout << "\tTest 1: " << (test1() ? "passed" : "failed") << endl;
		cout << "\tTest 2: " << (test2() ? "passed" : "failed") << endl;
		cout << "\tTest 3: " << (test3() ? "passed" : "failed") << endl;
		return 0;
	}
	catch(exception& exc)
	{
		cout << exc.what();
	}
}