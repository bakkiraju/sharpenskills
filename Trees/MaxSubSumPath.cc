// TODO : print path has issues
#include <iostream>
using namespace std;

struct Node 
{
    Node *left;
    Node *right;

    int data;

    Node(int val)
    { 
        this->left = this->right = nullptr;   
        this->data = val;
    }
};

int findMaxSum(Node *root)
{
    if (root == nullptr) return 0;

    int left = findMaxSum(root->left);
    int right = findMaxSum(root->right);

    int val = (left < right) ? right : left;
    return val + root->data;
}

bool printMaxSumPath(Node *root, int sum)
{
    if (sum == 0) return true;

    if (root == nullptr)
       return false;
    
    bool left = printMaxSumPath(root->left, sum - root->data);
    bool right = printMaxSumPath(root->right, sum - root->data);

    if (left || right)
    {
        cout << root->data << " ";
    }

    return right || left;

}

int main()
{
     /* Construct below tree
			  1
			/   \
		   /     \
		  2       3
		 / \     / \
		8   4   5   6
		   /   / \   \
		 10   7   9   5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(8);
    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->left->right->left = new Node(10);
    
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(8);

    int sum = findMaxSum(root);

    cout << "Max sum:" << sum << endl;
    printMaxSumPath(root, sum);

    return 0;
}