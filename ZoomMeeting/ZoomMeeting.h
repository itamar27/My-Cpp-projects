#pragma once

#include "Participant.h"
#include "Host.h"
#include "Regular.h"
#include <memory>
#include <vector>

class ZoomMeeting
{
public:
	ZoomMeeting(
		const string& name,
		const string& date,
		const string& startTime,
		const string& endTime,
		const string& id,
		int numOfParticipants,
		Participant** participants);
    
	ZoomMeeting() : m_numOfParticipants(0) {}
    ~ZoomMeeting();

public:
    void read(istream& in);
    void write(ostream& out) const;
	void removeParticipant(int idx) { m_participants.erase(m_participants.begin() + idx); --m_numOfParticipants;}

private:
	Participant * readParticipant(istream& in);
    void cleanParticipants();

private:
    string				m_name;
    string				m_date;
    string				m_startTime;
    string				m_endTime;
    string				m_Id;
	int					m_numOfParticipants;
	vector<shared_ptr<Participant>> m_participants;
};

istream& operator >> (istream& in, ZoomMeeting& superMarket);
ostream& operator << (ostream& out, const ZoomMeeting& superMarket);