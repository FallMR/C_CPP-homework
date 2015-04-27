#include <iostream>
#include <Windef.h>
#include "Stack.h"
#include "Iterator.h"

using namespace std;

int main()
{
    Stack s;

    s.sPush(1);
    s.sPush(2);

	Iterator* it1 = s.createIterator();

	cout << *(it1 -> next()) << endl;
	cout << *(it1 -> next()) << endl;

	Iterator* it2 = s.createIterator();
	cout << *(it2 -> next()) << endl;

	return 0;
}
