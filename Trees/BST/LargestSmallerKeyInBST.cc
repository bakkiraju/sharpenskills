#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

// Helper function that allocates a new Node
Node *newNode(int key)
{
    Node *n = new Node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;

    return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use
Node *insert(Node *root, int key)
{
    // 1) If the tree is empty, return a new single Node
    if (root == nullptr)
        return newNode(key);

    Node *temp;

    // 2) Otherwise, recur down the tree
    if (key < root->key)
    {
        temp = insert(root->left, key);
        root->left = temp;
        temp->parent = root;
    }
    else
    {
        temp = insert(root->right, key);
        root->right = temp;
        temp->parent = root;
    }

    // Return the (unchanged) Node pointer
    return root;
}

// 20 > 17 left
// 9 < 17 right
// 12 < 17 right
// 14 < 17 right

int helper(Node *rootNode, int num)
{
    int lsf = -1;
    while (rootNode != NULL)
    {
        if (rootNode->key >= num)
        {
            rootNode = rootNode->left;
        }
        else
        {
            lsf = rootNode->key;
            rootNode = rootNode->right;
        }
    }

    return lsf;
}

int findLargestSmallerKey(Node *rootNode, int num)
{
    return helper(rootNode, num);
}

int main()
{
    Node *root = insert(root, 25);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);
    std::cout << findLargestSmallerKey(root, 4);
 
    return 0;
}