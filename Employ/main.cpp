#include <iostream>
#include "Employee.h"
#include "Sales.h"

using namespace std;

int main()
{
    Employee man("Alice", 1);
    char* name = man.getName();
    int salary = man.calcSalary();
    cout << name << endl;
    cout << salary << endl;

    Sales sale("Bob", 2);
    name = sale.getName();
    sale.setSaleCount(2000);
    salary = sale.calcSalary();
    cout << name << endl;
    cout << salary << endl;
    return 0;
}
