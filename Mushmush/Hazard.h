#pragma once

#include <string>
using namespace std;

class Hazard
{
public:
    Hazard(){};
    ~Hazard(){};

public:
    virtual string messageWarning() const = 0;
    virtual string messageAttack() const = 0;
    virtual string messageClash() const = 0;
};

