#include "employee.h"

Employee:: Employee(const Employee & e)
{
    _id = e._id;
    _salary = e._salary;
    _seniority = e._seniority;
}

void Employee::load(std:: ifstream & in)
{
    int id_length;

    in.read((char *)& id_length, sizeof(id_length)); 
    char * buff = new char [(id_length + 1)];
    in.read(buff , id_length);
    buff[id_length] = '\0';
    _id = buff;
    in.read((char * )&_salary, sizeof(_salary));
    in.read((char *)&_seniority, sizeof(_seniority));

}



