#include <iostream>
using namespace std;

struct TableElement
{
	unsigned char key = char(0);
	int valur = 0;
	TableElement() {}
	TableElement(char _key, int _valur) : key(_key), valur(_valur) {}
};

class HashTable
{
	static const unsigned int MaxSize = 10;
	TableElement table[MaxSize];
	unsigned int get_hash(unsigned char key)
	{
		unsigned int hash;
		hash = key % MaxSize;
		return hash;
	}
public:
	HashTable() {}

	void add_row(TableElement new_row)
	{
		unsigned int hash = get_hash(new_row.key);
		int rehash = 0;
		while (table[(hash + rehash) % MaxSize].key != table[(hash + rehash) % MaxSize].key != 0)
		{
			rehash++;
		}
		table[(hash + rehash) % MaxSize] = new_row;
	}

	bool find_by_key(char key, TableElement& found_element)
	{
		bool found = false;
		unsigned int hash = get_hash(key);
		int rehash = 0;

		while (table[(hash + rehash) % MaxSize].key != key && table[(hash + rehash) % MaxSize].key != 0)
		{
			rehash++;
		}

		if (table[(hash + rehash) % MaxSize].key == key)
		{
			found_element = table[(hash + rehash) % MaxSize];
			found = true;
		}

		return found;
	}
};

bool table_test_1()
{
	bool passed = true;
	HashTable tabl;
	TableElement element;

	element.key = 'W';
	element.valur = 20;
	tabl.add_row(element);

	element.key = 'X';
	element.valur = 30;
	tabl.add_row(element);

	element.key = 'Y';
	element.valur = 40;
	tabl.add_row(element);

	passed &= !tabl.find_by_key('Z', element);

	passed &= tabl.find_by_key('X', element);
	passed &= element.key == 'X';
	passed &= element.valur == 30;

	return passed;
}

bool table_test_2()
{
	bool passed = true;
	HashTable tabl;
	TableElement element;

	element.key = 'D';
	element.valur = 47;
	tabl.add_row(element);

	element.key = 'P';
	element.valur = 81;
	tabl.add_row(element);

	element.key = 'Q';
	element.valur = 39;
	tabl.add_row(element);

	passed &= !tabl.find_by_key('L', element);

	passed &= tabl.find_by_key('P', element);
	passed &= element.key == 'P';
	passed &= element.valur == 81;

	passed &= tabl.find_by_key('Q', element);
	passed &= element.key == 'Q';
	passed &= element.valur == 39;

	return passed;
}

bool table_test_3()
{
	bool passed = true;
	HashTable tabl;
	TableElement element;

	element.key = 'Q';
	element.valur = 96;
	tabl.add_row(element);

	element.key = 'W';
	element.valur = 43;
	tabl.add_row(element);

	element.key = 'R';
	element.valur = 218;
	tabl.add_row(element);

	passed &= !tabl.find_by_key('G', element);
	passed &= tabl.find_by_key('Q', element);
	passed &= element.key == 'Q';
	passed &= element.valur == 96;

	return passed;
}

int main()
{
	cout << "Table tests" << endl;
	cout << "Test 1:" << (table_test_1() ? "passed" : "failed") << endl;
	cout << "Test 2:" << (table_test_2() ? "passed" : "failed") << endl;
	cout << "Test 3:" << (table_test_3() ? "passed" : "failed") << endl;

	return 0;
}