#ifndef MYINTLINKEDLIST_H
#define MYINTLINKEDLIST_H

#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(){
        data = 0;
        next = nullptr;
    }

    ListNode(int value){
        data = value;
        next = nullptr;
    }
};


class myIntLinkedList{
public:
    myIntLinkedList(); // constructor
    ~myIntLinkedList(); // destructor

    void addFront(int value);
    void addBack(int value);
    void removeFront();
    void removeBack();
    void insert(int index, int value);
    int getFront() const;
    int getBack() const;
    int get(int index) const;
    string toString() const;
private:
    ListNode* front;
};


#endif // MYINTLINKEDLIST_H


