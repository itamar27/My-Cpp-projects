#include "Room.h"

//----------------------------------------------------------------------------------------//
Room::Room(int tunnel1, int tunnel2, int tunnel3) : _tunnels{tunnel1, tunnel2, tunnel3}, _hazard(nullptr) {}

//----------------------------------------------------------------------------------------//
int Room::getTunnel1() const
{
    int min = 0;
    for (int i = 1; i < 3; ++i)
    {
        if (_tunnels[i] < _tunnels[min])
            min = i;
    }
    return _tunnels[min];
}

//----------------------------------------------------------------------------------------//
int Room::getTunnel2() const
{
    int sum;
    sum  =_tunnels[0] + _tunnels[1] + _tunnels[2];
    int sub;
    sub = getTunnel3() + getTunnel1();
    return (sum - sub);
}

//----------------------------------------------------------------------------------------//
int Room::getTunnel3() const
{
    int max = 0;
    for (int i = 1; i < 3; ++i)
    {
        if (_tunnels[i] > _tunnels[max])
            max = i;
    }
    return _tunnels[max];
}

//----------------------------------------------------------------------------------------//
string Room::roomHazard() const
{
    if (_hazard == nullptr)
        return "";

    return _hazard->messageWarning();
}

//----------------------------------------------------------------------------------------//
bool Room::roomIsEmpty() const
{
    if (_hazard == nullptr)
        return true;

    return false;
}

//----------------------------------------------------------------------------------------//
bool Room::attackInRoom(string &message) const
{
    if (_hazard == nullptr)
    {
        message = "";
        return false;
    }

    message = _hazard->messageAttack();
    return true;
}

//----------------------------------------------------------------------------------------//
bool Room::clashInRoom(string &msg) const //if clash happend returns true else returns false
{
    if (_hazard == nullptr)
    {
        msg = "";
        return false;
    }
    msg = _hazard->messageClash();
    return true;
}

//----------------------------------------------------------------------------------------//
bool Room::isMushMushHere() const
{
    if(_hazard)
    {
        if (typeid(*_hazard) == typeid(MushMush))
            return true;
    }
    return false;
}

//----------------------------------------------------------------------------------------//
const Hazard *Room::getHazard() const
{
    return _hazard;
}

//----------------------------------------------------------------------------------------//
void Room::setHazard(const Hazard* haz)
{
    _hazard = haz;
}


//----------------------------------------------------------------------------------------//

Room::~Room()
{
    
};