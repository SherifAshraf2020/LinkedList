#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{
    doublyLinkedList<int> list;

    // Display initial list (should be empty)
    cout << "Initial list (should be empty): ";
    list.print();
    cout << endl;

    // Insert elements into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Display list after insertions
    cout << "List after inserting 10, 20, 30, 40: ";
    list.print();
    cout << endl;

    // Display the list in reverse
    cout << "Reverse list: ";
    list.reversePrint();
    cout << endl;

    // Search for an element
    if (list.search(20)) {
        cout << "20 found in the list." << endl;
    } else {
        cout << "20 not found in the list." << endl;
    }

    // Delete an element
    list.deleteNode(20);

    // Display list after deletion
    cout << "List after deleting 20: ";
    list.print();
    cout << endl;

    // Try to delete a non-existent element
    list.deleteNode(50);
    cout << "List after attempting to delete 50 (should show 'not in the list'): ";
    list.print();
    cout << endl;

    // Access and print front and back elements if the list is not empty
    if (!list.isEmptyList()) {
        cout << "Front element: " << list.front() << endl;
        cout << "Back element: " << list.back() << endl;
    } else {
        cout << "List is empty, cannot access front element." << endl;
        cout << "List is empty, cannot access back element." << endl;
    }

    // Print the length of the list
    cout << "Length of the list: " << list.length() << endl;

    // Clear the list
    list.intializeList();

    // Display list after clearing
    cout << "List after clearing (should be empty): ";
    list.print();
    cout << endl;

    // Check if the list is empty and try to access front and back elements
    if (list.isEmptyList()) {
        cout << "List is empty, cannot access front element." << endl;
        cout << "List is empty, cannot access back element." << endl;
    } else {
        cout << "Front element: " << list.front() << endl;
        cout << "Back element: " << list.back() << endl;
    }



    return 0;
}
