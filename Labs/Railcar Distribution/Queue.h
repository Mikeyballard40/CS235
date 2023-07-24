#ifndef QUEUE_H
#define QUEUE_H
#include "Deque.h"
#include <string>

using namespace std;

template <typename T>
class Queue 
{
private:
    Deque<T> queue;

public:

    Queue(): queue(Deque<T>())
    {}

    ~Queue()
    {}

    void push(const T& value){
            // cout << "Queue.push: " << value << endl;
        queue.push_back(value);
    }

    void pop(){
        if (queue.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
        queue.pop_front();
        }
    }

    virtual T& top(){
        if (queue.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return queue.front();
        }
    }

    virtual size_t size(){
            return queue.size();
    }

    T& at(size_t value){
        if (queue.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return queue.at(value);
        }
    }

    virtual string toString(){
            return queue.toString();
    }

    virtual bool empty() const {
        return queue.empty();
    }
};





#endif