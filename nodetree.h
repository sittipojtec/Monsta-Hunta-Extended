#ifndef treenode_h
#define treenode_h


class TreeNode {   
                                        
  TreeNode *leftPtr; 
  int data;                               
  TreeNode *rightPtr; 
public:
  TreeNode(int); 
  ~TreeNode();
  void set_left( TreeNode* t){ leftPtr=t;}
  void set_right( TreeNode* t){ rightPtr=t;}
  TreeNode* move_left(){return leftPtr;}
  TreeNode* move_right(){return rightPtr;}
  int get_value(){return data;}
}; 
        
typedef TreeNode* TreeNodePtr; 

TreeNode::TreeNode(int x){
  data=x;
  leftPtr=NULL;
  rightPtr=NULL;
}
                    
TreeNode::~TreeNode(){}



// Need to make a random array gen for each.



#endif