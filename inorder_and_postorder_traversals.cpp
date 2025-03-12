#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
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
    unordered_map<int, int> inorderMap;

    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int &postIndex)
    {
        // Base case
        if (inStart > inEnd)
            return nullptr;

        // Get the current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootVal);

        // Find the index of the root in the inorder array
        int inIndex = inorderMap[rootVal];

        // Recursively build the right and left subtrees
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postIndex = n - 1;

        // Build a map to store the index of each value in the inorder traversal
        for (int i = 0; i < n; ++i)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }
};

// Utility function to print inorder traversal of the tree
void printInorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode *root = sol.buildTree(inorder, postorder);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}