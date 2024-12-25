#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include <linkedListIterator.h>
#include <linkedListType.h>

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

// Template class for an ordered linked list
// Inherits from the linkedListType class
template <class Type>
class orderedLinkedList : public linkedListType <Type>
{
    public:
        orderedLinkedList();                            // Constructor to initialize the list

        bool search(const Type& searchItem) const;      // Searches for an item in the list

        void insert(const Type& newItem);               // Inserts an item in the correct order

        void insertFirst(const Type& newItem);          // Inserts an item at the beginning

        void insertLast(const Type& newItem);           // Inserts an item at the end

        void deleteNode(const Type& deleteItem);        // Deletes a node with the specified value

        virtual ~orderedLinkedList();                   // Destructor to clean up memory

    protected:

    private:
};

// Constructor: Initializes an empty ordered linked list
template <class Type>
orderedLinkedList<Type>::orderedLinkedList()
{

}

// Searches for an item in the list
// Returns true if the item is found, otherwise false
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current;                // Pointer to traverse the list
    bool found = false;                     // Flag to track if the item is found

    current = this->first;

    // Traverse the list while the current node exists and the item is not found
    while (current != NULL && !found)
    {
        if(current->info == searchItem)     // Check if current node's info matches
        {
            found = true;
        }
        else
        {
            current = current->link;        // Move to the next node
        }
    }
    if (found)
    {
        found = (current->info == searchItem);  // Double-check for accuracy
    }
    return found;


}

// Inserts a new item into the list while maintaining order
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
   nodeType<Type> *current;             // Pointer to traverse the list
   nodeType<Type> *trailCurrent;        // Pointer to the node just before the current one
   nodeType<Type> *newNode;             // Pointer for the new node to be inserted

   bool found;

   newNode = new nodeType<Type>;        // Create a new node
   newNode->info = newItem;             // Set the node's value
   newNode->link = NULL;                // Initialize the link to null

   if (this->first == NULL)             // If the list is empty
    {
        this->first = newNode;          // Set first and last to new node
        this->last = newNode;
        this->count++;                  // Increment the node count
    }
    else
    {
        current = this->first;
        found = false;

        // Traverse the list to find the correct position for insertion
        while (current != NULL && !found)
        {
            if (current->info >= newItem)   // If current node's value is greater or equal
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;

            }
        }
        // Inserting at the start of the list
        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else
        {
            trailCurrent->link = newNode;       // Linking previous node to new node
            newNode->link = current;            // Linking new node to current
            if (current == NULL)                // If inserting at the end
            {
                this->last = newNode;           // Update the last pointer
            }

        this->count++;                          // Increment the node count
        }
    }
}

// Inserts an item at the beginning of the list (same as insert)
template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}

// Inserts an item at the end of the list (same as insert)
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}


// Deletes a node with a specific value
template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;      // Pointer to traverse the list
    nodeType<Type> *trailCurrent; // Pointer just before current
    bool found;

    if (this->first == NULL)    // If the list is empty
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        current = this->first;
        found = false;

        // Traverse the list to find the item to delete
        while (current != NULL && !found)
        {
            if (current->info >= deleteItem)    // If item is found
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }

        // If item is not found
        if (current == NULL)
        {
            cout << "The item to be deleted is not in the list." << endl;
        }
        else if (current->info == deleteItem)       // If the item to be deleted is found
        {
            if (this->first == current)             // If deleting the first node
            {
                this->first = this->first->link;
                if (this->first == NULL)            // If list becomes empty
                {
                    this->last = NULL;
                }
                delete current;
            }
            else
            {
                trailCurrent->link = current->link;     // Bypass the current node
                if (current == this->last)              // If deleting the last node
                {
                    this->last = trailCurrent;
                }
                delete current;
            }
            this->count--;                              // Decrement the node count
        }
        else
        {
            cout << "The item to be deleted is not in the list." << endl;
        }
    }
}

// Destructor: Clean up any remaining resources
template <class Type>
orderedLinkedList<Type>::~orderedLinkedList()
{

}

//template class orderedLinkedList<int>;
#endif // ORDEREDLINKEDLIST_H
