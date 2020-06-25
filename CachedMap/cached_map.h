#pragma once

#include <algorithm>
#include <memory>
#include <map>
#include <string>

template <class K, class V>
class CachedMap
{
public:
    struct ObjectNotExistException {};
    struct DuplicateKeyExecption{};

public:
    CachedMap() = default;
    ~CachedMap(){};

    void erase(const K &k) //throw (std::string)//(ObjectNotExistException)
    {
        auto it = _map.find(k);
        if (it != _map.end())
            _map.erase(it);
        else
            throw ObjectNotExistException();
    }

    void add(const K &k, const V &value) //throw (std::string) //(DuplicateKeyExecption)
    {
        auto it = _map.find(k);
        if (it == _map.end())
        {
            _map[k] = std::shared_ptr<V>(new V(value));
        }
        else
            throw DuplicateKeyExecption();
    }

    std::shared_ptr<V> get(const K &k)
    {
        auto it = _cachemap.find(k);
        if (it != _cachemap.end())
        {
            if (_cachemap[k].expired())
                _cachemap.erase(it);
            else
                return _cachemap[k].lock();
        }
        else
        {
            auto it2 = _map.find(k);
            if (it2 != _map.end())
            {
                std::shared_ptr<V> value = _map[k];
                _cachemap.insert(std::pair<K, std::weak_ptr<V>>(k, std::weak_ptr<V>(value)));
                return value;
            }
        }
        return nullptr;
    }

private:
    std::map<K, std::shared_ptr<V>> _map;
    std::map<K, std::weak_ptr<V>> _cachemap;
};