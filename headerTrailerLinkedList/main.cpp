#include <iostream>
#include "headerTrailerLinkedList.h"

using namespace std;

int main()
{
         // Create a header-trailer linked list
    headerTrailerLinkedList<int> list;

    cout << "Testing headerTrailerLinkedList:" << endl;

    // Check if the list is initially empty
    if (list.isEmptyList()) {
        cout << "List is initially empty." << endl;
    }

    // Insert some elements
    list.insert(10);
    list.insert(20);
    list.insert(15);
    list.insert(25);

    // Print the list with header and trailer
    cout << "\nList after inserting elements:" << endl;
    list.printWithHeaderAndTrailer();

    // Print the list without header and trailer
    cout << "\nList elements (without header and trailer):" << endl;
    list.print();

    // Check the length of the list
    cout << "\n\nLength of the list: " << list.length() << endl;

    // Search for an element in the list
    int searchItem = 15;
    if (list.search(searchItem)) {
        cout << "Item " << searchItem << " is found in the list." << endl;
    } else {
        cout << "Item " << searchItem << " is not in the list." << endl;
    }

    // Delete an element
    int deleteItem = 20;
    cout << "\nDeleting item " << deleteItem << " from the list." << endl;
    list.deleteNode(deleteItem);

    // Print the list after deletion
    cout << "\nList after deletion:" << endl;
    list.printWithHeaderAndTrailer();

    // Destroy the list and check if it is empty
    cout << "\nDestroying the list..." << endl;
    list.destroy();
    if (list.isEmptyList()) {
        cout << "List is now empty." << endl;
    }

    return 0;
}
