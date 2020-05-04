#include <iostream>

// 5,9, 11,12, 14, 20, 25
using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

Node* findInOrderSuccessor( Node *inputNode )
{
    if (inputNode->right)
    {
       // left most child in the right sub tree
       Node *curr = inputNode->right;
       while(curr->left)
       {
         curr = curr->left;
       }
       
       return curr;
    }
    else
    {
        // keep going up until u find a node with no ancestor 
        Node *child = inputNode;
        Node *ancestor = child->parent;
      
        while (ancestor != NULL && child == ancestor->right)
        {
           child = ancestor;
           ancestor = child->parent;
        }
      
        return ancestor;
    }
}

void printInOrder(Node *root)
{
     if (root == NULL)
     {
          return;
     }

     printInOrder(root->left);
     cout << root->key << " ";  
     printInOrder(root->right);
}

int main() {
  Node *root = insert(NULL, 20);
  insert(root,9);
  insert(root,25);
  insert(root,5);
  insert(root,12);
  insert(root,11);
  insert(root,14);
  insert(root,25);
  
  printInOrder(root);

  Node *n = getNodeByKey(root, 14);
  
  cout << n->key << endl;
  
  Node *p = findInOrderSuccessor(n);
  
  cout << p->key << endl;
  return 0;
}