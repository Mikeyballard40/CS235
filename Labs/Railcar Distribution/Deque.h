#ifndef DEQUE_H
#define DEQUE_H
#include "DequeInterface.h"
#include <string>

using namespace std;

#define DEFAULT_CAPACITY 4


template<typename T>
class Deque: public DequeInterface<T>
{
private:

        T *the_data;
        int capacity;
        int num_items;
        int front_index;
        int rear_index;

public:

    Deque(void) :
        capacity(DEFAULT_CAPACITY),
        num_items(0),
        front_index(0),
        rear_index(0), // changed from DEFAULT_CAPACITY - 1 to the current;
        the_data(new T[DEFAULT_CAPACITY]) {}
    
    ~Deque(){
        delete[] the_data;
    }

    void reallocate(){
        capacity = capacity * 2; //create new array and alocate info from previous array to new array
        T *temp_array = new T[capacity];
        cout << capacity << endl;
        for (int i = 0 ; i < (capacity / 2); i++){
            cout << i << endl;
            temp_array[i] = the_data[(front_index + i) % (capacity/2)];
        }
        cout << "hi" << endl;
        front_index = 0;
        cout << "1" << endl;
        rear_index = num_items - 1;
        cout << "2" << endl;
        delete[] the_data;
        cout << "3" << endl;
        the_data = temp_array;
        cout << "4" << endl;
    }

    //outputting Car objects
    virtual string toString() {
        stringstream out;
        for (int i = 0; i < num_items; ++i){
            out << the_data[(front_index + i) % capacity] << " ";
            // out << the_data[i] << " ";
        }
        return out.str();
    }

	/** Insert item at front of deque */
	virtual void push_front(const T& value){
    if (num_items == capacity)
   {
      reallocate();
   }
   if (num_items==0){
    rear_index = 0;
    front_index = 0;
    the_data[front_index] = value;
   }else{
   front_index = (front_index - 1 + capacity) % capacity;
   the_data[front_index] = value; 
    }
    num_items++;
    }

	/** Insert item at rear of deque */
	virtual void push_back(const T& value) {
    if (num_items == capacity){
      reallocate();
    }
    if (num_items == 0){
        rear_index = 0;
        front_index = 0;
        the_data[rear_index] = value;
        
    }
    else{
    rear_index = (rear_index + 1) % capacity;
    the_data[rear_index] = value;
    }
    num_items++;
    }

	/** Remove the front item of the deque */
	virtual void pop_front(void) {
        the_data[front_index] = 0;
        front_index = (front_index + 1) % capacity;
        num_items--;
    }

	/** Remove the rear item of the deque */
	virtual void pop_back(void) {
        the_data[rear_index] = 0;
        rear_index = (rear_index - 1) % capacity;
        num_items--;
        }

	/** Return the front item of the deque (Do not remove) */
	virtual T& front(void) {
        return the_data[front_index];
    }

	/** Return the rear item of the deque (Do not remove) */
	virtual T& back(void) {
        return the_data[rear_index];
    }

	/** Return the number of items in the deque */
	virtual size_t size(void) const {
        return num_items;
    }

	/** Return true if deque is empty */
	virtual bool empty(void) const {
        if (num_items == 0){
            return true;
        } else{
            return false;
        }
    }

	/** Return item in deque at index (0 based) */
	virtual T& at(size_t index) {
        return the_data[index];
    }


    
};




#endif