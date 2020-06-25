#pragma once
#include "Bat.h"
#include "Pit.h"
#include "MushMush.h"

#include <string>
using std:: string;

class Hazard;

#pragma pack(push, 1)
class Room
{
public:
    Room(int tunnel1, int tunnel2, int tunnel3);
    ~Room() ;

    virtual bool attackInRoom(string& message) const;
    int getTunnel1() const;
    int getTunnel2() const;
    int getTunnel3() const;
    string roomHazard() const;
    const Hazard* getHazard() const;
    
    bool roomIsEmpty() const;
    bool isMushMushHere() const;
    bool clashInRoom(string& msg) const;

    void setHazard(const Hazard* haz);
    
protected:
    const Hazard* _hazard;
private:
    int _tunnels[3];
};
#pragma pack(pop)