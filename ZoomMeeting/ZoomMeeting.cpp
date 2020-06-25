#include "ZoomMeeting.h"
#include "Host.h"
#include "Regular.h"

/*----------------------------------------------------------------------------*/
ZoomMeeting::ZoomMeeting(
	const string &name,
	const string &date,
	const string &startTime,
	const string &endTime,
	const string &id,
	int numOfParticipants,
	Participant **participants)
	: m_name(name),
	  m_date(date),
	  m_startTime(startTime),
	  m_endTime(endTime),
	  m_Id(id),
	  m_numOfParticipants(numOfParticipants)
{
	for (int i = 0; i < m_numOfParticipants; i++)
	{
		auto p = move(shared_ptr<Participant>(participants[i])); //unique_ptr<Participant>(participant[i])
		m_participants.push_back(p);
	}
}
/*----------------------------------------------------------------------------*/
void ZoomMeeting::cleanParticipants()
{
	for (int i = 0; i < m_numOfParticipants; i++)
	{
		removeParticipant(i);
	}
}
/*----------------------------------------------------------------------------*/
ZoomMeeting::~ZoomMeeting()
{
	cleanParticipants();
}
/*----------------------------------------------------------------------------*/
void ZoomMeeting::read(istream &in)
{
	string buffer;

	getline(in, buffer);
	m_name = buffer;

	getline(in, buffer);
	m_date = buffer;

	getline(in, buffer);
	m_startTime = buffer;

	getline(in, buffer);
	m_endTime = buffer;

	getline(in, buffer);
	m_Id = buffer;

	getline(in, buffer);
	m_numOfParticipants = atoi(buffer.c_str());

	for(int i=0; i < m_numOfParticipants; ++i)
	{
		auto p = move(shared_ptr<Participant>(readParticipant(in)));
		m_participants.push_back(p);
	}
}
/*----------------------------------------------------------------------------*/
Participant *ZoomMeeting::readParticipant(istream &in)
{
	string type;
	vector<string> buffer;
	buffer.resize(4);
	Participant *temp;
	bool shareScreen;

	getline(in, type);
	getline(in, buffer[0]);
	getline(in, buffer[1]);
	getline(in, buffer[2]);
	getline(in, buffer[3]);

	if (buffer[3] == "1")
		shareScreen = true;

	if (type == "H")
		temp = new Host(buffer[0], shareScreen);
	else
		temp = new Regular(buffer[0], shareScreen);

	return temp;
}
/*----------------------------------------------------------------------------*/
void ZoomMeeting::write(ostream &out) const
{
	out << m_name << endl;
	out << m_date << endl;
	out << m_startTime << endl;
	out << m_endTime << endl;
	out << m_Id << endl;
	out << m_numOfParticipants << endl;

	for (int i = 0; i < m_numOfParticipants; ++i)
	{
		if (typeid(*m_participants[i]) == typeid(Host))
			out << "H" << endl;
		else
			out << "R" << endl;

		m_participants[i]->write(out);
	}
}
/*----------------------------------------------------------------------------*/
istream &operator>>(istream &in, ZoomMeeting &zoomMeeting)
{
	zoomMeeting.read(in);
	return in;
}
/*----------------------------------------------------------------------------*/
ostream &operator<<(ostream &out, const ZoomMeeting &zoomMeeting)
{
	zoomMeeting.write(out);
	return out;
}
/*----------------------------------------------------------------------------*/