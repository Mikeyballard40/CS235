#include <string>
#include <vector>

// C++ templates and vectors

using namespace std;

template <typename T1, typename T2>
class MyPair
{
private:
    T1 first;
    T2 second;
public:
    MyPair(T1 f, T2 s) : first(f), second(s) { }
    T1 getFirst() { return first; }
    T2 getSecond() { return second; }
};

MyPair<string, int> myDog("Dog", 36);
MyPair<double, double> myFloat(3.0, 2.18);


vector<string> my_vector;
my_vector.push_back("A"); // add "A" to the end of the vector
my_vector.insert(1, "B"); // insert "B" at index 1. all others move back
my_vector.erase(1); // erase element at index 1
my_vector[0] = "C" // replace element at index 0 with "C"


cout << my_vector[2]; //static. can run out without checking
cout << my_vector.at(2); //this checks to see if anyting is there!



int sum = 0;
vector<int> vec = { 1, 2, 3, 4, 5 };
using Iter = std::vector<int>::const_iterator;
for (Iter iter = vecbegin(); iter!=vec.end(); ++iter) // this is to go until the end. iter!=vec.end();
{
    sum += *iter;
}

//standard algorithms are used with vectors

#include <numeric>
vector<int> vect = { 1, 2, 3, 4, 5 };
int sum = std::accumulate(vect.begin(), vect.end(), 0);


//vector classes

template<typename T>
class Vector
{
private:
   // Data fields

   /** The initial capacity of the array */
   static const size_t INITIAL_CAPACITY = 10;

   /** The current capacity of the array */
   size_t current_capacity;

   /** The current num_items of the array */
   size_t num_items;

   /** The array to contain the data */
   T* the_data;

public:
   // Member Functions

      /** Construct an empty vector w/default capacity */
   Vector<T>() : current_capacity(INITIAL_CAPACITY),
                 the_data(new T[INITIAL_CAPACITY]),
                 num_items(0) {}


    //Error for out of range

    /** Subscripting operator */
   T& operator[](size_t index) { return the_data[index]; }

   /** at member function */
   T& at(size_t index)
   {
      if (index >= num_items)    // Verify valid index.
      {
         throw std::out_of_range("index to operator[] is out of range");
      }
      return the_data[index];
   }
};

//Reserve Function

void reserve(size_t new_capacity)
{
   if (new_capacity > current_capacity)
   {
      T* new_data = new T[new_capacity];
      for (size_t i = 0; i < num_items; i++)
           new_data[i] = the_data[i];
      delete[] the_data;
      the_data = new_data;
      current_capacity = new_capacity;
   }
}


//Pushback function

void push_back(const T& the_value)
{
   // Make sure there is space for the new item.
   if (num_items == current_capacity)
   {
      reserve(2 * current_capacity);   // Double the capacity
   }
   // Insert the new item.
   the_data[num_items] = the_value;
   num_items++;
}

//insert function

void insert(size_t index, const T& the_value)
{
    if (index > num_items)                      // Validate index.
    {
            throw std::out_of_range("Insert index is out of range");
    }
    if (num_items == current_capacity)          // Check for room
    {
        reserve(2 * current_capacity);           // Double the capacity
    }
   for (size_t i = num_items; i > index; i--)  // Open a slot
   {
      the_data[i] = the_data[i - 1];
   }
   the_data[index] = the_value;                // Insert new item
   num_items++;
}


//shallow vs deep copy

Vector<int> v2 = v1;


/** Make a (deep) copy of a vector.
    @param other The vector to be copied
*/
Vector<T>(const Vector<T>& other)
   : current_capacity(other.capacity),
     num_items(other.num_items),
     the_data(new T[other.current_capacity])
{
   for (size_t i = 0; i < num_items; i++)
   {
      the_data[i] = other.the_data[i];
   }
}


//Linked Lists

*** Connecting Nodes ***
//option 1:
Node* tom = new Node("Tom");
Node* sam = new Node("sam");
Node* harry = new Node("harry");
Node* jim = new Node("Jim");
head = tom;
tom->next = sam;
sam->next = harry;
harry->next = Jim;

//option 2:
Node* tom = new Node("Tom");
head->next = new Node("sam");
head->next->next =new Node("harry");
head->next->next->next =new Node("Jim");

//output linked lists:
Node# node_ptr = head;
while (node_pts != NULL)
{
    cout << node_ptr->data;
    if (node_ptr->next != NULL)
    {
        cout << " ==> ";
    }
    node_ptr = node_ptr->next;
}
cout << endl;

//finding heads in the linked list
Node* node_ptr = head;
while (node_ptr->data != "Harry") //find "Harry"
    node_ptr = node_ptr->next;

//insert "Bob" after "Harry"
Node* bob = new Node("Bob");
bob->next = node_ptr->next;
node_ptr->next = bob;
