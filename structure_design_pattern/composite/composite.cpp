#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Employee {
public:
    Employee(string &name, float salary) {}
    Employee(string &&name, float salary) {}
    virtual string get_name()=0;
    virtual void set_name(string &name)=0;
    virtual float get_salary()=0;
    virtual void set_salary(float &salary)=0;
    virtual ~Employee(){}
};

class Developer: public Employee {
public:
    Developer(string &name, float salary): Employee(name, salary)
    {
        this->name = name;
        this->salary = salary;
    }
    Developer(string &&name, float salary): Employee(name, salary)
    {
        this->name = name;
        this->salary = salary;
    }
    virtual string get_name() override
    {
        return name;
    }
    virtual void set_name(string &name) override
    {
        this->name = name;
    }
    virtual float get_salary() override
    {
        return this->salary;
    }
    virtual void set_salary(float &salary) override
    {
        this->salary = salary;
    }
private:
    string name;
    int salary;
};
class Designer: public Employee {
public:
    Designer(string &name, float salary): Employee(name, salary)
    {
        this->name = name;
        this->salary = salary;
    }
    Designer(string &&name, float salary): Employee(name, salary)
    {
        this->name = name;
        this->salary = salary;
    }
    virtual string get_name() override
    {
        return name;
    }
    virtual void set_name(string &name) override
    {
        this->name = name;
    }
    virtual float get_salary() override
    {
        return this->salary;
    }
    virtual void set_salary(float &salary) override
    {
        this->salary = salary;
    }
private:
    string name;
    int salary;
};

class Organization
{
public:
    Organization(int size)
    {
        employees.reserve(size);
    }
    void add_employee(Employee* employee)
    {
        employees.push_back(employee);
    }
    float get_total_salary()
    {
        float total = 0;
        for(int i =0; i < employees.size(); i++)
        {
            total += employees[i]->get_salary();
        }
        return total;
    }
private:
    vector<Employee*> employees;
};

int main(int argc, char** argv)
{
    Employee* desinger1= new Designer("bob", 100);
    Employee* desinger2 = new Designer("blues", 200);

    Employee* developer1 = new Developer("kevin", 150);
    Employee* developer2 = new Developer("lucy", 250);

    Organization* company = new Organization(10);
    company->add_employee(desinger1);
    company->add_employee(developer1);
    company->add_employee(desinger2);
    company->add_employee(developer2);

    cout <<"total salary is " <<  company->get_total_salary() << endl;
    return 0;
}
