
#include <iostream>
#include "console.h"
#include "ginteractors.h" // for GWindow
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

struct ListdNode{
    int data;
    ListdNode* next;

    ListdNode(int value){
        data = value;
        next = nullptr;
    }

    ListdNode(){
        data = 0;
        next = nullptr;
    }

};

void printList(ListdNode* node);
void addFront(ListdNode*& front, int value);
void addBack(ListdNode* front, int value);
void removeFront(ListdNode*& front);
void removeBack(ListdNode* front);
int duplicates(ListdNode* front);
void insert(ListdNode* front, int index, int value);

int main() {
    /*
    ListdNode* front = new ListdNode();
    front->data = 42;
    front->next = new ListdNode();
    front->next->data = -3;
    front->next->next = new ListdNode();
    front->next->next->data = 17;
    front->next->next->next = new ListdNode();
    front->next->next->next->data = 9;
    front->next->next->next->next = nullptr;
    */

    // 8, 23, 19, 7, 102
    ListdNode* front = nullptr;
    addFront(front , 102);
    addFront(front , 7);
    addFront(front , 19);
    addFront(front , 23);
    addFront(front , 8);


    cout << "First Print " << endl;
    printList(front);


    // add  100 at the front of the linked list
    //addFront(front , 100);
    //cout << "After Adding 100 at front:  " << endl;
    //printList(front);

    // add 10 at the back of the linked List
    //addBack(front, 10);
    //cout << "After Adding 10 at back:  " << endl;
    //printList(front);


    // remove front element
    //removeFront(front);
    //cout << "After Removing Front :  " << endl;
    //printList(front);

    // remove back element
    //removeBack(front);
    //cout << "After Removing Back : " << endl;
    //printList(front);

    //cout << "Total Duplicates: " << duplicates(front) <<endl;

    insert(front, 2, 42);
    cout << "Afetr calling insert(front, 2, 42) " << endl;
    printList(front);
    return 0;
}



void insert(ListdNode* front, int index, int value){
    ListdNode* current = front;
    ListdNode* previous = nullptr;
    int currentIndex = 0;
    while(true){
        if(currentIndex == index){
            //now current is pointing to the given index
            ListdNode* newNode = new ListdNode();
            newNode->data = value;
            newNode->next = current;
            previous->next = newNode;
            break;
        }
        currentIndex++;
        previous = current;
        current = current->next;
    }
}




// Assumes That List is in sorted Order
int duplicates(ListdNode* front){
    ListdNode* current = front;
    ListdNode* previous = nullptr;
    int count = 0;
    while(current->next != nullptr){
        previous = current;
        current = current->next;
        if(previous->data == current->data){
            count = count +1;
        }
    }
    return count;
}


void removeBack(ListdNode* front){
    if(front != nullptr){
        ListdNode* current = front;
        ListdNode* previus = nullptr;
        while(current->next != nullptr){
            previus = current;
            current = current->next;
        }
        // now current pointing to the last element
        ListdNode* trash = current;
        current = previus;
        current->next = nullptr;
        delete trash;
    }
}


void removeFront(ListdNode*& front){
    if(front != nullptr){
        ListdNode* trash = front;
        front = front->next;
        delete trash;
    }
}



void addBack(ListdNode* front , int value){
    if(front == nullptr){
        // empty list
        front = new ListdNode(value);
    }else{
        ListdNode* current = front;
        while(current->next != nullptr){
            current = current->next;
        }
        // at this point current is pointing to the last element
        ListdNode* newValue = new ListdNode();
        newValue->data = value;
        newValue->next = nullptr;

        current->next = newValue;
    }
}


void addFront(ListdNode*& front, int value){
    ListdNode* newNode = new ListdNode();
    newNode->data = value;
    newNode->next = front;
    front = newNode;
}


void printList(ListdNode* node){
    while(node != nullptr){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
