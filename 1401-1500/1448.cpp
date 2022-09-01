/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int goodNodes(TreeNode* root, int maxi = INT_MIN) {
    if (!root)
      return 0;

    const int newMax = max(maxi, root->val);
    return (root->val >= maxi) +
           goodNodes(root->left, newMax) +
           goodNodes(root->right, newMax);
  }
};
