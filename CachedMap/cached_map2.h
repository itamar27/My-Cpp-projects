#pragma once
#include <map>
#include <memory>
#include <string>
#include <algorithm>



template <class K, class V>
class CachedMap
{
public:
	struct ObjectNotExistException {};
	struct DuplicateKeyExecption {};

	CachedMap() {};
	~CachedMap() {};

	void erase(const K& key)
	{   
		auto iterator = map_all.find(key);
		if (iterator == map_all.end())
			throw  ObjectNotExistException();
		else
			map_all.erase(key);

		auto iterator2 = map_cache.find(key);
		if (iterator2 != map_cache.end())
		      map_cache.erase(key);
	}
	void add(const K& key, const V& value)
	{
		auto iterator = map_all.find(key);
		if (iterator != map_all.end())       // the value in map_all
			throw DuplicateKeyExecption();
		else
		{	
			map_all[key] = std::shared_ptr<V>(new V(value));
		}
	}

	std::shared_ptr<V> get(const K& key)
	{
		auto iterator = map_cache.find(key);
		  if (iterator != map_cache.end())           // found in cache 
		  {
			  if (map_cache[key].expired())       // expired
				  map_cache.erase(key);

			  else return  map_cache[key].lock();  // not expired  
		  }
		        
		  else                                  // not found in cache
		  {
			  auto iterator2 = map_all.find(key);
			  if (iterator2 != map_all.end())
			  {
				  std::shared_ptr<V> value = map_all[key];
				  map_cache.insert(std::pair<K, std::weak_ptr<V>>(key, std::weak_ptr<V>(value)));
				  return map_all[key];
			  }
			  else return nullptr;
		
		  }
		  return nullptr;
	}
	
private:
	std::map<K, std::shared_ptr<V>> map_all;
	std::map<K, std::weak_ptr<V>> map_cache;
};

