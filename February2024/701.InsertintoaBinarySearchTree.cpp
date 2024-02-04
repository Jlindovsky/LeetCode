/*
Difficulty: Medium
Description:
You are given the root node of a binary search tree (BST)
and a value to insert into the tree. Return the root node
of the BST after the insertion. It is guaranteed that
the new value does not exist in the original BST.
 */

#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

int main()
{
    // sample binary search tree
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // instance of the Solution class
    Solution solution;

    // Inserting a new value into the BST
    int newValue = 5;
    root = solution.insertIntoBST(root, newValue);

    std::cout << "Root value: " << root->val << std::endl;

    return 0;
}
