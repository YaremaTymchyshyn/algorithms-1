#include <iostream>
using namespace std;

class Steak
{
private:
	int* steak;
	unsigned int steakSize;
	unsigned int top = 0;
public:
	Steak()
	{
		steak = new int[100];
		steakSize = 100;
	}
	~Steak()
	{
		delete[] steak;
	}
	void push(int valur)
	{
		if (top >= steakSize - 1)
		{
			int* tastySteak = new int[steakSize * 2];
			for (int i = 0; i < steakSize; i++)
			{
				tastySteak[i] = steak[i];
			}
			delete[] steak;
			steakSize *= 2;
			steak = tastySteak;
		}
		steak[top] = valur;
		top++;
		cout << valur << " pushed into stack\n";
	}
	int pop()
	{
		int returnValur;
		top--;
		returnValur = steak[top];
		return returnValur;
		returnValur;
	}
};

int main()
{
	//// first test
	//class Steak stack;
	//stack.push(5);
	//stack.push(10);
	//stack.push(15);
	//stack.push(20);
	//stack.push(25);
	//cout << stack.pop() << " popped from stack\n";
	//cout << stack.pop() << " popped from stack\n";

	// second test
	class Steak steck;
	steck.push('a');
	steck.push('b');
	steck.push('c');
	steck.push('d');
	cout << steck.pop() << " popped from stack\n";
	cout << steck.pop() << " popped from stack\n";

	//// third test
	//class Steak stack;
	//stack.push(1);
	//stack.push(2);
	//stack.push(3);
	//stack.push(4);
	//stack.push(5);
	//cout << stack.pop(3) << " popped from stack\n";
	//cout << stack.pop(2) << " popped from stack\n";

	return 0;
}