#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "SetInterface.h"
#include <string>

using namespace std;

template<typename T>
class Set : public SetInterface<T>
{
    private:

    // construct the node
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& item, Node* l = nullptr, Node* r = nullptr)
            : data(item), left(l), right(r) {}
   };

   Node* root_;
   Node* copyRoot_;


    //Assistant function to toString()
    
    void outLevel(Node* node, stringstream& out, bool& isFirst) const
    {
        if (node == nullptr) {
            return;
        }
        outLevel(node->left, out, isFirst);

        if (!isFirst)
            out << ",";
        else
            isFirst = false;

        out << node->data;

        outLevel(node->right, out, isFirst);

    } 


public:

	Set() {this->root_ = NULL; 
                    this->copyRoot_ = NULL;}

	~Set() { clear(); 
                      clearTreeC();}



   friend std::ostream& operator<< (std::ostream& os, Set& set)
	{
		os << set.toString();
		return os;
	}

    Set(const Set& other) {
        root_ = copyTreeHelper(other.root_);
    }
    //Deep Copy Constructor
    Set& operator=(const Set& other) {
    if (this != &other) {
        clear();
        root_ = copyTreeHelper(other.root_);
    }
    return *this;
    }

    Node* deepCopy() {
        copyRoot_ = copyTreeHelper(root_);
        return copyRoot_;
    }
    //assignment opperator
     Node* copyTreeHelper(Node* node)  {
        if (node == nullptr) {
            return nullptr;
        }
        
        Node* newNode = new Node(node->data);
        newNode->left = copyTreeHelper(node->left);
        newNode->right = copyTreeHelper(node->right);
        
        return newNode;
    }



	/** Inserts item into the set, if the container doesn't
		already contain an element with an equivalent value. */
	virtual bool insert(const T& item) {
        Node* newNode = new Node(item);

        if (root_ == nullptr) {
            root_ = newNode;
            return true;
        }

        Node* curr = root_;
        Node* parent = nullptr;

        while (curr != nullptr) {
            parent = curr; // Update the parent node before moving to the next level

            if (item < curr->data)
                curr = curr->left;
            else if (item > curr->data)
                curr = curr->right;
            else {
                delete newNode;
                return false; // Duplicate values not allowed
            }
        }

        // Update the parent node's child pointer
        if (item < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        return true;
        }



	/** Removes all items from the set. */
	 // DUAL FUNCTION
    virtual void clear() override {
        CLEAR(root_);
        root_ = nullptr;
    }
    virtual void clearTreeC(){
        CLEAR(copyRoot_);
        copyRoot_ = nullptr;
    }

    virtual void CLEAR(Node* node) {
        if (node == nullptr) {
            return;
        }

        CLEAR(node->left);
        CLEAR(node->right);

        delete node;
    }


	/** @return: the number of elements contained by the Set. */
	// DUAL FUNCTION
   virtual size_t size() const {
        return sizeNode(root_);
    }

    size_t sizeNode(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + sizeNode(node->left) + sizeNode(node->right);
    }


	/** @return: return 1 if contains element equivalent to item, else 0. */
	virtual size_t count(const T& item){
        Node* track = root_;
        if(FIND(item, track)){
            return 1;
        }else{
            return 0;
        }; // MEMORY LEAK????
    }

    virtual bool FIND(const T& item, Node* track){
        if (track == nullptr) return false;
        if (track->data == item) return true;
        return FIND(item, track->right) || FIND(item, track->left);
    }


	/** @return: string representation of items in Set. */
	// DUAL FUNCTION
    /** Output nodes at a given level */
    virtual string toString() const
    {
        stringstream out;
        if (root_ == nullptr) {
            out << "empty";
        } else {
            // out << endl << "[";
            bool isFirst = true;
            outLevel(root_, out, isFirst);
            // out << "]";
        }
        return out.str();
    }    
    
    string toStringC() const
    {


        stringstream out;
        if (copyRoot_ == nullptr) {
            out << "empty";
        } else {
            out << endl << "[";
            bool isFirst = true;
            outLevel(copyRoot_, out, isFirst);
            out << "]";
        }
        return out.str();

    return out.str();
    }
    
};
#endif // SET_H