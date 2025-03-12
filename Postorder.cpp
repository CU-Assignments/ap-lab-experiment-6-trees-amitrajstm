#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    unordered_map<int, int> inorderMap;

    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int &postIndex)
    {
        // Base case: if start index exceeds end index, return null
        if (inStart > inEnd)
            return nullptr;

        // Get the root value from the current postorder index
        int rootVal = postorder[postIndex--];
        TreeNode *root = new TreeNode(rootVal);

        // Find the index of the root in the inorder traversal
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

        // Build a map to store the index of each value in inorder traversal for quick lookup
        for (int i = 0; i < n; ++i)
        {
            inorderMap[inorder[i]] = i;
        }

        // Build the binary tree using the helper function
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }
};

// Utility function to print the tree in inorder fashion
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

    cout << "Constructed Binary Tree (Inorder Traversal): ";
    printInorder(root);
    cout << endl;

    return 0;
}
