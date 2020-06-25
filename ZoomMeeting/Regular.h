#pragma once

#include "Participant.h"

class Regular : public Participant
{
public:
	Regular(const string& name, bool viewSharedScreen = false) : Participant(name), m_viewSharedScreen(viewSharedScreen) {}
	Regular() : m_viewSharedScreen(false) {}
public:
    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);

private:
    bool m_viewSharedScreen;
};