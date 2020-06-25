#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Employee
{
public:
    Employee() = default;
    Employee(const Employee & e);
    ~Employee(){};

    void load(std::ifstream &in_file);
  
    //----------------------------------------Helping functions----------------------------------------
    void printEmployee() const { std::cout << _id << " " << _salary << " "<< _seniority << std::endl;}
    std::string getID() const {return _id;}

private:
    std::string _id;
    int _salary;
    int _seniority;
};


