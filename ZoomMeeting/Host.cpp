#include "Host.h"


/*----------------------------------------------------------------------------*/
istream& Host::read(istream& in)
{
	string buff;
	Participant::read(in);
	getline(in, buff);
	m_shareScreen = atoi(buff.c_str());
	return in;
}

/*----------------------------------------------------------------------------*/
ostream& Host::write(ostream& out)
{
	Participant::write(out);
	out << m_shareScreen <<endl;
	return out;
	
}