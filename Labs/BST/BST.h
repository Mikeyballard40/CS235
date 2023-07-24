#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "BSTInterface.h"
#include <string>

using namespace std;


/** A binary tree node with data, left and right child pointers */
template<typename T>
class BST : public BSTInterface<T>
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
    bool outLevel(Node* root, int level, stringstream& out) const
    {
       
    if (root == NULL){ 
        return false;
        }
    if (level == 1)
    {
        out << " " << root->data;
        if ((root->left != NULL) || (root->right != NULL)) return true;
        return false;
    }
    if ((level == 2) && !root->left && root->right){ 
        out << " _";
    }
    bool left = outLevel(root->left, level - 1, out);
    bool right = outLevel(root->right, level - 1, out);
    if ((level == 2) && root->left && !root->right) {
    out << " _";}
    return left || right;
    } // end outLevel()




public:

   BST() { this->root_ = NULL; 
            this->copyRoot_ = NULL;}
   ~BST() { clearTree(); 
   clearTreC();}


   Node* deepCopy() {
    copyRoot_ = copyTreeHelper(root_);
    return copyRoot_;
}


     Node* copyTreeHelper(Node* node)  {
        if (node == nullptr) {
            return nullptr;
        }
        
        Node* newNode = new Node(node->data);
        newNode->left = copyTreeHelper(node->left);
        newNode->right = copyTreeHelper(node->right);
        
        return newNode;
    }




 

   friend std::ostream& operator<< (std::ostream& os, BST<T>& BST)
	{
		for (Iterator iter = BST.begin(); iter != BST.end(); ++iter)
		{
			os << *iter << " ";
		}
		return os;
	}



    // DUAL FUNCTION
    /** Output nodes at a given level */
    string toString() const
    {
    stringstream out;
    if (root_ == NULL) out << " empty";
    else
    {
        int level = 0;
        do
        {
            out << endl << "  " << ++level << ":";
        } while (outLevel(root_, level, out));
    }
    return out.str();

    } // end toString()
    
    string toStringC() const
    {
        stringstream out;
        if (copyRoot_ == NULL)out << " Error";
        else
        {
            int level = 0;
            do
            {
                out << endl << "  " << ++level << ":";
            } while (outLevel(copyRoot_, level, out));
        }
    return out.str();
    }

    virtual bool checkCopyRoot(){
        if(copyRoot_ == nullptr){
            return false;
        }else{
            return true;
        }
    }
    


   class Iterator
    {
    private:
        Node* current_; 
        BST<Node*> stack_; 

    public:
        Iterator(Node* root) {
            current_ = root;
            while (current_ != nullptr) {
                stack_.push(current_);
                current_ = current_->left;
            }
        }

        bool operator!=(const Iterator& rhs) const {
            return current_ != rhs.current_;
        }

        Iterator operator++() {
            if (current_->right != nullptr) {
                current_ = current_->right;
                while (current_ != nullptr) {
                    stack_.push(current_);
                    current_ = current_->left;
                }
            } else {
                current_ = stack_.top();
                stack_.pop();
            }
            return *this;
        }

        T operator*() const {
            return current_->data;
        }
    };


    // add node to the tree
    virtual bool addNode(const T& item) {
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

//DUAL FUNCTION
//remove a specific node
virtual bool removeNode(const T& item) {
    return removeNodeHelper(root_, item);
}

bool removeNodeHelper(Node*& node, const T& item) {
    if (node == nullptr) {
        return false;
    }

    if (item < node->data) {
        return removeNodeHelper(node->left, item);
    }
    else if (item > node->data) {
        return removeNodeHelper(node->right, item);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* maxLeft = findMax(node->left);
            node->data = maxLeft->data;
            removeNodeHelper(node->left, maxLeft->data);
        }

        return true;
    }
}

Node* findMax(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}



    
 // DUAL FUNCTION
// Clear the BST of all nodes
virtual bool clearTree(){
    CLEAR(root_);
    root_ = nullptr;
    return true;
}
virtual bool clearTreC(){
    CLEAR(copyRoot_);
    copyRoot_ = nullptr;
    return true;
}

virtual bool CLEAR(Node* node){
    if (node == nullptr){
        return true;
    }

    CLEAR(node->right);
    CLEAR(node->left);

    delete node;
    return true;
}




    // DUAL FUNCTION
    // iterate through the tree counting each node --- CALLABLE FUNCTION
    virtual int size(){
        int sizeNode = 0;
        Node* track = root_; //DELETE MEMORY LEAK
        return SIZE(sizeNode, track);
        // delete track;
    }

    virtual int SIZE(int sizeNode, Node* track){ //at each recursive call i is added.
        if (track == nullptr){
            return sizeNode;
        }

        sizeNode++;

        sizeNode = SIZE(sizeNode, track->right);
        sizeNode = SIZE(sizeNode, track->left);

        return sizeNode;
    }


    // DUAL FUNCTION
    // find a value by recursion
    virtual bool find(const T& item){
        Node* track = root_;
        if(FIND(item, track)){
            return true;
        }else{
            return false;
        }; // MEMORY LEAK????
    }

    virtual bool FIND(const T& item, Node* track){
        if (track == nullptr) return false;
        if (track->data == item) return true;
        return FIND(item, track->right) || FIND(item, track->left);
    }





   Iterator begin() const {

   }
   Iterator end() const {

   }


}; 
#endif


// COMMAND	DESCRIPTION	OUTPUT
// INT	Instantiates a BST object for subsequent commands.	OK
// STRING	Instantiates a BST object for subsequent commands.	OK
// add <data>	Add data node to BST. Return Error if duplicate.	OK
// remove <data>	Remove node from BST.	OK
// clear	Delete all nodes from the BST.	OK
// size	Output the number of nodes in the BST.	Number of BST nodes
// print	Print BST (using insertion operator) in level-order. Return empty if BST contains no elements.	Level-order listing of BST empty
// find <data>	Find node in BST. Return "found" or "not found".	found not found
// copy	Make a deep copy of the current BST.	OK
// printcopy	Print the deep BST copy (created by the copy command) in level-order.	Level-order listing of BST empty