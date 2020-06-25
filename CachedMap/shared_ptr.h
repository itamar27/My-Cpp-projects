#pragma once

#include <string>
#include <iostream>
#include "counter.h"

template <class T>
class SharedPtr
{
public:
    SharedPtr(T *p) : _p(p), _counter(new Counter()) { _counter->incUse(); }

    ~SharedPtr() { decrementRef(); }

    SharedPtr(const SharedPtr<T> &p) : _counter(NULL)
    {
        *this = p;
    }

    const SharedPtr<T> &operator=(const SharedPtr<T> &sp)
    {
        decrementRef();
        _p = sp._p;
        _counter = sp._counter;
        _counter->incUse();
        return *this;
    }

    T *operator->() const { return _p; }

    T operator*() const { return *_p; }

    template<class U> friend class WeakPtr;


private:
    T *_p;
    Counter *_counter;

    void decrementRef()
    {
        if (_counter == NULL)
            return;

        _counter->decUse();

        if (_counter->getUse() == 0)
        {
            delete _p;
            _counter->decWeak();
            if (_counter->getWeak() == 0)
                delete _counter;
        }
    }
};