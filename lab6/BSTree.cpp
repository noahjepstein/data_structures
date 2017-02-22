#include "BSTree.h"


BST::BST()
{
	root = NULL;	
}

//
// Insert: public version of Insert takes a value only and
// 	   inserts in the tree at the root
//
void BST::unbalancedInsert(int v)
{
	root = unbalancedInsert(root, v);
}

//
// Insert: private version inserts a value at any subtree
//         given by the 'root' of that tree
//
//   returns: the current tree NOW WITH the value inserted
//   note: ALWAYS adds a leaf
//
BSTNode* BST::unbalancedInsert(BSTNode* r, int v)
{
        //Base Case for recursion:
        //We have reached the end of the
        //tree and we are at NULL. We
        //create a node with the correct
        //information and return a pointer
        //to the new data. This return sets
        //the value for the parent which made
        //the function call
        
        if(r == NULL)
        {
            r = new BSTNode;
            r->value = v;
            r->left = NULL;
            r->right = NULL;
            return r;
        }
        
        //notice we asked NULL first so that
        //r->left and r->right will not seg fault
        
        else if(v < r->value)
        {
            r->left = unbalancedInsert(r->left, v);
            return r;
            
        }
        
        else
        {
            r->right = unbalancedInsert(r->right, v);
            return r;
            
            
        }
}


//****************** inorder *****************//

void BST::inOrder()
{

	inOrder(root);	// calls the next one
	cout << endl;
}


void BST::inOrder(BSTNode* root)
{
    if (root == NULL){
	return;
    }
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}



//****************** postorder *****************//

/*

void BST::postOrder()
{	
	postOrder(root);	// calls the next one
}

void BST::postOrder(BSTNode* root)
{
	//your code here --- if you want

}

*/

//****************** preorder *****************//



// print the tree in preOrder using the next function
// Question to ponder: can we do this without a helper function?
void BST::preOrder()
{
	preOrder(root);		// calls the next one (really needed?)
}

//
// preOrder traversal using a stack of our own, not
// the one from the compiler

void BST::preOrder(BSTNode* root)
{
    stack<BSTNode*> s;
    BSTNode* iter = root;
    

    if (iter != NULL) {
      s.push(iter);
    }
    while (!s.empty()) {
      
	iter = s.top();
	cout << iter->value << " ";
	s.pop();
      
	if (iter->right != NULL) {
	    s.push(iter->right);
	}
	if (iter->left != NULL) {
	    s.push(iter->left);
	}
    }
}



//****************** levelorder *****************//



void BST::levelOrder()
{
    levelOrder(root);
}


void BST::levelOrder(BSTNode* root)
{
    Queue<BSTNode*> q;
    
    
    
    if (root != NULL) {
      BSTNode* iter = root;
      q.push(root);
    }
    
    while (!q.empty()) {
      iter = s.front();
      cout << q.front()->value << " ";
      q.pop; 
      if (iter->left != NULL){
	q.push(iter->left);
      }
      if (iter->right != NULL){
	q.push(iter->right);
      }
      
      
    }

}




