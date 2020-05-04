struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

// Helper function that allocates a new Node
TreeNode *newNode(int key)
{
    TreeNode *n = new TreeNode;
    n->val = key;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;

    return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use
TreeNode *insert(TreeNode *root, int key)
{
    // 1) If the tree is empty, return a new single Node
    if (root == nullptr)
        return newNode(key);

    TreeNode *temp;

    // 2) Otherwise, recur down the tree
    if (key < root->val)
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

void inorderTraverse(TreeNode* root, int& val, int& min_dif) {
    if (root->left != NULL) inorderTraverse(root->left, val, min_dif);
    if (val >= 0) min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) inorderTraverse(root->right, val, min_dif);
}
int getMinimumDifference(TreeNode* root) {
    auto min_dif = INT_MAX, val = -1;
    inorderTraverse(root, val, min_dif);
    return min_dif;
}