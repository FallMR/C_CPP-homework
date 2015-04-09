#include <vector>

#ifndef STACK_H
#define STACK_H

#define INF 0x7fffff;

using namespace std;

class Stack {
    private:
        vector<int> st;
    public:
        Stack();
        void Push(int n);
        void Pop();
        bool isEmpty();
        int Top();
        int Size();
};

#endif // STACK_H
