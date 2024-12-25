#ifndef HEADERTRAILERLINKEDLIST_H
#define HEADERTRAILERLINKEDLIST_H

#include <iostream>

using namespace std;

// Definition of a node in the linked list template
template <class Type>
struct nodeType
{
    Type info;              // The data stored in the node
    nodeType<Type> *link;   // Pointer to the next node
};

// Class representing a header-trailer linked list template
template <class Type>
class headerTrailerLinkedList
{
    public:
        headerTrailerLinkedList();                                                                  // Default constructor

        headerTrailerLinkedList(const headerTrailerLinkedList<Type>& otherList);                    // Copy constructor

        const headerTrailerLinkedList<Type> & operator=(const headerTrailerLinkedList<Type> &);     // Assignment operator

        void intializeList();                       // Initialize the list (clear it)

        bool isEmptyList() const;                   // Check if the list is empty

        void destroy();                             // Destroy all nodes and clear the list

        void print() const;                         // Print all elements of the list

        void printWithHeaderAndTrailer() const;     // Print all elements of the list with header and trailer

        int length() const;                         // Get the number of elements in the list


        bool search(const Type& searchItem) const;  // Search for an item in the list

        void insert(const Type& insertItem);        // Insert an item into the list

        void deleteNode(const Type& deleteItem);    // Delete an item from the list


        virtual ~headerTrailerLinkedList();         // Destructor

    protected:
        Type count;                                 // Number of elements in the list
        nodeType<Type> *first;                      // Pointer to the header node
        nodeType<Type> *last;                       // Pointer to the trailer node


    private:
        void copyList(const headerTrailerLinkedList<Type>& otherList);  // Copy another list into this one
};

// Default constructor
// Initializes an empty list with header and trailer nodes
template<class Type>
headerTrailerLinkedList<Type>::headerTrailerLinkedList()
{
    first = new nodeType<Type>;         // Create header node
    last = new nodeType<Type>;          // Create trailer node
    first->link = last;                 // Link header to trailer
    last->link = NULL;                  // Trailer node points to NULL
    count = 0;                          // Initialize count to 0

    first->info = 0;                    // Set the value for the header node
    last->info  = 100;                  // Set the value for the trailer node
}

// Copy constructor
// Creates a new list as a copy of another list
template<class Type>
headerTrailerLinkedList<Type>::headerTrailerLinkedList(const headerTrailerLinkedList<Type>& otherList)
{
    first = new nodeType<Type>;         // Create header node
    last = new nodeType<Type>;          // Create trailer node
    first->link = last;                 // Link header to trailer
    last->link = NULL;                  // Trailer node points to NULL
    count = 0;                          // Initialize count to 0
    copyList(otherList);                // Copy elements from the other list
}



// Overloaded assignment operator
// Assigns one list to another
template<class Type>
const headerTrailerLinkedList<Type>& headerTrailerLinkedList<Type>::operator=(const headerTrailerLinkedList<Type>& otherList)
{
    if (this != &otherList)     // Avoid self-assignment
    {
        copyList(otherList);    // Copy the other list into this one
    }
    return *this;
}

// Initialize the list by destroying its current contents
template<class Type>
void headerTrailerLinkedList<Type>::intializeList()
{
    destroy();                  // Clear the list
}

// Check if the list is empty
// Returns true if the list has no elements
template<class Type>
bool headerTrailerLinkedList<Type>::isEmptyList() const
{
    return(first->link == last);    // If header points to trailer, the list is empty
}



// Destroy the list and free all allocated memory
template<class Type>
void headerTrailerLinkedList<Type>::destroy()
{
    nodeType<Type> *temp;
    nodeType<Type> *current;

    current = first->link;          // Start from the first actual node

    while(current != last)          // Traverse until the trailer node
    {
        temp = current;             // Save the current node
        current = current->link;    // Move to the next node
        first->link = current;      // Update the header's link
        delete temp;                // Delete the current node
    }
    last->link = NULL;                                       // Trailer node points to NULL
    count = 0;                                               // Reset count to 0
}

// Print the elements of the list
template <class Type>
void headerTrailerLinkedList<Type>::print() const
{
    nodeType<Type> *current;

    current = first->link;          // Start from the first actual node

    while(current != last)          // Traverse until the trailer node
    {
        cout<<current->info<<" ";   // Print the data
        current = current->link;    // Move to the next node
    }
}

template <class Type>
void headerTrailerLinkedList<Type>::printWithHeaderAndTrailer() const {
    // Print the header value
    cout << "Header: " << first->info << endl;

    // Print the list elements
    cout << "List elements: ";
    nodeType<Type> *current = first->link; // Start from the first actual node
    while (current != last) {              // Traverse until the trailer node
        cout << current->info << " ";      // Print the data
        current = current->link;           // Move to the next node
    }
    cout << endl;

    // Print the trailer value
    cout << "Trailer: " << last->info << endl;
}

// Return the number of elements in the list
template <class Type>
int headerTrailerLinkedList<Type>::length() const
{
    return count;   // Return the count of nodes
}


// Search for an item in the list
// Returns true if the item is found
template <class Type>
bool headerTrailerLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;

    current = first->link;              // Start from the first actual node

    while(current != last && !found)    // Traverse until the trailer node or item is found
    {
        if(current->info >= searchItem) // Stop if current info is greater or equal
        {
            found = true;
        }
        else
        {
            current = current->link;    // Move to the next node
        }
    }
    if(found)
    {
        found = (current->info == searchItem);  // Check if the item matches
    }

    return found;
}


// Insert a new item into the list
template <class Type>
void headerTrailerLinkedList<Type>::insert(const Type& insertItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;
    bool  found;

    newNode = new nodeType<Type>;       // Create a new node
    newNode->info = insertItem;         // Set the info
    newNode->link = NULL;               // Initialize the link

    if (first->link == last)            // If list is empty, newNode is the only node
    {
        first->link = newNode;          // Insert as the first node
        newNode->link = last;           // Link to the trailer node
        count++;
    }
    else
    {
        found = false;
        current = first->link;                  // Start from the first actual node

        while(current != last && !found)
        {
            if(current->info >= insertItem)     // Find the correct position to insert
            {
                found = true;
            }
            else
            {
                trailCurrent = current;         // Update the trailing pointer
                current = current->link;        // Move to the next node
            }
        }

        if (current == first->link)             // Insert at the beginning (after header)
        {
            newNode->link = first->link;
            first->link = newNode;
            count++;
        }
        else                                    // Insert in the middle or end
        {
            if(current != last)
            {
                trailCurrent->link = newNode;
                newNode->link = current;
            }
            else
            {
                trailCurrent->link = newNode;
                newNode->link = last;

            }
            count++;
        }

    }
}

// Delete an item from the list
template <class Type>
void headerTrailerLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;            // Pointer to traverse the list
    nodeType<Type> *trailCurrent;       // Pointer just before current
    bool found;

    if (first->link == last)            // If the list is empty
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        current = first->link;          // Start from the first actual node
        found = false;

        while(current != last && !found)
        {
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;     // Update the trailing pointer
                current = current->link;    // Move to the next node
            }
        }
        if(current == last)                 // Item not found
        {
            cout << "The item to be deleted is not in the list."<< endl;
        }
        else if(current->info == deleteItem)    // Item found
        {

            if (current == first->link)         // Delete the first actual node
            {
                first->link = first->link->link;
                delete current;
            }
            else                                // Delete a middle or last node
            {
                trailCurrent->link = current->link;

                if(current->link == last)
                {
                    trailCurrent->link = last;
                }
                delete current;
            }
            count--;
        }
        else
        {
            cout << "The item to be deleted is not in the "<< "list." << endl;
        }

    }

}

// Copy the contents of another list into this one
template <class Type>
void headerTrailerLinkedList<Type>::copyList(const headerTrailerLinkedList<Type>
        &otherList)
{
   nodeType<Type> *newNode;                         // Pointer to create a node
   nodeType<Type> *current;                         // Pointer to traverse the list
   nodeType<Type> *otherCurrent;                    // Pointer to traverse otherList

   if (first->link != last)                         // If the list is nonempty, make it empty
       destroy();                                   // Clear the current list

   if (otherList.first->link == otherList.last)     // If the other list is empty
   {
       first->link = last;
       last->link = NULL;
       count = 0;
   }
   else
   {
        otherCurrent = otherList.first->link;       // Start from the first actual node of the other list
                                                    // Copy the count
        count = otherList.count;

            // Copy the first node
        first->link = new nodeType<Type>;           // Create the node
        first->link->info = otherCurrent->info;     // Copy info
        first->link->link = last;                   // Link to trailer
        current = first->link;                      // Set current to this new node
        otherCurrent = otherCurrent->link;          // Move to the next node in the other list



        while (otherCurrent != otherList.last)      // Copy the rest of the nodes
        {
            newNode = new nodeType<Type>;           // Create a node
            newNode->info = otherCurrent->info;     // Copy info
            newNode->link = last;                   // Attach last
            current->link = newNode;                // Attach node
            current = current->link;                // Make current point to the next node
            otherCurrent = otherCurrent->link;      // Make otherCurrent point to the next node
        }
   }
}



template<class Type>
headerTrailerLinkedList<Type>::~headerTrailerLinkedList()
{
    destroy();
}

#endif // HEADERTRAILERLINKEDLIST_H
