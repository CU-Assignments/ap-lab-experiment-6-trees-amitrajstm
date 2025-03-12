#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;

        while (curr != nullptr || !stk.empty())
        {
            // Reach the leftmost node of the current subtree
            while (curr != nullptr)
            {
                stk.push(curr);
                curr = curr->left;
            }
            // Current must be null at this point
            curr = stk.top();
            stk.pop();
            result.push_back(curr->val); // Visit root
            // Now visit the right subtree
            curr = curr->right;
        }

        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
