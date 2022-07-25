#include "nodetree.h"
#include "queue.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class BST {
	int size;
	TreeNodePtr rootPtr;
  void preOrder(TreeNodePtr);
  Queue a;

public:
	BST();
  ~BST();
  void insert_node(int);
  int checkTree();
};

BST::BST(){
  size=0;
  rootPtr=NULL;
}

BST::~BST(){
}

void BST::insert_node(int x) {
  for (int i=0; i< 10; i++){
	  x = rand()%39+9;
	}
  cout<<" "<<x;
  TreeNodePtr new_node = new TreeNode(x);
  if (new_node) {
    if (!rootPtr) {
      rootPtr = new_node;
    } else {
      int inserted = 0;
      TreeNodePtr t = rootPtr;
      while (!inserted) {
        if (t->get_value() >= x) {
          /* get to the left*/
          if (t->move_left() == NULL) {
            t->set_left(new_node);
            inserted = 1;
          }
          else{
            t = t->move_left();
          }
        } else {
          /* get to the right*/
          if (t->move_right() == NULL) {
            t->set_right(new_node);
            inserted = 1;
          }
          else{
            t = t->move_right();
          }
        }
      } // end while
      size++;
    } // end if;
  }
}

int BST::checkTree(){
  int v = a.sizeOf();
  for (int i=0; i<v;i++){
    a.dequeue();
  }
  int input;
  preOrder(rootPtr);
  //cout<<"size"<<a.sizeOf()<<endl;
  v = a.sizeOf();
  for (int j = 0; j< v; j++){
    cout<<"PreOrder (Hint: From Center -> Left -> Right): ";
    cin>>input;
    if (input != a.dequeue()){
      return -1;
    }
    else{
      cout<<"Correct! Next: ";
    }
	}
  return 0;
}

void BST::preOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    //cout<<setw(3)<<treePtr->get_value();
    a.enqueue(treePtr->get_value());
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }
} 

