#pragma once

#include "Participant.h"

class Host : public Participant
{
public:
	Host(const string& name, bool shareScreen) : Participant(name), m_shareScreen(shareScreen){}
	Host() : m_shareScreen(false)  {}

public: 
    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);

private:
    bool m_shareScreen;
};