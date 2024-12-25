#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <cassert>

using namespace std;

// Definition of a node in the doubly linked list
template <class Type>
struct nodeType
{
    Type info;                  // The data stored in the node
    nodeType<Type> *next;       // Pointer to the next node in the list
    nodeType<Type> *back;       // Pointer to the previous node in the list
};

// Definition of the doubly linked list class
template <class Type>
class doublyLinkedList
{
    public:
        doublyLinkedList();                                                         // Default constructor: Initializes an empty list

        doublyLinkedList(const doublyLinkedList<Type>& otherList);                  // Copy constructor: Creates a new list as a copy of another list

        const doublyLinkedList<Type>& operator=(const doublyLinkedList<Type> &);    // Overloaded assignment operator

        void intializeList();                                                       // Resets the list to an empty state

        bool isEmptyList() const;                                                   // Checks if the list is empty

        void destroy();                                                             // Deletes all nodes in the list and frees memory

        void print() const;                                                         // Prints the list from first node to last node

        void reversePrint() const;                                                  // Prints the list from last node to first node

        int length() const;                                                         // Returns the number of nodes in the list

        Type front() const;                                                         // Retrieves the data of the first node

        Type back() const;                                                          // Retrieves the data of the last node

        bool search(const Type& searchItem) const;                                  // Searches for a value in the list

        void insert(const Type& insertItem);                                        // Inserts a new node in sorted order

        void deleteNode(const Type& deleteItem);                                    // Deletes a node with a specific value from the list





        virtual ~doublyLinkedList();                                                // Destructor: Frees memory by destroying the list

    protected:
        int count;                                                                  // Number of nodes in the list
        nodeType<Type> *first;                                                      // Pointer to the first node in the list
        nodeType<Type> *last;                                                       // Pointer to the last node in the list

    private:
        void copyList(const doublyLinkedList<Type>& otherList);                     // Helper method to copy the content of another list
};






// ------------------ Method Implementations ------------------

// Default constructor: Initializes an empty list
template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
    first = nullptr; // Set the first pointer to nullptr
    last = nullptr;  // Set the last pointer to nullptr
    count = 0;       // Initialize count as 0 (no nodes in the list)
}

// Copy constructor: Creates a copy of an existing list
template <class Type>
doublyLinkedList<Type>::doublyLinkedList(const doublyLinkedList<Type>& otherList)
{
    first = nullptr;        // Initialize the list as empty
    copyList(otherList);    // Call the helper method to copy the other list
}


// Assignment operator: Copies one list into another
template <class Type>
const doublyLinkedList<Type>& doublyLinkedList<Type>::operator=(const doublyLinkedList<Type>& otherList)
{
    if (this != &otherList)     // Avoid self-assignment
    {
        copyList(otherList);    // Copy the other list's content
    }
    return *this;
}


// Checks if the list is empty
template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
    return (first == NULL);     // Returns true if the first pointer is nullptr

}

// Deletes all nodes in the list
template <class Type>
void doublyLinkedList<Type>::destroy()
{
    nodeType<Type> *temp;       // Temporary pointer to hold nodes
    while(first !=  NULL)       // Iterate through the list
    {
        temp = first;           // Store the current node
        first = first->next;    // Move to the next node
        delete temp;            // Delete the current node
    }
    last = NULL;                // Set the last pointer to nullptr
    count = 0;                  // Reset the count to 0
}

// Reinitializes the list by destroying its content
template <class Type>
void doublyLinkedList<Type>::intializeList()
{
    destroy();                  // Call destroy to clear the list
}

// Returns the length of the list
template <class Type>
int doublyLinkedList<Type>::length() const
{
    return count;           // Return the count of nodes
}

// Prints the list from the first node to the last node
template <class Type>
void doublyLinkedList<Type>::print() const
{
    nodeType<Type> *current;            // Start from the first node
    current = first;
    while (current != NULL)             // Iterate through the list

    {
        cout << current->info << " ";   // Print the node's data
        current = current->next;        // Move to the next node
    }
}

// Prints the list from the last node to the first node
template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
    nodeType<Type> *current;            // Start from the last node
    current = last;
    while (current != NULL)             // Iterate backwards through the list
    {
        cout << current->info << " ";   // Print the node's data
        current = current->back;        // Move to the previous node
    }
}

// Searches for a specific value in the list
template <class Type>
bool doublyLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;                 // Flag to indicate if the item is found
    nodeType<Type> *current;            // Pointer to traverse the list

    current = first;                    // Start from the first node

    while(current != NULL && !found)
    {
        if(current->info == searchItem) // Check if the current node contains the item
        {
            found = true;               // Mark the item as found
        }
        else
        {
            current = current->next;    // Move to the next node
        }
    }
    if(found)                           // If the item was found in the loop
    {
        found = (current->info == searchItem);  // Ensure the match is exact
    }

    return found;   // Return true if the item was found
}






// Get the first element in the list
template <class Type>
Type doublyLinkedList<Type>::front() const
{
    assert(first != NULL);  // Ensure the list is not empty

    return first->info;     // Return the data of the first node
}


// Get the last element in the list
template <class Type>
Type doublyLinkedList<Type>::back() const
{
    assert(last != NULL);   // Ensure the list is not empty

    return last->info;      // Return the data of the last node
}



template <class Type>
void doublyLinkedList<Type>::insert(const Type& insertItem)
{
    nodeType<Type> *current;            // Pointer to traverse the list
    nodeType<Type> *trailCurrent;       // Pointer to the node before `current`
    nodeType<Type> *newNode;            // Pointer for the new node to be inserted
    bool found;                         // Flag to indicate if the correct position is found

    // Create a new node and set its data
    newNode = new nodeType<Type>;
    newNode->info = insertItem;
    newNode->next = NULL;
    newNode->back = NULL;

    if (first == NULL)                  // Case 1: The list is empty
    {
        first = newNode;                // Set the new node as the first node
        last = newNode;                 // Set the new node as the last node
        count++;                        // Increment the node count
    }
    else                                // Case 2: The list is not empty
    {
        found = false;
        current = first;                // Start from the first node

        // Traverse the list to find the correct position for insertion
        while(current != NULL && !found)
        {
            if(current->info >= insertItem) // Found the position where the new node should be inserted
            {
                found = true;
            }
            else
            {
                trailCurrent = current;     // Keep track of the previous node
                current = current->next;    // Move to the next node
            }
        }
        if(current == first)                // Case 2a: Insert at the beginning
        {
            first->back = newNode;          // Update the previous pointer of the original first node
            newNode->next = first;          // Link the new node to the original first node
            first = newNode;                // Update the first pointer
            count++;                        // Increment the node count
        }
        else                                // Case 2b: Insert in the middle or at the end
        {
            if(current != NULL)             // Case 2b.1: Insert in the middle
            {
                trailCurrent->next = newNode; // Link the previous node to the new node
                newNode->back = trailCurrent; // Update the back pointer of the new node
                newNode->next = current;      // Link the new node to the current node
                current->back = newNode;      // Update the back pointer of the current node
            }
            else                            // Case 2b.2: Insert at the end
            {
                trailCurrent->next = newNode;   // Link the last node to the new node
                newNode->back =trailCurrent;    // Update the back pointer of the new node
                last = newNode;                 // Update the last pointer
            }
            count++;                            // Increment the node count
        }


    }


}


template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;                // Pointer to traverse the list
    nodeType<Type> *trailCurrent;           // Pointer to the node before `current`

    bool found;                             // Flag to indicate if the item to delete is found

    if(first == NULL)                       // Case 1: The list is empty
    {
        cout<<"Cannot delete from an empty list." << endl;
    }
    else if(first->info == deleteItem)      // Case 2: Delete the first node
    {
        current = first;                    // Point to the first node
        first = first->next;                // Move the first pointer to the next node

        if(first != NULL)                   // If the list is not empty after deletion
        {
            first->back = NULL;             // Update the back pointer of the new first node
        }
        else                                // If the list is empty after deletion
        {
            last = NULL;                    // Update the last pointer
        }
        count--;                            // Decrement the node count

        delete current;                     // Free the memory of the deleted node

    }
    else                                    // Case 3: Delete a node that is not the first
    {
        found = false;
        current = first;                    // Start from the first node

        // Traverse the list to find the node to delete
        while (current != NULL && !found)
        {
            if (current->info >= deleteItem)
            {
                found = true;
            }
            else
            {
                current = current->next;    // Move to the next node
            }

        }
        if(current == NULL)                 // Case 3a: The item is not in the list
        {
            cout << "The item to be deleted is not in "<< "the list." << endl;
        }
        else if(current->info == deleteItem)        // Case 3b: The item is found
        {
            trailCurrent = current->back;           // Point to the previous node
            trailCurrent->next = current->next;     // Update the next pointer of the previous node

            if (current->next != NULL)              // If the node to delete is not the last node
            {
                current->next->back = trailCurrent; // Update the back pointer of the next node
            }

            if (current == last)                    // If the node to delete is the last node
            {
                last = trailCurrent;                // Update the last pointer
            }

            count--;                                // Decrement the node count
            delete current;                         // Free the memory of the deleted node
        }
        else                                        // Case 3c: The item is not in the list
        {
            cout << "The item to be deleted is not in list." << endl;
        }

    }

}

template <class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList<Type>& otherList)
{
    nodeType<Type> *newNode;                // Pointer for the new node to be created
    nodeType<Type> *current;                // Pointer to traverse the `otherList`

    // If the current list is not empty, destroy it first
    if (first != nullptr)
        destroy();

    // If the list to be copied is empty, set first and last to nullptr
    if (otherList.first == nullptr)     // Case 1: The other list is empty
    {
        first = nullptr; // Set the first pointer to null
        last = nullptr;  // Set the last pointer to null
        count = 0;       // Reset the count to 0
    }
    else                // Case 2: The other list is not empty
    {
        // Otherwise, initialize the new list
        current = otherList.first; // Start from the first node of the other list
        count = otherList.count;   // Copy the count of nodes

        // Create the first node
        first = new nodeType<Type>;
        first->info = current->info;
        first->next = nullptr;
        first->back = nullptr;
        last = first;
        current = current->next;    // Move to the next node

        // Copy the rest of the nodes
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->next = nullptr;
            newNode->back = last;
            last->next = newNode;
            last = newNode;
            current = current->next;
        }
    }
}

// Destructor: cleans up when the list object is destroyed
template <class Type>
doublyLinkedList<Type>::~doublyLinkedList()
{
    destroy();  // Call the destroy function to free memory
}


#endif // DOUBLYLINKEDLIST_H
