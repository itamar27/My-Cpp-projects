#pragma once

class Counter
{
public:
    Counter() : _useCount(0), _weakCount(1) {}
    void incUse() { ++_useCount; }
    void incWeak() { ++_weakCount; }
    void decUse() { --_useCount; }
    void decWeak() { --_weakCount; }
    int getUse() const { return _useCount; }
    int getWeak() const { return _weakCount; }

private:
    int _useCount;
    int _weakCount;
};