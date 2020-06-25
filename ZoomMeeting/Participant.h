#include <iostream>
#include <string>

using namespace std;

#pragma once

class Participant
{
public:
	Participant(const string& name) : m_name(name) {}
	Participant() {}
   
public:
    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);

private:
    string	 m_name;
	bool	 m_useMic = false;
	bool     m_useCam = false;
};