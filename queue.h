#include "nodequeue.h"

#ifndef queue_h
#define queue_h

class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
   void enqueue(int);
   int dequeue();
   int sizeOf();
   Queue();
   ~Queue(); // dequeue all
};

Queue::Queue(){
  size=0;
  headPtr=NULL;
  tailPtr=NULL;
}

Queue::~Queue(){
  /*basically dequeue all*/
  NodePtr t = headPtr;
  int i;
	for(i=0; i<size ;i++){
    t = headPtr; 
    headPtr = headPtr->get_next();
    delete t;
    } 
  //for() dequeue();
}

void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
  
  if(!headPtr) headPtr = new_node;
  else tailPtr->set_next(new_node);
    
  tailPtr = new_node;

  //cout<<"enqueue "<<x<<endl;
  
	size++;
 }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
     NodePtr t=headPtr;
     int value= t->get_value();
     headPtr = headPtr->get_next();
    if (size==1) tailPtr=NULL;
     size--;    
     delete t;
     return value;
  }
  else{
  cout<<"The queue is empty "<<endl;
  }
  return -1;
}

int Queue::sizeOf(){
  return size;
}

// 1. Move head away --> to the next one
// last node change tail

//set_next = connect / deQ = no need to connect
//get = get value where it points to


#endif