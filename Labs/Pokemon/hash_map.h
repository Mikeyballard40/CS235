#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <iostream>
#include <typeinfo>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "hash_map_interface.h"
#include "Pair.h"
#include "Set.h"

#define DEFAULT_MAP_HASH_TABLE_SIZE	31
#define HASH_CONSTANT				3
#define LOAD_THRESHOLD				75

using namespace std;

template <typename K, typename V>
class HashMap : public HashMapInterface<K, V>
{
private:
    size_t hashTableSize;
    size_t numElements;
    Pair<K, V>* hashMap;
    Set<string> setter;
    

        

    void rehash() //rehash the hash table to fit twice as much data. 
    {
        size_t newHashTableSize = hashTableSize * 2;

        Pair<K, V>* newHashMap;

        hashTableSize = newHashTableSize;
        newHashMap = new Pair<K, V> [newHashTableSize];

        for (size_t j = 0; j < hashTableSize/2; j++) //itterate through the existing hashMap.
        {

            size_t newIndex = getHashValue(hashMap[j].first); //get new hashvalue for each key value pair. 
            cout << newIndex << " :newIndex and j: " << j << endl;
            if (hashMap[j].first.length() == 0) continue;
            int k = 1;

            while (1)
            {
                if (newHashMap[newIndex].first.length() != 0)
                {
                    if (newHashMap[newIndex].first == hashMap[j].first){ //if repeat? Should be no repeats in rehash.
                        break;
                    }
                    newIndex = (newIndex + k) % newHashTableSize;
                    k = k + 2;
                }
                else
                {
                    
                    newHashMap[newIndex].first = hashMap[j].first;
                    newHashMap[newIndex].second = hashMap[j].second;
                    break;
                }
            }


        }

        swap(hashMap, newHashMap);//reset hashTableSize to new size. 
        delete[] newHashMap;
    }

public:
	HashMap() 
        {
            hashTableSize = DEFAULT_MAP_HASH_TABLE_SIZE;
            numElements = 0;
            hashMap = new Pair<K, V> [hashTableSize];
        }

	virtual ~HashMap() {
        delete[] hashMap;
    }

    V& operator[](const K& key) //operator function
	{
        double loadFactor = (numElements * 100.0) / hashTableSize;
        if (loadFactor > LOAD_THRESHOLD)
        {
            rehash();
        }

        size_t hashValue = getHashValue(key);
		size_t index = hashValue;
		size_t k = 1;

		while (1)
		{
			if (hashMap[index].first.length() != 0)
			{
				if (hashMap[index].first == key) {
                    return hashMap[index].second;
                };
				index = (index + k) % hashTableSize;
				k = k + 2;
			}
			else
			{
                
				hashMap[index].first = key;
				break;
			}
		}
        numElements++;
		return hashMap[index].second;
	}


size_t power(size_t base, int exponent) const
    {
        size_t result = 1;
        for (int i = 0; i < exponent; ++i)
        {
            result *= base;
        }
        return result;
    }

    size_t getHashValue(const K& key) const //create a hash value
    {
        unsigned int hashValue = 0;
        int n = key.size();
        for (int i = 0; i < n; ++i)
        {
            hashValue += key[i] * power(HASH_CONSTANT, n - i - 1);
        }
        return hashValue % hashTableSize;
    }



	/** @return: the number of elements that match the key in the Map. */
	virtual size_t count(const K& key)
    {
        return hashTableSize;
    };

	/** Removes all items from the Map. */
	virtual void clear(void)
    {
        delete[] hashMap;
        hashTableSize = DEFAULT_MAP_HASH_TABLE_SIZE;
        numElements = 0;
        hashMap = new Pair<K, V>[hashTableSize];
    };

	/** @return: number of Key-Value pairs stored in the Map. */
	virtual size_t size(void) const
    {
        return numElements;
    };

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	virtual size_t max_size(void) const
    {
        return hashTableSize;
    };



	/** @return: string representation of Key-Value pairs in Map. */
	virtual string toString() const override {
        stringstream ss;
        for (size_t i = 0; i < hashTableSize; i++) {
   
            if (hashMap[i].first.length() > 0){ // if pokemon or move called.
                ss << "  [" << i << ":" << hashMap[i].first << "->" << hashMap[i].second << "]" << endl;
            }
        }
        return ss.str();
    

    }
};
#endif // HASH_MAP_H