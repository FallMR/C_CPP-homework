#ifndef SALES_H
#define SALES_H

#include "Employee.h"

class Sales : public Employee {
    public:
        Sales(char* salesName, int salesLevel);
        virtual ~Sales();
        void setSaleCount(int saleCount);
        int calcSalary();
    protected:
    private:
        int _saleCount;
};

#endif // SALES_H
