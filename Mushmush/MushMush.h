#pragma once

#include "Hazard.h"

class MushMush : public Hazard
{
public:
    MushMush(){};
    ~MushMush(){};

public:
    virtual string messageWarning() const;
    virtual string messageAttack() const;
    virtual string messageClash() const;
};
