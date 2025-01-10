#include <iostream>
#include "circularLinkedList.h"

using namespace std;

int main()
{
     circularLinkedList<int> list;

    std::cout << "Inserting elements into the list: 30, 10, 40, 20, 50\n";

    list.insert(30);
    list.insert(10);
    list.insert(40);
    list.insert(20);
    list.insert(50);

    std::cout << "List after insertion (should be sorted): ";
    list.print();

    std::cout << "Length of the list: " << list.length() << "\n";

    int searchItem = 60;
    std::cout << "Searching for " << searchItem << ": "
              << (list.search(searchItem) ? "Found" : "Not Found") << "\n";

    int deleteItem = 30;
    std::cout << "Deleting item " << deleteItem << " from the list...\n";
    list.deleteNode(deleteItem);

    std::cout << "List after deletion: ";
    list.print();

    std::cout << "Creating a copy of the list (list2)...\n";
    circularLinkedList<int> list2 = list;

    std::cout << "List2 after assignment from list: ";
    list2.print();

    std::cout << "Destroying list...\n";
    list.destroy();

    std::cout << "List after destruction: ";
    list.print();

}



