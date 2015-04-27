#include "Stack.h"

Stack::Stack() {
	dataSize = 0;
}

Stack::~Stack() {}

void Stack::sPush(int dataValue) {
	data[dataSize++] = dataValue;
}

void Stack::sPop() {
    dataSize--;
}

int Stack::sTop() {
    return data[dataSize];
}

Iterator* Stack::createIterator() {
	Iterator* it = new Iterator();
	it->p_data = data;
	it->p_dataEnd = data + dataSize;
	return it;
}
