#ifndef __STACK_H__
#define __STACK_H__

#include "Iterator.h"

using namespace std;

class Stack {
    public:
        Stack();
        virtual ~Stack();
        void sPush(int value);
        void sPop();
        int sTop();
        class Iterator* createIterator();
    private:
        int data[1000];
        int dataSize;
};

#endif
