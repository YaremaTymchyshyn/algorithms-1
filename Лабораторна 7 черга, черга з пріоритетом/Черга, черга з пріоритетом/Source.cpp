#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;

class Node // вузол
{
public:
	int info;
	Node* prev;
	Node* next;
};

class List
{
	Node* top = new Node;
	Node* bottom = new Node;
	int size = 0;
public:
	List()
	{
		top->next = bottom;
		bottom->prev = top;
	}

	int GetSize()
	{
		return size;
	}

	void push(int _info)
	{
		size++;
		Node* new_node = new Node();
		new_node->info = _info;
		new_node->next = bottom;
		new_node->prev = bottom->prev;
		bottom->prev->next = new_node;
		bottom->prev = new_node;
	}

	int GetTop()
	{
		if (size == 0)
		{
			throw out_of_range("Queue is empty!");
		}
		return bottom->prev->info;
	}

	int GetBottom()
	{
		if (size == 0)
		{
			throw out_of_range("Queue is empty!");
		}
		return top->next->info;
	}

	int PopTop()
	{
		if (size == 0)
		{
			throw out_of_range("Queue is empty!");
		}
		size--;
		int valur = bottom->prev->info;
		Node* dlt = bottom->prev;
		bottom->prev->prev->next = bottom;
		bottom->prev = bottom->prev->prev;
		return valur;
	}

	int PopBot()
	{
		if (size == 0)
		{
			throw out_of_range("Queue is empty!");
		}
		size--;
		int valur = top->next->info;
		Node* dlt = top->next;
		top->next->next->prev = top;
		top->next = top->next->next;
		return valur;
	}
};

class Queue 
{
	List* _list;
public:
	Queue()
	{
		_list = new List;
	}

	int GetSize()
	{
		int g = _list->GetSize();
		return g;
	}

	void push(int a)
	{
		_list->push(a);
	}

	int pop()
	{
		int q;
		try
		{
			q = _list->PopBot();
			return q;
		}
		catch (exception& ex)
		{
			cout << "exception: " << ex.what() << endl;
		}
	}
};

bool Test1()
{
	bool passed = true;
	Queue q;
	q.push(9);
	q.push(4);
	q.push(1);
	passed = q.pop() == 9;
	return passed;
}

bool Test2()
{
	bool passed = true;
	Queue q;
	q.push(9);
	q.push(7);
	q.push(4);
	q.push(1);
	passed = q.GetSize() == 4;
	return passed;
}

bool Test3()
{
	bool passed = true;
	List l;
	l.push(7);
	l.push(3);
	l.push(6);
	passed = l.GetTop() == 6 && l.GetBottom() == 7;
	return passed;
}

int main()
{
	cout << "Test 1: " << (Test1() ? "passed" : "failed") << endl;
	cout << "Test 2: " << (Test2() ? "passed" : "failed") << endl;
	cout << "Test 3: " << (Test3() ? "passed" : "failed") << endl;
	return 0;
}