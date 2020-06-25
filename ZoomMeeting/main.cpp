#include <iostream>
#include <fstream>
#include "ZoomMeeting.h"

using namespace std;
int main (void)
{
	{
		std::shared_ptr<ZoomMeeting> meeting(new ZoomMeeting);

		// Input.txt is located within the ZIP file! Place it within your 'working directory' or just replace the path below with an absolute path
		ifstream in("Input.txt");
		if (!in.is_open())
		{
			cerr << "Could not open file: Input.txt\n";
			return -1;
		}
		in >> *meeting; // Calls istream& operator >> (istream&, ZoomMeeting&)

		cout << *meeting << endl; // Calls ostream& operator << (ostream&, const ZoomMeeting&)

		in.close();

		ofstream out("Copy.txt");
		if (!out.is_open())
		{
			cerr << "Could not create file: Copy.txt\n";
			return -1;
		}

		out << meeting.get() << endl;// Calls ostream& operator << (ostream&, const ZoomMeeting&)
		out.close();

		std::shared_ptr<ZoomMeeting> meeting2 = meeting;

		meeting2->removeParticipant(3);
		cout << *meeting2 << endl;
	}
	cin.get();
    return 0;
}