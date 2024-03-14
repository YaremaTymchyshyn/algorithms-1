#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '(' || op == ')');
}

bool isNumber(char el)
{
	return el >= '0' && el <= '9';
}

int priority(char op)
{
	switch (op)
	{
	case'(':
		return 0;
	case')':
		return 0;

	case'+':
		return 1;
	case'-':
		return 1;

	case'*':
		return 2;
	case'/':
		return 2;

	case'^':
		return 3;

	default:
		return -1;
	}
}

int evaluation(int var1, int var2, char op)
{
	switch (op)
	{
	case'+':
		return var1 + var2;
	case'-':
		return var1 - var2;
	case'*':
		return var1 * var2;
	case'/':
		return var1 / var2;
	case'^':
		return pow(var1, var2);
	default:
		throw exception("Invalid operation or variables");
	}
}

string toPostfix(string infix)
{
	stack <char> stk;
	string postfix = "";
	for (int i = 0; i < infix.length(); i++)
	{
		if (isNumber(infix[i]))
		{
			postfix += infix[i];
		}
		else if (infix[i] == '(')
		{
			stk.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (stk.top() != '(')
			{
				postfix += stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if (isOperator(infix[i]))
		{
			while (!stk.empty() && priority(infix[i]) <= priority(stk.top()))
			{
				postfix += stk.top();
				stk.pop();
			}
			stk.push(infix[i]);
		}
		else
		{
			throw exception("Invalid infix");
		}
	}
	while (!stk.empty())
	{
		postfix += stk.top();
		stk.pop();
	}
	return postfix;
}

int postfixCalculation(string postfix)
{
	stack <int> stc;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isNumber(postfix[i]))
		{
			int var = postfix[i] - 48;
			stc.push(var);
		}
		else if (isOperator(postfix[i]))
		{
			int b = stc.top();
			stc.pop();
			int a = stc.top();
			stc.pop();
			int result = evaluation(a, b, postfix[i]);
			stc.push(result);
		}
		else throw exception("Invalid postfix");
	}
	return stc.top();
}

bool Test1()
{
	bool passed = true;
	string s = "(4+1)*(1+2)";
	string sp = "41+12+*";
	string spf = toPostfix(s);
	passed = spf == sp;
	return passed;
}

bool Test2()
{
	bool passed = true;
	string s = "(2+1)*5";
	string sp = "21+5*";
	string spf = toPostfix(s);
	passed = spf == sp;
	int k = postfixCalculation(spf);
	passed = k == 15;
	return passed;
}

bool Test3()
{
	bool passed = true;
	passed = passed && priority('(') == 0;
	passed = passed && priority('-') == 1;
	passed = passed && priority('/') == 2;
	passed = passed && priority('^') == 3;
	return passed;
}

bool Test4()
{
	bool passed = true;
	string s = "(3+2)-1";
	string spf = toPostfix(s);
	int j = postfixCalculation(spf);
	passed = j == 4;
	return passed;
}

int main()
{
	cout << "Test 1: " << (Test1() ? "passed" : "failed") << endl;
	cout << "Test 2: " << (Test2() ? "passed" : "failed") << endl;
	cout << "Test 3: " << (Test3() ? "passed" : "failed") << endl;
	cout << "Test 4: " << (Test4() ? "passed" : "failed") << endl;
}