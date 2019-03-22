
#include"myintlinkedlist.h"

// constructor
myIntLinkedList::myIntLinkedList(){
    front = nullptr;
}

// destructor
myIntLinkedList::~myIntLinkedList(){
    ListNode* previuos = front;
    while(front->next != nullptr){
        previuos = front;
        front = front->next;
        delete previuos;
    }
    delete front;
}

void myIntLinkedList::addFront(int value){
    ListNode* newNode = new ListNode();
    newNode->data = value;
    newNode->next = front;
    front = newNode;
}


void myIntLinkedList::addBack(int value){
    if(front == nullptr){
        // empty list
        front = new ListNode(value);
    }else{
        ListNode* current = front;
        while(current->next != nullptr){
            current = current->next;
        }
        // at this point current is pointing to the last element
        ListNode* newValue = new ListNode();
        newValue->data = value;
        newValue->next = nullptr;

        current->next = newValue;
    }
}

void myIntLinkedList::removeFront(){
    if(front != nullptr){
        ListNode* trash = front;
        front = front->next;
        delete trash;
    }
}

void myIntLinkedList::removeBack(){
    if(front != nullptr){
        ListNode* current = front;
        ListNode* previus = nullptr;
        while(current->next != nullptr){
            previus = current;
            current = current->next;
        }
        // now current pointing to the last element
        ListNode* trash = current;
        current = previus;
        current->next = nullptr;
        delete trash;
    }
}

void myIntLinkedList::insert(int index, int value){
    ListNode* current = front;
    ListNode* previous = nullptr;
    int currentIndex = 0;
    while(true){
        if(currentIndex == index){
            //now current is pointing to the given index
            ListNode* newNode = new ListNode();
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


int myIntLinkedList::getFront() const {
    return front->data;
}

int myIntLinkedList::getBack() const{
    if(front->next != nullptr){
        ListNode* current = front;
        while(current->next != nullptr){
            current = current->next;
        }
        // now current is pointing to the last element
        return current->data;
    }else{
        return 0;
    }
}

int myIntLinkedList::get(int index) const {
    int currentIndex = 0;
    ListNode* current = front;
    while(true){
        if(currentIndex == index){
            //now current is pointing to the given index

            return current->data;
        }
        currentIndex++;
        current = current->next;
    }
}

string myIntLinkedList::toString() const {
    string llStr = "[";
    ListNode* current = front;
    while(current->next != nullptr){
        llStr = llStr + to_string(current->data) + ", ";
        current = current->next;
    }
    llStr = llStr + to_string(current->data) + "]";
    return llStr;
}
