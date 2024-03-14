#include <iostream>
using namespace std;

struct TableElem
{
    char key = char(0);
    int value = 0;
    TableElem(){}
    TableElem(char _key, int _value) : key(_key), value(_value) {}
};

class SimpleTable
{
    static const unsigned int MaxSize = 100;
    TableElem table[MaxSize];
    unsigned int empty_index = 0;
public:
    SimpleTable() {}
    void add_row(TableElem new_row)
    {
        table[empty_index] = new_row;
        empty_index++;
    }
    bool find_by_key(char key, TableElem& found_element)
    {
        bool found = false;
        for (int i = 0; i < empty_index; i++)
        {
            if (table[i].key == key)
            {
                found_element = table[i];
                found = true;
                break;
            }
        }
        return found;
    }
};
    
bool table_test_1()
{
    bool passed = true;
    SimpleTable tabl1;
    TableElem element1;

    element1.key = 'A';
    element1.value = 20;
    tabl1.add_row(element1);

    element1.key = 'B';
    element1.value = 20;
    tabl1.add_row(element1);

    element1.key = 'C';
    element1.value = 40;
    tabl1.add_row(element1);

    passed &= !tabl1.find_by_key('D', element1);
    passed &= tabl1.find_by_key('B', element1);
    passed &= element1.key == 'B';
    passed &= element1.value == 20;

    return passed;
}

bool table_test_2()
{
    bool passed = true;
    SimpleTable tabl2;
    TableElem element2;

    element2.key = 'N';
    element2.value = 5;
    tabl2.add_row(element2);

    element2.key = 'D';
    element2.value = 15;
    tabl2.add_row(element2);

    element2.key = 'H';
    element2.value = 10;
    tabl2.add_row(element2);

    passed &= tabl2.find_by_key('D', element2);
    passed &= tabl2.find_by_key('H', element2);
    passed &= element2.key == 'H';
    passed &= element2.value == 10;

    return passed;
}

bool table_test_3()
{
    bool passed = true;
    SimpleTable tabl3;
    TableElem element3;

    element3.key = 'Q';
    element3.value = 96;
    tabl3.add_row(element3);

    element3.key = 'W';
    element3.value = 43;
    tabl3.add_row(element3);

    element3.key = 'R';
    element3.value = 218;
    tabl3.add_row(element3);

    passed &= !tabl3.find_by_key('G', element3);
    passed &= tabl3.find_by_key('Q', element3);
    passed &= element3.key == 'Q';
    passed &= element3.value == 96;

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