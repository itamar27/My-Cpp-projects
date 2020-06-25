#include "Participant.h"

/*----------------------------------------------------------------------------*/
istream& Participant::read(istream &in)
{
	string buff;
	getline(in, m_name);
	getline(in, buff);
	m_useMic = atoi(buff.c_str());
	getline(in, buff);
	m_useCam = atoi(buff.c_str());
	return in;

}

/*----------------------------------------------------------------------------*/
ostream& Participant::write(ostream &out)
{
	out << m_name << endl;
	out << m_useMic << endl;
	out << m_useCam << endl;
	return out;
}