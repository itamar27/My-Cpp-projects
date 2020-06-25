#pragma once

#include "shared_ptr.h"

template <class T>
class WeakPtr
{
public:
    WeakPtr() : _shared(NULL), _counter(NULL) {}

    WeakPtr(SharedPtr<T> &p) : _shared(&p), _counter(p._counter) 
    {
        _counter->incWeak();
    }

    ~WeakPtr()
    {
        decrementRef();
    }

    WeakPtr(const WeakPtr<T> &wp)
    {
        _counter = NULL;
        *this = wp;
    }

    const WeakPtr<T> &operator=(const WeakPtr<T> &weakPtr)
    {
        decrementRef();
        _counter = weakPtr._counter;
        _shared = weakPtr._shared;
        _counter->incWeak();
        return *this;
    }

    bool expired() const { return _counter->getUse() == 0; }

    T *operator->() const 
    {
        if (expired())
            throw "Pointer is not longer valid.";
        return _shared->_p;
    }

    const T &operator*() const
    {
        if (expired())
            throw "Pointer is not longer valid.";
        return *(_shared->_p);
    }
    int getWeak(){ return _counter->getWeak();}
private:

    void decrementRef(void)
    {
        if (_counter == NULL)
            return;

        _counter->decWeak();

        if (_counter->getWeak() == 0)
            delete _counter;
    }

    SharedPtr<T> *_shared;

    Counter *_counter;
};


