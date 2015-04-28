#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    public:
        Employee(char *employeeName, int employeeLevel);
        virtual ~Employee();
        int calcSalary();
        char* getName();
        int getLevel();
        bool setLevel(int level);
    protected:
    private:
        char* _name;
        int _level;
};

#endif // EMPLOYEE_H
