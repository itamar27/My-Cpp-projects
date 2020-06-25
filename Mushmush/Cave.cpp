#include "Cave.h"

//----------------------------------------------------------------------------------------//
Cave::Cave(const int *const sealedRooms, int size)
{

    for (int i = 0; i < 20; i++)
    {
        int odd = 2 + 2 * (i & 1);
        bool flag = true;
        for (int j = 0; j < size; ++j)
        {
            if (i == *(sealedRooms + j))
            {
                _rooms[i] = new SealedRoom(19 - i, (i + odd) % 20, ((i - odd + 20) % 20));
                flag = false;
                break;
            }
        }
        if (flag)
            _rooms[i] = new RegularRoom(19 - i, (i + odd) % 20, ((i - odd + 20) % 20));
    }

    _gameInProgres = true;
}

//----------------------------------------------------------------------------------------//
const Room *Cave::getRoomAtIndex(int index) const
{
    if ((index < 0) || (index > 19))
        throw "Invalid Index Exception";

    return _rooms[index];
}

//----------------------------------------------------------------------------------------//
void Cave::plotHazard(int idx, const string &eventName)
{
    if ((idx < 0) || (idx > 19) || (_rooms[idx]->getHazard() != nullptr))
        throw "Invalid Index Exception";

    if ((eventName != "MushMush") && (eventName != "Bat") && (eventName != "Pit"))
        throw "Invalid Hazard Exception";
    Hazard *tmphaz;
    if (eventName == "MushMush")
        tmphaz = new MushMush;
    else if (eventName == "Bat")
        tmphaz = new Bat;
    else if (eventName == "Pit")
        tmphaz = new Pit;

    _rooms[idx]->setHazard(tmphaz);
}

//----------------------------------------------------------------------------------------//
void Cave::plotPlayerIdx(int idx)
{
    if ((idx < 0) || (idx > 19) || (_rooms[idx]->getHazard() != nullptr))
        throw "Invalid Index Exception";
    _player = idx;
}

//----------------------------------------------------------------------------------------//
int Cave::findMushMush(void) const
{
    for (int i = 0; i < 20; i++)
    {
        if (_rooms[i]->isMushMushHere())
            return i;
    }

    throw "MushMush Not Found Exception";
}

//----------------------------------------------------------------------------------------//
void Cave::movePlayer(int idx)
{
    if ((idx < 0) || (idx > 19) || (_rooms[_player]->getTunnel1() != idx) && (_rooms[_player]->getTunnel2() != idx) && (_rooms[_player]->getTunnel3() != idx))
        throw "Invalid Index Exception";

    _player = idx;
}

//----------------------------------------------------------------------------------------//
string Cave::playerAttack(int idx)
{
    if ((_rooms[_player]->getTunnel1() != idx) && (_rooms[_player]->getTunnel2() != idx) && (_rooms[_player]->getTunnel3() != idx))
        throw "Invalid Index Exception";

    string tmp;
    _rooms[idx]->attackInRoom(tmp);

    if ((tmp == "You got MushMush") || (tmp == "You just shot yourself"))
    {
        _gameInProgres = false;
        return tmp;
    }

    int location = findMushMush();
    int tunnel1 = _rooms[location]->getTunnel1();
    int tunnel2 = _rooms[location]->getTunnel2();
    int tunnel3 = _rooms[location]->getTunnel3();
    if (_rooms[tunnel1]->roomIsEmpty())
    {
        _rooms[tunnel1]->setHazard(_rooms[location]->getHazard());
        _rooms[location]->setHazard(nullptr);
    }
    else if (_rooms[tunnel2]->roomIsEmpty())
    {
        _rooms[tunnel2]->setHazard(_rooms[location]->getHazard());
        _rooms[location]->setHazard(nullptr);
    }
    else if (_rooms[tunnel3]->roomIsEmpty())
    {
        _rooms[tunnel3]->setHazard(_rooms[location]->getHazard());
        _rooms[location]->setHazard(nullptr);
    }
    return tmp;
}

//----------------------------------------------------------------------------------------//
bool Cave::gameOver() const
{
    return !_gameInProgres;
}

//----------------------------------------------------------------------------------------//
void Cave::hazardNearPlayer(string *hazards) const
{
    *hazards = _rooms[_rooms[_player]->getTunnel1()]->roomHazard();
    *(hazards + 1) = _rooms[_rooms[_player]->getTunnel2()]->roomHazard();
    *(hazards + 2) = _rooms[_rooms[_player]->getTunnel3()]->roomHazard();
}

//----------------------------------------------------------------------------------------//
string Cave::playerClash(int idx)
{
    if ((idx < 0) || (idx > 19) || (_rooms[_player]->getTunnel1() != idx) && (_rooms[_player]->getTunnel2() != idx) && (_rooms[_player]->getTunnel3() != idx))
        throw "Invalid Index Exception";

    string tmp;
    if (_rooms[_player]->getHazard() != nullptr)
    {
        if (typeid(*(_rooms[_player]->getHazard())) == typeid(Bat))
        {
            _rooms[_player]->setHazard(nullptr);
            movePlayer(idx);
            tmp = playerClash(_rooms[idx]->getTunnel1());
        }

        else if ((typeid(*(_rooms[_player]->getHazard())) == typeid(MushMush)) || (typeid(*(_rooms[_player]->getHazard())) == typeid(Pit)))
        {
            _gameInProgres = false;
        }
    }
    _rooms[_player]->clashInRoom(tmp);
    return tmp;
}

//----------------------------------------------------------------------------------------//
Cave::~Cave()
{
    for (int i = 0; i < 20; i++)
        delete _rooms[i];
}