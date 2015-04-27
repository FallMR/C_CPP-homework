#ifndef ITERATOR_H
#define ITERATOR_H

#include "Stack.h"

class Iterator {
    public:
        Iterator();
        virtual ~Iterator();
        int* next();
        friend class Stack;
    private:
        int* p_data;
        int* p_dataEnd;
};

#endif
