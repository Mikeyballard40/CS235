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

    friend std::ostream& operator<< (std::ostream& os, LinkedList<T>& linkedList)
	{
		for (Iterator iter = linkedList.begin(); iter != linkedList.end(); ++iter)
		{
			os << *iter << " ";
		}
		return os;
	}

	class Iterator
	{
	private:
		node* iNode;
	public:
		Iterator(node* head) : iNode(head) { }

		~Iterator(void) {}
    // 
		bool operator!=(const Iterator& rhs) const
		{
            if(iNode != rhs.iNode){
                return true;
            }else{
                return false;
            }
		}

		Iterator& operator++()
		{
            iNode = iNode->next;
			return *this;
		}

		T& operator*() const
		{
			return iNode->data;
		}

        
	};



	/** Insert Node(value) at beginning of linked list */
	virtual void push_front(const T& value){
        node* n = new node;            //********************************* changed from n = new node; to current
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

    /** Return iterator pointing to the first value in linked list */
	Iterator begin(void)
	{
		return LinkedList<T>::Iterator(h);
	}

	/** Return iterator pointing to something not in linked list */
	Iterator end(void)
	{
		return LinkedList<T>::Iterator(NULL);
	}

    /** Return iterator pointing found value in linked list */
    // Iterator find(const T& value) {
    //     node* curr = h;
    //     while (curr != nullptr)
    //     {
    //         if (curr->data == value)
    //             return Iterator(curr);
    //         curr = curr->next;
    //     }
    //     return end();
    // }
    


    /** Return iterator pointing to inserted value in linked list */
    Iterator insert(const T& position, const T& value) {
        node* curr = h;
        node* rep = new node;
        rep->data = value;
        node* use = nullptr;
        node* nul = NULL;
        while (curr != nullptr){
            if (curr->data == position){
                push_front(value); // Changed from push_front(value);  to current 
                return Iterator(rep);
                
            }
            else if (curr->next != nullptr && curr->next->data == position){
                use = curr;
                curr = curr->next;
                use->next = rep;
                rep->next = curr;
                return Iterator(rep);
            } 
            curr = curr->next;//use push front
        }
        return Iterator(nul);


    }


    /** Return iterator pointing to inserted value in linked list */
    Iterator insert_after(const T& position, const T& value) {//changed from Iterator position to const position
        node* curr = h;
        node* rep = new node;
        node* nul = NULL;
        rep->data = value;
        while (curr != nullptr)
        {
            if (curr->data == position){
                rep->next = curr->next;
                curr->next = rep;
             
                return Iterator(rep);
            
            }
            curr = curr->next;
            
        }
        return Iterator(nul);

    }

    /** Return iterator pointing found value in linked list */
    Iterator find(const T& value) {
        node* curr = h;
        node* nul = NULL;
        while (curr != nullptr)
        {
            if (curr->data == value){
                return curr;
                break;
            }
            curr = curr->next;
            
        }
        return nul;
    }
    


    /** Return iterator pointing to next item after deleted node linked list */
    Iterator erase(const T& value) {
        node* curr = h;
        node* nul = nullptr;
        node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->data == value) {
                if (curr == h) {
                    h = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return Iterator(prev != nullptr ? prev->next : h);
            }
            prev = curr;
            curr = curr->next;
        }
        return nul;
    }








    /** Replace all old_value(s) with new_value */
    void replace(const T& old_value, const T& new_value) {
        node* curr = h;
        while (curr != nullptr){
            if (curr->data == old_value)
            {
                curr->data = new_value;
            } 
            curr = curr->next; 
        }
    }

};

template<typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& list)
{
    typename LinkedList<T>::Iterator iter = list.begin();
    while (iter != list.end())
    {
        os << *iter << " ";
        ++iter;
    }
    return os;
}

#endif	// LINKED_LIST_INTERFACE_H