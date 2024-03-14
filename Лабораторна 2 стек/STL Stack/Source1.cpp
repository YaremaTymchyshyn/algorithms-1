#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;

    stack.push(23);
    stack.push(46);
    stack.push(69);
    stack.push(82);
    stack.push(105);

    stack.pop();
    stack.pop();

    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
}