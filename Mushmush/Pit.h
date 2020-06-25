#pragma once
#include "Hazard.h"

class Pit : public Hazard
{
public:
    Pit(){};
    ~Pit(){};

public:
    virtual string messageWarning() const;
    virtual string messageAttack() const;
    virtual string messageClash() const;
};