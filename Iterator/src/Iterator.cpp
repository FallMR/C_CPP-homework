#include "Iterator.h"
#include <stdio.h>

Iterator::Iterator() {}

Iterator::~Iterator() {}

int* Iterator::next()
{
	if (p_data == p_dataEnd)
	{
		return NULL;
	}
	return p_data++;
}
