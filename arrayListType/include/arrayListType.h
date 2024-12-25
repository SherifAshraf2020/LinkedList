#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

// Template class for a generic array-based list
template <class elemType>
class arrayListType
{
    public:
        // Constructors
        arrayListType(int size = 100); // Default constructor
        arrayListType(const arrayListType<elemType>& otherList); // Copy constructor

        // Overloaded assignment operator
        const arrayListType<elemType>& operator=(const arrayListType<elemType>&);


        // Utility functions
        bool isEmpty() const; // Check if the list is empty
        bool isFull() const; // Check if the list is full


        int listSize() const; // Get the current number of elements
        int maxListSize() const; // Get the maximum size of the list


        void print() const; // Print all elements of the list


        // Element-specific operations
        bool isItemEqual(int location , const elemType& item) const; // Check if item at a location matches


        void insertAt(int location , const elemType& insertItem); // Insert item at a specific location
        void insertEnd(const elemType& insertItem); // Insert item at the end



        void removeAt(int location); // Remove an item at a specific location



        void retrieveAt(int location , elemType& retItem) const;  // Retrieve an item at a location
        void replaceAt(int location , const elemType& repItem); // Replace item at a specific location


        void clearList(); // Clear the list


        // Search functions
        int seqSearch(const elemType& item) const; // Sequential search
        int binarySearch(const elemType& item) const; // Binary search



        // High-level insert/remove
        void insert(const elemType& insertItem); // Insert item if not a duplicate
        void remove(const elemType& removeItem); // Remove specific item





        // Destructor
        virtual ~arrayListType();


    protected:
        elemType *list; // Dynamic array to hold elements
        int length;     // Current number of elements
        int maxSize;    // Maximum capacity of the list



    private:
};




#include "arrayListType.h"


// Constructor: Initializes list with given size
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    //ctor
    // Constructor to initialize an array list with a given size
    if (size < 0)
        {
            // If the provided size is negative, display an error message
            cerr << "The array size must be positive. Creating "<< "an array of size 100. " << endl;
            maxSize = 100;          // Default to a size of 100
        }
    else
    {
       maxSize = size;              // Use the provided size if valid
    }

    length = 0;                     // Initially, the list contains no elements
    list = new elemType[maxSize];   // Dynamically allocate memory for the array of the specified size
    assert(list != nullptr);        // Check if memory allocation succeeded

}


// Copy constructor: Creates a deep copy of another list
template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;        // Set the maximum size of the new list to match the other list
    length = otherList.length;          // Set the current length to match the other list
    list = new elemType[maxSize];       // Dynamically allocate memory for the new list
    assert(list != nullptr);            // Ensure memory allocation was successful

    // Copy each element from the source list to the new list
    for (int j = 0; j < length; j++)
    {
        list [j] = otherList.list[j];
    }
}


// Overloaded assignment operator: Deep copy of one list to another
template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList)
{
    // Check for self-assignment to avoid redundant work
    if (this != &otherList)
    {
        // Deallocate the current list to free existing memory
        delete [] list;

        // Copy the maximum size and current length of the other list
        maxSize = otherList.maxSize;
        length = otherList.length;

        // Allocate new memory for the list
        list = new elemType[maxSize];

        // Ensure the memory allocation was successful
        assert(list != NULL);

        // Copy elements from the other list into the current list
        for (int i = 0; i < length; i++)
        {
            list[i] = otherList.list[i];
        }

    }
    // Return the current object by reference to allow chaining
    return *this;
}



// Utility function implementations

// Checks if the list is empty
template <class elemType>
bool arrayListType<elemType>::isEmpty()const
{
    return(length == 0);            // Returns true if the list has no elements
}

// Checks if the list is full
template <class elemType>
bool arrayListType<elemType>::isFull()const
{
    return(length == maxSize);      // Returns true if the list has reached its maximum size
}


// Returns the current number of elements in the list
template <class elemType>
int arrayListType<elemType>::listSize()const
{
    return length;                  // The number of elements currently in the list
}

// Returns the maximum size the list can hold
template <class elemType>
int arrayListType<elemType>::maxListSize()const
{
    return maxSize;                 // The capacity of the list
}


// Print all elements of the list
template <class elemType>
void arrayListType<elemType>::print()const
{
    // Loop through each element in the list and print it
    for (int i = 0; i < length; i++)
        {
            cout << list[i] << " "; // Print each element followed by a space
        }
    // Print a newline at the end of the list for clarity
    cout << endl;
}


// Check if an item matches a specific location
template <class elemType>
bool arrayListType<elemType>::isItemEqual(int location , const elemType& item)const
{
    return(list[location] == item);     // Return true if the item at the location is equal to the given item
}


// Insert an item at a specific location
template <class elemType>
void arrayListType<elemType>::insertAt(int location , const elemType& insertItem)
{
    // Check if the location is valid
    if (location < 0 || location >= maxSize)
    {
        cerr << "The position of the item to be inserted "<< "is out of range" << endl;

    }

    else
    {
        // Check if the list is full
        if (length >= maxSize)
        {
           cerr << "Cannot insert in a full list" << endl;
        }

        else
        {
             // Shift elements to the right to make space for the new item
            for(int i = length ; i  > location ; i--)
            {
                list[i] = list[i-1];

            }
            list[location] = insertItem;        // Insert the item at the specified location
            length++;                           // Increase the length of the list


        }

    }


}

// Insert an item at the end of the list
template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    list[length] = insertItem; // Add the item at the end
    length++; // Increment the list length
}



// Remove an item at a specific location
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    // Check if the location is valid
    if (location < 0 || location >= length)
    {
        cerr << "The location of the item to be removed "<< "is out of range" << endl;
    }
    else
    {
        // Shift elements to the left to remove the item
        for(int i = location ; i < length - 1  ; i++)
        {
            list[i] = list[i+1]; // Shift elements to the left
        }
        length--; // Decrease the list length

    }

}



// Retrieve an item at a specific location
template <class elemType>
void arrayListType<elemType>::retrieveAt(int location , elemType& retItem)const
{
    // Check if the location is valid
    if (location < 0 || location >= length)
    {
        cout <<"The item's location is out of range" << endl;
    }
    else
    {
        retItem = list[location]; // Assign the item at the location to retItem
    }
}


// Replace an item at a specific location
template <class elemType>
void arrayListType<elemType>::replaceAt(int location , const elemType& repItem)
{
    // Check if the location is valid
    if (location < 0 || location >= length)
    {
        cerr << "The location of the item to be replaced is "<< "out of range." << endl;

    }
    else
    {
        list[location] = repItem; // Replace the item at the location with the new item
    }
}



// Clear the list by setting its length to 0
template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0; // Set length to 0, effectively clearing the list
}


// Sequential search: Finds the first occurrence of an item in the list
template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;                 // Flag to track if the item is found
    // Loop through the list to search for the item
    for (loc = 0; loc < length; loc++)
    {
        if (list[loc] == item)          // If the item is found
        {
            found = true;               // Set found to true
            break;                      // Exit the loop once the item is found
        }
    }
    // If the item was found, return its index
    if(found)
    {
        return loc; // Return the index of the item if found
    }
    else
    {
        return -1; // Return -1 if the item is not found
    }

}


template <class elemType>
int arrayListType<elemType>::binarySearch(const elemType& item) const
{
    int first = 0;                   // Starting index of the search range
    int last = length - 1;           // Ending index of the search range
    int mid;                         // Middle index

    bool found = false;              // Flag to indicate if the item is found


     // Continue searching while the range is valid and the item is not found
    while(first <= last && !found)
    {
        mid = ( first + last ) / 2 ; // Calculate the middle index
        if(item > list[mid])
        {
            first = mid + 1;         // Search in the right half of the list

        }
        else if(item < list[mid])
        {
            last = mid - 1 ;         // Search in the left half of the list

        }
        else
        {
            found = true;            // Item is found at the middle index
        }
    }

    if(found)
    {
        return mid;                  // Return the index where the item is found
    }
    else
    {
        return -2;                   // Return -2 if the item is not found
    }

}




// Insert an item into the list if it's not already present
template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    // If the list is empty, directly insert the item
    if (length == 0)
    {
        list[length++] = insertItem; // Insert into an empty list
    }
   // If the list is full, display an error
    else if (length == maxSize)

    {
       cerr << "Cannot insert in a full list." << endl;
    }
    else
    {
        loc = seqSearch(insertItem);        // Search for the item in the list

        // If the item is not found, insert it at the end
        if (loc == -1)
        {
        list[length++] = insertItem;        // Insert if not found in the list
        }


        else
        {
            // If the item is found, display an error (no duplicates allowed)
            cerr << "the item to be inserted is already in "<< "the list. No duplicates are allowed." << endl;
        }

    }
}


// Remove an item from the list
template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    // If the list is empty, display an error
    if (length == 0)
    {
        cerr << "Cannot delete from an empty list." << endl;
    }

    else
    {
        loc = seqSearch(removeItem); // Search for the item
        // If the item is found, remove it
        if (loc != -1)
        {
            removeAt(loc); // Remove it if found
        }

        else
        {
            // If the item is not found, display an error
            cout << "The item to be deleted is not in the list."<< endl;
        }

    }
}

// Destructor: Releases the dynamically allocated memory
template<class elemType>
arrayListType<elemType>::~arrayListType()
{
    //dtor
    // Free the dynamically allocated array memory when the object is destroyed
    delete [] list; // Release allocated memory
}





#endif // ARRAYLISTTYPE_H
