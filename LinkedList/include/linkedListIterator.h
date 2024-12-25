#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

// Template structure for a node in a linked list
template <class Type>
struct nodeType
{
Type info;                  // Data field to store the value of the node
nodeType<Type> *link;       // Pointer to the next node in the linked list
};



// Template class for an iterator to traverse a linked list
template <class Type>
class linkedListIterator
{
    public:
        // Default constructor: Initializes the iterator with a null pointer
        linkedListIterator();
        // Constructor: Initializes the iterator with a given node pointer
        linkedListIterator(nodeType<Type> *ptr);

        // Dereference operator: Accesses the data in the current node
        Type operator*();


        // Pre-increment operator: Moves the iterator to the next node
        linkedListIterator<Type> operator++();


        // Equality operator: Checks if two iterators are at the same position
        bool operator==(const linkedListIterator<Type>& right) const;

        // Inequality operator: Checks if two iterators are at different positions
        bool operator!=(const linkedListIterator<Type>& right) const;


        // Destructor
        virtual ~linkedListIterator();

    protected:

    private:
        nodeType<Type> *current;        // Pointer to the current node in the linked list
};




template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;      // Initialize with null
    //ctor
}


template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;                          // Initialize with given node
}


template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;                   // Return the data of the current node
}


template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;                // Move to the next node
    return *this;                           // Return the updated iterator

}


template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);      // Compare node pointers
}


template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);      // Compare node pointers
}


template <class Type>
linkedListIterator<Type>::~linkedListIterator()
{
    //dtor
    // Destructor (no dynamic memory allocated here, so nothing to clean up)
}


#endif // LINKEDLISTITERATOR_H
