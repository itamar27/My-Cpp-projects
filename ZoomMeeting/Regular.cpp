#include "Regular.h"

/*----------------------------------------------------------------------------*/
istream& Regular::read(istream& in)
{
	string buff;
	Participant::read(in);
	getline(in, buff);
	m_viewSharedScreen= atoi(buff.c_str());
	return in;

}
/*----------------------------------------------------------------------------*/
ostream& Regular::write(ostream& out)
{
	Participant::write(out);
	out << m_viewSharedScreen <<endl;
	return out;
}