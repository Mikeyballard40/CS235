#ifndef VECTOR_H
#define VECTOR_H
#include "Deque.h"

using namespace std;

template <typename T>
class Vector {
private:
    Deque<T> vect;
public:

    Vector() : vect(Deque<T>()){}
    ~Vector() {}


    void push_back(const T& value){
        vect.push_back(value);
    }

    void pop_back(){
        if (vect.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
        vect.pop_back();
        }
    }

    virtual T& back(){
        if (vect.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return vect.back();
        }
    }

    virtual size_t size(){
            return vect.size();
    }

    T& at(size_t value){
        if (vect.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return vect.at(value);
        }
    }

    virtual string toString(){
            return vect.toString();
    }

    virtual bool empty() const {
        return vect.empty();
    }

};





#endif