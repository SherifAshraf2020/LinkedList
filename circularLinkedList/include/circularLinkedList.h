#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>

using namespace std;


template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};


template <class Type>
class circularLinkedList
{
    public:
        circularLinkedList();
        circularLinkedList(const circularLinkedList<Type>& otherList);
        circularLinkedList& operator=(const circularLinkedList<Type>& otherList);

        void initializeList();
        bool isEmpty() const;
        void destroy();
        void print() const;
        int length() const;
        bool search(const Type& searchItem) const;
        void insert(const Type& insertItem);
        void deleteNode(const Type& deleteItem);

        virtual ~circularLinkedList();

    protected:
        Type count;
        nodeType<Type> *first;
    private:
        void copyList(const circularLinkedList<Type>& otherList);
};


template <class Type>
circularLinkedList<Type>::circularLinkedList()
{
    first = NULL;  // Initialize the list as empty
    count = 0;     // Set the count to 0
}



template <class Type>
circularLinkedList<Type>::circularLinkedList(const circularLinkedList<Type>& otherList)
{
    copyList(otherList);  // Use the copyList function to copy nodes
}


template <class Type>
circularLinkedList<Type>& circularLinkedList<Type>::operator=(const circularLinkedList<Type>& otherList)
{
    if (this != &otherList)     // Avoid self-assignment
    {
        destroy();               // Destroy the current list
        copyList(otherList);     // Copy the other list's contents
    }
    return *this;                // Return the current object
}




template <class Type>
void circularLinkedList<Type>::copyList(const circularLinkedList<Type>& otherList)
{
    first = NULL;  // Start with an empty list
    count = 0;     // Initialize the count to 0

    // If the other list is empty, we're done
    if (otherList.first == NULL) {
        return;
    }

    nodeType<Type> *current = otherList.first->link;  // Start from the first node of the other list
    do {
        insert(current->info);  // Insert each element from the other list into this list
        current = current->link;
    } while (current != otherList.first->link);  // Continue until we circle back to the start
}

template <class Type>
bool circularLinkedList<Type>::isEmpty() const
{
    return (first == NULL);
}

template <class Type>
void circularLinkedList<Type>::initializeList()
{
    destroy();
}

template <class Type>
int circularLinkedList<Type>::length() const
{
    return count;
}

template <class Type>
void circularLinkedList<Type>::destroy()
{
   if (first == NULL) return; // If the list is empty, nothing to destroy.

    nodeType<Type> *current = first->link; // Start from the node after `first`.
    nodeType<Type> *temp;

    while (current != first) // Traverse until we delete all nodes except the one pointed to by `first`.
    {
        temp = current;
        current = current->link; // Move to the next node.
        delete temp;             // Delete the current node.
    }

    // Delete the node pointed to by `first`.
    delete first;
    first = NULL; // Reset `first` to NULL.
    count = 0;    // Reset the count.
}

template <class Type>
void circularLinkedList<Type>::print() const
{
    if (first == NULL) // Check if the list is empty.
    {
        cout << "List is empty" << endl;
        return;
    }


    nodeType<Type> *current = first->link; // Start from the actual first node.

    do
    {
        cout << current->info << " "; // Print the current node's info.
        current = current->link;     // Move to the next node.
    } while (current != first->link); // Stop when we circle back to the start.

    cout << endl; // Add a newline at the end.
}

template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem) const
{
    if (first == NULL) // If the list is empty, return false.
        return false;

    nodeType<Type> *current = first->link; // Start from the actual first node.

    do
    {
        if (current->info >= searchItem) // Exit the loop if current info is >= searchItem
            break;

        current = current->link; // Move to the next node.
    } while (current != first->link); // Continue until we circle back to the starting node.

    // After exiting the loop, check if we found the item.
    return (current->info == searchItem); // If we find the searchItem, return true.
}

template <class Type>
void circularLinkedList<Type>::insert(const Type& insertItem)
{
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = insertItem;

    if(isEmpty())
    {
        newNode->link = newNode;
        first = newNode;
    }
    else
    {
        nodeType<Type>* current = first->link; // Start from the first actual node
        nodeType<Type>* trailCurrent = first;  // Start from the last node

        if(newNode->info < current->info)
        {
            newNode->link = current;
            trailCurrent->link =newNode;
            first->link = newNode;
        }
        else
        {
             do
             {
                 trailCurrent = current;
                 current = current->link;
             }while(current != first->link && current->info < newNode->info);

             trailCurrent->link = newNode;
             newNode->link = current;

             if(trailCurrent == first)
             {
                 first = newNode;
             }
        }

    }

    count++;
}


template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem)
{

    if (first == NULL)
    {  // Case 1: The list is empty
        cout << "Cannot delete from an empty list." << endl;
        return;
    }

    nodeType<Type> *current = first->link;  // Start from the first node
    nodeType<Type> *trailCurrent = first;   // Points to the last node initially
    bool found = false;

    // Traverse the list to find the node to delete
    do
    {
        if (current->info == deleteItem)
        {
            found = true;
            break;
        }
        trailCurrent = current;
        current = current->link;
    } while (current != first->link);

    if (!found) // Case 2: The item is not in the list
    {
        cout << "The item to be deleted is not in the list." << endl;
        return;
    }

    // Case 3: Delete the node
    if (current == first->link)
    {  // If deleting the first actual node
        first->link = current->link;  // Update first to point to the next node
        if (first->link == current)
        { // If there's only one node
            first = NULL;  // Reset the list to empty
        }
    }
    else    // Delete a middle or last node
    {
        trailCurrent->link = current->link;

        if (current == first)   // If deleting the last node
        {
            first = trailCurrent;  // Update first to point to the new last node
        }
    }

    delete current;  // Free the memory
    count--;         // Decrement the node count

}


template <class Type>
circularLinkedList<Type>::~circularLinkedList()
{
    destroy();  // Calls the destroy function to delete all nodes
}

#endif // CIRCULARLINKEDLIST_H
