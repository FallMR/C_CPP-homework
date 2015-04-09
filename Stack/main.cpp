#include <iostream>
#include <windows.h>
#include <vector>
#include "Stack.h"

using namespace std;

int main() {
    Stack s;
    s.Push(2);
    s.Push(1);
    s.Push(3);
    while (!s.isEmpty()) {
        cout << s.Size() << endl;
        cout << s.Top() << endl;
        s.Pop();
    }
    return 0;
}
