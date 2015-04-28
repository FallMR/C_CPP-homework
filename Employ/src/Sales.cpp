#include "Sales.h"

Sales::Sales(char* salesName, int salesLevel) : Employee(salesName, salesLevel) {}

Sales::~Sales() {}

void Sales::setSaleCount(int saleCount) {
    this->_saleCount = saleCount;
}

int Sales::calcSalary() {
    switch (this->getLevel()) {
    case 1:
        return this->_saleCount + 4000;
    case 2:
        return this->_saleCount + 5000;
    default:
        return -1;
    }
}
