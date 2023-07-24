#ifndef STACK_H
#define STACK_H
#include "Deque.h"

using namespace std;

template <typename T>
class Stack{
private:
    Deque<T> stack;
public:

    Stack():stack(Deque<T>()){}

    ~Stack()
    {}

void push(const T& value){
        stack.push_back(value);
    }

    void pop(){
        if (stack.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
        stack.pop_back();
        }
    }

    virtual T& top(){
        if (stack.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return stack.front();
        }
    }
    virtual T& last(){
        if (stack.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return stack.back();
        }
    }

    virtual size_t size(){
            return stack.size();
    }

    T& at(size_t value){
        if (stack.empty()){
            throw std::runtime_error("Error: Data structure is empty.");
        }else{
            return stack.at(value);
        }
    }

    virtual string toString(){
        return stack.toString();
    }

    virtual bool empty() const {
        return stack.empty();
    }

};





#endif