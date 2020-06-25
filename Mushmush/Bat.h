#pragma once

#include "Hazard.h"

class Bat : public Hazard
{
public:
    Bat(){};
    ~Bat(){};

public:
    virtual string messageWarning() const;
    virtual string messageAttack() const;
    virtual string messageClash() const;
};
