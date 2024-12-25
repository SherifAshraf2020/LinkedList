#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include <linkedListType.h>

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

// Template class for an unordered linked list
template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
    public:
        unorderedLinkedList();                          // Constructor

        // Function to search for an item in the list
        bool search(const Type& searchItem) const;

        // Function to insert an item at the beginning of the list
        void insertFirst(const Type& newItem);

        // Function to insert an item at the end of the list
        void insertLast(const Type& newItem);


        // Function to delete a node containing a specific item
        void deleteNode(const Type& deleteItem);



        virtual ~unorderedLinkedList();                 // Destructor

    protected:

    private:
};



// Constructor
template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList()
{
    //ctor
    // No additional initialization required
}

// Function to search for an item in the list
template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current;                // Pointer to traverse the list
    bool found = false;                     // Flag to indicate if the item is found

    current = this->first;                        // Start from the first node
    while (current != NULL && !found)
    {
        if(current->info == searchItem)     // If the item matches
        {
            found = true;                   // Mark as found
        }
        else
        {
            current = current->link;        // Move to the next node
        }
    }
    return found;                           // Return whether the item was found
}


// Function to insert an item at the beginning of the list
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;            // Create a new node
    newNode = new nodeType<Type>;
    newNode->info = newItem;            // Set the data
    newNode->link = this->first;              // Point the new node to the current first node

    this->first = newNode;                    // Update the first pointer

    this->count++;                            // Increment the node count

    if (this->last == NULL)                   // If the list was empty
    {
        this->last = newNode;                 // Update the last pointer
    }

}


// Function to insert an item at the end of the list
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;            // Create a new node
    newNode = new nodeType<Type>;
    newNode->info = newItem;            // Set the data
    newNode->link = NULL;               // The new node will be the last, so its link is NULL

    if (this->first == NULL)                  // If the list is empty
    {
        this->first = newNode;                // Set both first and last to the new node
        this->last = newNode;
        this->count++;
    }
    else
    {
        this->last->link = newNode;           // Link the current last node to the new node
        this->last = newNode;                 // Update the last pointer

        this->count++;                        // Increment the node count
    }
}

// Function to delete a node containing a specific item
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;            // Pointer to traverse the list
    nodeType<Type> *trailCurrent;       // Pointer to keep track of the previous node

    bool found;                         // Flag to indicate if the item is found

    if (this->first == NULL)                  // If the list is empty
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        if (this->first->info == deleteItem)  // If the item is in the first node
        {
            current = this->first;
            this->first = this->first->link;        // Update the first pointer
            this->count--;                    // Decrement the node count

            if (this->first == NULL)          // If the list becomes empty
            {
                this->last = NULL;            // Update the last pointer
            }

            delete current;             // Delete the node
        }
        else
        {
            found = false;
            trailCurrent = this->first;       // Start from the first node
            current = this->first->link;


            while (current != NULL && !found)       // Traverse the list
            {
                if (current->info != deleteItem)    // If the item does not match
                {
                    trailCurrent = current;         // Move the trail pointer
                    current = current->link;        // Move the current pointer
                }
                else
                {
                    found = true;                   // Mark as found
                }
            }

            if (found)                                  // If the item is found
            {
                trailCurrent->link = current->link;     // Remove the node
                this->count--;                                // Decrement the node count

                if (this->last == current)                    // If the node to delete is the last node
                {
                    this->last = trailCurrent;                // Update the last pointer
                }

                delete current;                         // Delete the node
            }
            else
            {
                cout << "The item to be deleted is not in the list." << endl;
            }
        }
    }
}

// Destructor
template <class Type>
unorderedLinkedList<Type>::~unorderedLinkedList()
{
    //dtor
    // Destructor body
}


#endif // UNORDEREDLINKEDLIST_H
