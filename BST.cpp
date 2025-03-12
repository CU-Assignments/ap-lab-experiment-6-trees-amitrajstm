#include <iostream>
#include <vector>
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        // Base case: if the left index exceeds the right index, return null
        if (left > right)
            return nullptr;

        // Choose the middle element as the root
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};

// Utility function to print the tree in inorder traversal
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
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
