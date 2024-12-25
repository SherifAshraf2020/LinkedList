#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include "linkedListIterator.h"         // Include iterator class

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

// Template class for a generic linked list
template <class Type>
class linkedListType
{
    public:
        // Default constructor: Initializes an empty linked list
        linkedListType();
        // Copy constructor: Creates a deep copy of another linked list
        linkedListType(const linkedListType<Type>& otherList);

        // Assignment operator: Assigns the contents of one list to another
        const linkedListType<Type>& operator=(const linkedListType<Type>&);

        // Initializes the list to an empty state
        void initializeList();

        // Checks if the list is empty
        bool isEmptyList() const;

        // Prints the elements of the list
        void print() const;

        // Returns the number of elements in the list
        int length() const;

        // Destroys the list, releasing all allocated memory
        void destroyList();

        // Returns the first element in the list
        Type front() const;

        // Returns the last element in the list
        Type back() const;

        // Pure virtual function to search for an element in the list
        virtual bool search(const Type& searchItem) const = 0;

        // Pure virtual function to insert an element at the beginning of the list
        virtual void insertFirst(const Type& newItem) = 0;

        // Pure virtual function to insert an element at the end of the list
        virtual void insertLast(const Type& newItem) = 0;

        // Pure virtual function to delete a specific element from the list
        virtual void deleteNode(const Type& deleteItem) = 0;

        // Returns an iterator pointing to the first node of the list
        linkedListIterator<Type> begin();

        // Returns an iterator pointing past the last node of the list
        linkedListIterator<Type> end();



        // Destructor: Cleans up the list
        virtual ~linkedListType();

    protected:

        int count;                      // Number of elements in the list
        nodeType<Type> *first;          // Pointer to the first node in the list
        nodeType<Type> *last;           // Pointer to the last node in the list

    private:
        // Helper function to copy contents from another list
        void copyList(const linkedListType<Type>& otherList);
};



// Default constructor: Initializes an empty linked list
template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;        // Set the first node pointer to null
    last = nullptr;         // Set the last node pointer to null
    count = 0;              // Initialize the count of nodes to zero
    //ctor
}

// Copy constructor: Creates a deep copy of the given list
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = nullptr;        // Initialize the first pointer
    copyList(otherList);    // Copy all nodes from the other list
}

// Assignment operator: Assigns the contents of one list to another
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
    if (this != &otherList)     // Avoid self-assignment
    {
        copyList(otherList);    // Copy the other list's contents
    }
    return *this;               // Return the current object
}


// Checks if the linked list is empty
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
return (first == nullptr);      // Return true if no nodes in the list
}


// Deletes all nodes in the list and releases memory
template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;
    while (first != nullptr)    // Loop through the list
    {
        temp = first;           // Save the current node
        first = first->link;    // Move to the next node
        delete temp;            // Free memory of the current node
    }
    last = nullptr;             // Set the last node pointer to null
    count = 0;                  // Reset the count to zero
}

// Initializes the list to an empty state by destroying existing nodes
template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();              // Clear the list
}


// Prints the contents of the list
template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;            // Start from the first node
    current = first;
    while (current != nullptr)          // Traverse the list
    {
        cout << current->info << " ";   // Print the data in the node
        current = current->link;        // Move to the next node
    }

}

// Returns the number of elements in the list
template <class Type>
int linkedListType<Type>::length() const
{
    return count;                       // Return the count of nodes
}

// Returns the data of the first node
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);              // Ensure the list is not empty

    return first->info;                 // Return the data of the first node
}


// Returns the data of the last node
template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);               // Ensure the list is not empty

    return last->info;                  // Return the data of the last node
}


// Returns an iterator pointing to the first node
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);   // Create an iterator at the first node.
    return temp;                            // Return the iterator.
}


// Returns an iterator pointing past the last node
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);    // Create an iterator at the end.
    return temp;                            // Return the iterator
}


// Copies all nodes from another list to the current list
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode;        // Pointer to create a new node
    nodeType<Type> *current;        // Pointer to traverse the other list

    if (first != NULL)              // If the current list is not empty
    {
        destroyList();              // Clear it first
    }

    if (otherList.first == NULL)    // If the other list is empty
    {
        first = NULL;               // Set first and last pointers to null
        last = NULL;
        count = 0;                  // Set count to zero
    }

    else
    {
        current = otherList.first;  // Start with the first node of the other list

        count = otherList.count;    // Set the node count

        // Create the first node for the new list
        first = new nodeType<Type>;
        first->info = current->info;
        first->link = NULL;
        last = first;

        current = current->link;    // Move to the next node in the other list

        // Copy the rest of the nodes
        while (current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;

            last->link = newNode;       // Link the new node to the list
            last = newNode;             // Update the last pointer

            current = current->link;    // Move to the next node
        }
    }
}
// Destructor: Releases all resources used by the list
template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();                      // Clean up the list
    //dtor
}


#endif // LINKEDLISTTYPE_H
