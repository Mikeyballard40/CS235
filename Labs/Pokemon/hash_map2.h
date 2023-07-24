#ifndef HASH_MAP2_H
#define HASH_MAP2_H

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
class HashMap2 
{
private:
    size_t hashTableSize;
    size_t numElements;
    pair<K, Set<string> >* hashMap2;
    

    size_t getHashValue(const K& key) const//create hash value for the key.
    {
        size_t hashValue = 0;
        int n = key.size();
        for (int i = 0; i < n; ++i)
        {
            // cout << "Pow: ";
            // cout << n - i - 1<< endl;
            // cout << "key[i]: ";
            // cout << key[i] << endl;

            hashValue += key[i] * static_cast<size_t>(pow(HASH_CONSTANT, n - i - 1));
            // cout << key[i] << ":  " << n - i - 1 << "  " << hashValue << ",   ";
        }

        // cout << endl << "KEY: " << key << endl;
        // cout << "hashValue; " << hashValue << endl;
        // cout << "HASH_CONSTANT: " << HASH_CONSTANT << endl;
        // cout << "hashTableSize: " << hashTableSize << endl;
        // cout << hashValue % hashTableSize << endl;
        // cout << endl;
     
        return hashValue % hashTableSize;
    }

    void rehash() //rehash the hash table to fit twice as much data. 
    {
        size_t newHashTableSize = hashTableSize * 2;

        pair<K, V>* newHashMap;
        newHashMap = new pair<K, Set<string> > [newHashTableSize];

        for (size_t j = 0; j <= hashTableSize; j++) //itterate through the existing hashMap.
        {

            size_t newIndex = getHashValue(hashMap2[j].first); //get new hashvalue for each key value pair. 
            int probe;
            int count = 0; 

            for (size_t i = 0; i < hashTableSize; i++) {
                
                if (count == 0){
                    probe = 1;
                }
                else{
                    probe = probe + 2;
                }
                if (hashMap2[i].first.length() > 0){
                    newIndex = (newIndex + probe) % newHashTableSize; //preform quadratic probing.
                    count++;
                }   
            }

            newHashMap[newIndex].first = hashMap2[j].first;
            newHashMap[newIndex].second = hashMap2[j].second;
        }

        swap(hashMap2, newHashMap);//reset hashTableSize to new size. 
        hashTableSize = newHashTableSize;
        delete[] newHashMap;
    }

public:
	HashMap2()
        {
            hashTableSize = DEFAULT_MAP_HASH_TABLE_SIZE;
            numElements = 0;
            hashMap2 = new pair<K, Set<string> > [hashTableSize];
        }

	virtual ~HashMap2() {}

	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	virtual V& operator[](const K& key){
        double loadFactor = (numElements * 100.0) / hashTableSize;
        if (loadFactor > LOAD_THRESHOLD)
        {
            rehash();
        }

        size_t hashValue = getHashValue(key);
        int probe = 1;
        size_t index = hashValue;
        // cout << "INDEX: " << index << "   hashMap[index]:" << hashMap2[index].first << "   KEY: " << key << endl;******************************
        if (hashMap2[index].first == key) // ***check if the key is already in the hash map. if so it returns the reference to the corresponding value. 
            {
                return hashMap2[index].second;
            }
        else if (hashMap2[index].first != key && hashMap2[index].first.length() > 0){
            while(hashMap2[index].first.length() != 0){
                if (hashMap2[index].first == key) // ***check if the key is already in the hash map. if so it returns the reference to the corresponding value. 
            {
             
                    // cout << "YES in WHILE LOOP    " << endl; //******************************
                    return hashMap2[index].second;
                
            }
              
                index = (index + probe) % hashTableSize; //preform quadratic probing.
                cout << ", INTERMITANT INDEX: " << index; //******************************
                probe += 1;
                probe++;
            }
            cout << endl << "final index: " << index << endl; //******************************
        }

        // for (size_t i = 0; i < hashTableSize; i++) {
        //     if (hashMap[i].first.length() > 0){ 
        //         index = (index + probe) % hashTableSize; //preform quadratic probing.
        //         probe += 2;
        //         probe++;
        //     }   
        // }


        // while (hashMap.find(index) != hashMap.end()) //check for collision and probe for available index
        // {
        //     if (hashMap[index].first == key) // ***check if the key is already in the hash map. if so it returns the reference to the corresponding value. 
        //     {
        //         return hashMap[index].second;
        //     }

        //     index = (index + probe * probe) % hashTableSize; //the quadratic probing.
        //     probe++;

        // }

        hashMap2[index] = make_pair(key, V());  //make_pair function??? This may be the issue. ******
        numElements++;
        cout<< endl << "END" << endl << endl;
        return hashMap2[index].second;
    };

	/** @return: the number of elements that match the key in the Map. */
	virtual size_t count(const K& key)
    {
        
    };

	/** Removes all items from the Map. */
	virtual void clear(void)
    {
        
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
	virtual string toStringOG() const {
        stringstream ss;
        for (size_t i = 0; i <= hashTableSize; i++) {
           
            if (hashMap2[i].first.length() > 0){ // if pokemon or move called.
                ss << "  [" << i << ":" << hashMap2[i].first << "->" << hashMap2[i].second.toString() << "]" << std::endl;
            }
        }
        cout << "HELLO"; //******************************
        return ss.str();
        // std::ostringstream ss;
        // for (const auto& pair : hashMap) {
        //     ss << "[" << std::to_string(getHashValue(pair.first)) << ":" << pair.second.first << "->" << pair.second.second << "]" << std::endl;
        // }
        // return ss.str();

    }
};
#endif // HASH_MAP_INTERFACE_H