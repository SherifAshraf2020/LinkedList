#include <iostream>
#include "linkedListIterator.h"
#include "linkedListType.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"
using namespace std;

int main()
{

    // Testing Unordered Linked List
    cout << "Testing Unordered Linked List" << endl;

    unorderedLinkedList<int> unorderedList;

    // InsertFirst
    unorderedList.insertFirst(10);
    unorderedList.insertFirst(20);
    unorderedList.insertFirst(30);

    cout << "After insertFirst (30, 20, 10): ";
    unorderedList.print();
    cout << endl;

    // InsertLast
    unorderedList.insertLast(40);
    unorderedList.insertLast(50);

    cout << "After insertLast (40, 50): ";
    unorderedList.print();
    cout << endl;

    // Search for elements
    cout << "Searching for 20: " << (unorderedList.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 60: " << (unorderedList.search(60) ? "Found" : "Not Found") << endl;

    // Delete specific nodes
    unorderedList.deleteNode(30);
    cout << "After deleting 30: ";
    unorderedList.print();
    cout << endl;

    unorderedList.deleteNode(50);
    cout << "After deleting 50: ";
    unorderedList.print();
    cout << endl;

    unorderedList.deleteNode(100);
    cout << "After attempting to delete 100 (not in list): ";
    unorderedList.print();
    cout << endl;

    // Clear the list
    unorderedList.destroyList();
    cout << "After deleting all nodes: ";
    unorderedList.print();
    cout << endl << endl;

    // Testing Ordered Linked List
    cout << "Testing Ordered Linked List" << endl;

    orderedLinkedList<int> orderedList;

    // Insert elements
    orderedList.insert(20);
    orderedList.insert(10);
    orderedList.insert(30);
    orderedList.insert(40);

    cout << "After insert (10, 20, 30, 40): ";
    orderedList.print();
    cout << endl;

    // Search for elements
    cout << "Searching for 20: " << (orderedList.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (orderedList.search(25) ? "Found" : "Not Found") << endl;

    // Delete specific nodes
    orderedList.deleteNode(20);
    cout << "After deleting 20: ";
    orderedList.print();
    cout << endl;

    orderedList.deleteNode(40);
    cout << "After deleting 40: ";
    orderedList.print();
    cout << endl;

    orderedList.deleteNode(100);
    cout << "After attempting to delete 100 (not in list): ";
    orderedList.print();
    cout << endl;

    // Clear the list
    orderedList.destroyList();
    cout << "After deleting all nodes: ";
    orderedList.print();
    cout << endl;

    // Insert duplicates
    orderedList.insert(20);
    orderedList.insert(10);
    orderedList.insert(20);
    orderedList.insert(30);

    cout << "After inserting duplicates (10, 20, 20, 30): ";
    orderedList.print();
    cout << endl;

    orderedList.deleteNode(20);
    cout << "After deleting one occurrence of 20: ";
    orderedList.print();
    cout << endl;

    return 0;
}

/*
Testing Unordered Linked List
After insertFirst (30, 20, 10): 30 20 10
After insertLast (40, 50): 30 20 10 40 50
Searching for 20: Found
Searching for 60: Not Found
After deleting 30: 20 10 40 50
After deleting 50: 20 10 40
The item to be deleted is not in the list.
After attempting to delete 100 (not in list): 20 10 40
After deleting all nodes:

Testing Ordered Linked List
After insert (10, 20, 30, 40): 10 20 30 40
Searching for 20: Found
Searching for 25: Not Found
After deleting 20: 10 30 40
After deleting 40: 10 30
The item to be deleted is not in the list.
After attempting to delete 100 (not in list): 10 30
After deleting all nodes:
After inserting duplicates (10, 20, 20, 30): 10 20 20 30
After deleting one occurrence of 20: 10 20 30
*/
