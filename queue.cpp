#include "queue.h"
#include <iostream>
using namespace std;

bool Queue:: isEmpty(){
if (front == nullptr) {return true;}
  else return false;
}

Queue::~Queue(){
  Node* temp = front;
  Node* hldr = temp;
  while (temp != nullptr){
    temp = temp->nextPtr;
    delete hldr;
    hldr = temp;
    
  }
  
  
}

void Queue :: enQueue(Data d) {

  Node* newNode = new Node;
  newNode->data = d;
  newNode->nextPtr = nullptr;
//if empty
  if (front == nullptr){
    front = newNode;
    rear = newNode;
    
  }
  //if not empty
  else {
  rear->nextPtr = newNode;
    rear = newNode;

    
  }

  
}

int Queue::deQueue() {
if (front == nullptr) { return -1;}
  else {
    int val = front->data.value;
    Node* tempPtr = front;
    Data tempData = tempPtr->data;
    front = front->nextPtr;
    delete tempPtr;
    tempPtr = nullptr;
    return val;

    
  }
  
                       

  
}

int Queue::firstVal(){
if (front == nullptr) {return -1;}
  else {return front->data.value;}
  
}

int Queue::QueueCount(){

  if (front == nullptr) {return 0;}
  Node* temp = front;
  int num = 1;
  while (temp->nextPtr!=nullptr){
    num = num + 1;
  }
  delete temp;
  return num;
} 


