
#include <iostream>
#include "console.h"
#include "ginteractors.h" // for GWindow
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "myintlinkedlist.h"
using namespace std;


int main() {

    myIntLinkedList linkedList;
    linkedList.addFront(10);
    linkedList.addFront(11);
    linkedList.addBack(12);
    linkedList.addBack(13);
    linkedList.insert(2,100);
    cout << "Linked List is : " << linkedList.toString() << endl;
    cout << "Front is : " << linkedList.getFront() << endl;
    cout << "Back is : " << linkedList.getBack() << endl;
    cout << "In the index 2 value : " << linkedList.get(2) << endl;
    return 0;
}


