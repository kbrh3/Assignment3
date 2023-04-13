
#pragma once
#include <string>
using namespace std;
//Queue using linked list

struct Data {
int value;
}; //int to hold in node

struct Node {
Data data;
Node* nextPtr;
}; //vehicle for holding information in the linked list

class Queue {
private:
Node* front;
Node* rear;



public:
Queue() {front = nullptr; rear = nullptr;} //constructor
~ Queue(); //destructor
bool isEmpty();  //checks if empty
void enQueue(Data d); //adds to end of queue
int deQueue();   //return value of first node and deletes it
int firstVal();  //returns value of first node
int QueueCount(); //returns number of items in queue
char queueMenu(); //prints a menu to decide what to do with queue
}; //'queue' controls for the linked list


char queueMenu(); //prints a menu to decide what to do with queue