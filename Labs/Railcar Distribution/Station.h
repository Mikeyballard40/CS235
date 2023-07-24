#ifndef STATION_H
#define STATION_H
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"
#include "Deque.h"
#include "Car.h"

template <typename T>
class Station
{
private:
	Vector<T> train_;
    Deque<T> deq_;
	Stack<T> stack_;
	Queue<T> queue_;
	T turnTableCar_;
    bool TTOccupied;
public:

	Station() : 
    turnTableCar_(T()),
    deq_(Deque<Car>()),
    queue_(Queue<Car>()),
    stack_(Stack<Car>()),
    TTOccupied(false) {}

	~Station() {
        
    }

    // Train car enters the station turntable.
	string addCar(const T& car) { 
        if (TTOccupied == true){
            return "Turntable occupied!";
        }
        turnTableCar_ = car;
        TTOccupied = true;
        return "OK";
        }

    //Train car is removed from the turntable and pushed to the Stack roundhouse.	
	string addStack() { 
        if (TTOccupied == false) {
        return "Turntable empty!";
    }
    T car = turnTableCar_;
    turnTableCar_ = T();
    TTOccupied = false;
    stack_.push(car); 
    return "OK";
    }

    //Train car is removed from the turntable and pushed to the Queue roundhouse.
	string addQueue() {
        if (TTOccupied == false) {
        return "Turntable empty!";
    }
    T car = turnTableCar_;

    turnTableCar_ = T(); 
    TTOccupied = false;
    queue_.push(car); 
    return "OK";
    }

    //A train car is removed from the turntable and pushed into the train vector.
    string removeCar() { 
        if (TTOccupied == false) {
        return "Turntable empty!";
    }
    T car = turnTableCar_;
    turnTableCar_ = T(); 
    TTOccupied = false;
    train_.push_back(car); 
    return "OK";
    }

    //A train car is removed from Stack roundhouse and moved to the station turntable.	
	string removeStack() {
        if (TTOccupied == true) {
        return "Turntable occupied!";
    }
    else if (stack_.empty()){
        return "Stack empty!";
    }
    turnTableCar_ = stack_.last();
    TTOccupied = true;
    stack_.pop();
    return "OK";
    }

    //A train car is removed from Queue roundhouse and moved to the station turntable.
    string removeQueue() { 
        if (TTOccupied == true) {
        return "Turntable occupied!";
    }
    else if (queue_.empty()){
        return "Queue empty!";
    }
    turnTableCar_ = queue_.top();
    TTOccupied = true;
    queue_.pop();
    // cout << "Display the trains in Queue roundhouse. : " << queueToString() << endl;
    return "OK";
    }

    //Display the current train car on station turntable,
    const string& topCar() { 
        if (TTOccupied == false){
            static const string emptyMessage = "Turntable empty!";
            return emptyMessage;
        }
        return turnTableCar_.toString();
     }
    
    //Display the train car at head of Stack roundhouse.	
	string topStack() { 
        if (stack_.empty()){
            return "Stack empty!";
        }
        return stack_.last().toString();
    }

    //Display the train car at head of Queue roundhouse.
    string topQueue() { 
        if (queue_.empty()){
            return "Queue empty!";
        }
        return queue_.top().toString();
     }

    //Output number of train cars in Queue/Stack roundhouses and train vector.		
    string sizeStack() { return std::to_string(stack_.size()); }
    string sizeTrain() { return std::to_string(train_.size()); }
	string sizeQueue() { return std::to_string(queue_.size()); }

    //Find <data>	Find and display the current location and position of a car in the station data structures (turntable, queue, stack, or vector).
	string find(const T& car) { 
        if (turnTableCar_ == car){
            return "Turntable";
        }

        for (int i = 0; i < queue_.size(); i++){
            if (queue_.at(i) == car){
                return "Queue[" + std::to_string(i) + "]";
            }
        }

        for (int i = 0; i < stack_.size(); i++){
            if (stack_.at(i) == car){
                return "Stack[" + std::to_string(i) + "]";
            }
        }

        for (int i = 0; i < train_.size(); i++){
            if (train_.at(i) == car){
                return "Train[" + std::to_string(i) + "]";
            }
        }

        return "Not Found!";
     }

	// toString functions
    string queueToString()  { 
        return queue_.toString();
    }
	string vectorToString()  { 
        return train_.toString();
    }
	string stackToString()  { 
        return stack_.toString();
    }
    string toString(){
        return deq_.toString();
    };

    string XXX(){
        if (TTOccupied == true){
            return turnTableCar_.toString();
        }else{
            return "FALSE";
        }
    }

    
};
#endif