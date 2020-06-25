#pragma once
#include "Room.h"

class SealedRoom : public Room
{
public:
    SealedRoom(int tunnel1, int tunnel2, int tunnel3);
    ~ SealedRoom();

public:
    virtual bool attackInRoom(string& message) const;    

};