#include <iostream>
#include <string>
#include "arrayListType.h"
using namespace std;
int main()
{
    cout << "Hello world!" << endl;

    arrayListType<int> intList(100);
    arrayListType<string> stringList;

    int number,searched_number;

    cout << "List 10: Enter 5 integers: ";

    for (int counter = 0; counter < 5; counter++)
    {
        cin >> number;
        intList.insertAt(counter, number);
    }
    cout << endl;
    cout << "List 19: The list you entered is: ";
    intList.print();
    cout << endl;

/*  cout << "Line 20: Enter the item to be deleted: ";
    cin >> number;
    intList.remove(number);
    cout << "Line 23: After removing " << number<< ", the list is:" << endl;
    intList.print();
    cout << endl;
*/

    /*string str;
    cout << "Line 27: Enter 5 strings: ";
    for (int counter = 0; counter < 5; counter++)
    {
    cin >> str;
    stringList.insertAt(counter, str);
    }
    cout << endl;
    cout << "Line 34: The list you entered is: " << endl;
    stringList.print();
    cout << endl;

    cout << "Line 37: Enter the string to be deleted: ";
    cin >> str;
    stringList.remove(str);
    cout << "Line 40: After removing " << str<< ", the list is:" << endl;
    stringList.print();
    cout << endl;
    */

    cout << "Line 52: Enter the item to be searched for: ";
    cin >> searched_number;
    //cout<< intList.seqSearch(searched_number) << endl;
    cout<< intList.binarySearch(searched_number) << endl;


    return 0;
}
