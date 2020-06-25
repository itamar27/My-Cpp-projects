#include "SealedRoom.h"

//----------------------------------------------------------------------------------------//
SealedRoom::SealedRoom(int tunnel1, int tunnel2,int tunnel3) : Room::Room(tunnel1, tunnel2, tunnel3){}

//----------------------------------------------------------------------------------------//
SealedRoom::~SealedRoom()
{
    delete _hazard;
}


//----------------------------------------------------------------------------------------//
bool SealedRoom::attackInRoom(string &message) const
{
    message = "You just shot yourself";
    return true;
}

//----------------------------------------------------------------------------------------//
