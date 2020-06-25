#pragma once
#include "RegularRoom.h"
#include "SealedRoom.h"

#include <string>
using std::string;

class Room;

class Cave
{
public:
    Cave(const int *const sealedRooms, int size);
    ~Cave();
public:
    const Room *getRoomAtIndex(int index) const;
    void plotHazard(int idx, const string &eventName);
    void plotPlayerIdx(int idx);
    int findMushMush(void) const;
    void movePlayer(int idx);
    string playerAttack(int idx);
    string playerClash(int idx);
    bool gameOver() const;

    void hazardNearPlayer(string *hazards) const;

private:
    Room* _rooms[20];
    int   _player;
    bool _gameInProgres;
};
