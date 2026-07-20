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
    int ans=0;
    int dfs(TreeNode* root){
        if(!root)return 0;

        int leftMax=dfs(root->left);
        int rightMax=dfs(root->right);
        int currMax = max({root->val,leftMax,rightMax});

        if(root->val==currMax) ans++;
        return currMax;
    }
    int countDominantNodes(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};
