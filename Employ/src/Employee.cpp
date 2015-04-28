#include "Employee.h"

Employee::Employee(char* employeeName, int employeeLevel) {
    this->_name = employeeName;
    this->_level = employeeLevel;
}

Employee::~Employee() {}

int Employee::calcSalary() {
    switch (this->_level) {
    case 1:
        return 4000;
    case 2:
        return 5000;
    default:
        return -1;
    }
}

char* Employee::getName() {
    return this->_name;
}

int Employee::getLevel() {
    return this->_level;
}

bool Employee::setLevel(int level) {
    if (level != 1 && level != 2) return false;
    this->_level = level;
}
