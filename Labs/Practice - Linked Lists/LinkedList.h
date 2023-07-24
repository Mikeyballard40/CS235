#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedListInterface.h"
#include <string>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct node
    {
        T data; //T can store any data type
        node* next;
        // node(const T d, node node1){
        //     data = d;
        //     next = node1;
        // }
    };

    node* t;
    node* n; //
    node* h; //head
    node* hC; // head of Copy
    // node* l; // tail or LAST
    int Size;
public:
	LinkedList(void) { // constructor
        h = NULL;
        Size = 0;
    }

	virtual ~LinkedList(void) { // ~ makes the function destructor
    clear();
    }


	/** Insert Node(value) at beginning of linked list */
	virtual void push_front(const T& value){
        n = new node;
        n->data = value;
        n->next = h;
        h = n;
        
    }

	/** Remove Node at beginning of linked list */
	virtual void pop_front(void){
        if(h!=nullptr){
        node* temp = h;
        h = h->next; 
        delete temp;
        }
    }

	/** Return reference to value of Node at beginning of linked list */
	virtual T& front(void){
        if(h==nullptr){
            throw std::runtime_error("List is empty");
        } else{
            return h->data;
        }
    }
    // virtual front(void){
    //     return h->data;
    // }

	/** Return true if linked list size == 0 */
	virtual bool empty(void) const{
        return(h==nullptr);
    }

	/** Remove all Nodes with value from linked list */
	virtual void remove(const T& value){
        node* curr = h;
        node* prev = nullptr;
        while (curr != nullptr){
            if (curr->data == value){
                if (prev == nullptr){
                    h = curr->next;
                } else {
                    prev->next = curr->next;
                }
                node* temporary = curr;
                curr = curr->next;
                delete temporary;
            } else{
                prev = curr;
                curr = curr->next;
            }
        }
    }

	/** Remove all Nodes from linked list */
	virtual void clear(void){
        while (h != nullptr){
            node* temp = h;
            h = h->next;
            delete temp;
        }
    }

	/** Reverse Nodes in linked list */
	virtual void reverse(void){
        node* curr = h;
        node* mover = nullptr;
        node* prev = nullptr;
        while (curr != nullptr){
            mover = curr->next;
            curr->next = prev;
            prev = curr;
            curr = mover;
        }
        h = prev;
    }

	/** Return the number of nodes in the linked list */
	virtual size_t size(void) const{
        node* curr = h;
        int count = 0;
        while( curr != nullptr){
            count++;
            curr = curr->next;
        }
        // l = curr;
        return count;
    }

	/** Return contents of Linked List as a string */
	virtual std::string toString(void) const{
        std::string i;
        node* curr = h;
        while( curr != nullptr){
            i += curr->data + " ";
            curr = curr->next;
        }
        if(h==nullptr){
            return "Empty!";
        } else{
            return i;
        }
    }

    /** Create a deep copy of the nested list **/
    virtual void Copy(void) {
    hC = nullptr; 
    node* currC = h;  // Start from the head of the original list
    while (currC != nullptr) {
        node* newNode = new node;
        newNode->data = currC->data;
        newNode->next = nullptr;

        // If the new list is empty, set the new node as the head
        if (hC == nullptr) {
            hC = newNode;
        } else {
            // append the new node to the end of the new list
            node* tempC = hC;
            while (tempC->next != nullptr) {
                tempC = tempC->next;
            }
            tempC->next = newNode;
        }
        currC = currC->next;  // Move to the next node in the original list
    }
}

	/** Return contents of the coppied Linked List as a string */
    virtual string toStringC(void) const {
    string i;
    node* curr = hC; 
    while (curr != nullptr) {
        i += curr->data + " "; 
        curr = curr->next; 
    }
    return i;
}


	/** BONUS ** Insert Node(value) at end of linked list */
	// virtual void push_back(const T& value) = 0;
	/** BONUS ** Remove Node at end of linked list */
	//virtual void pop_back(void) = 0;

	/** BONUS ** Return reference to value of Node at end of linked list */
	// virtual T& back(void){
    //     return l;
    // };
};
#endif	// LINKED_LIST_INTERFACE_H