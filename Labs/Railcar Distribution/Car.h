#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

struct Car //The Car class has constructors and contains an unsigned int.
{
    unsigned int id;
    Car() : id(0) {}
    Car(unsigned value){
        id = value;
    }
    ~Car() {}

    bool operator==(const Car car) { return this->id == car.id;}
    bool operator!=(const Car car) { return this->id == car.id;}

    //return the car as a string
    string toString() const
    {
        stringstream ret;
        ret << id;
        return ret.str();
    }

    //make friend for car
    friend std::ostream& operator<< (ostream& os, const Car& item)
    {

        os << item.toString();
        return os;
    }

};
#endif