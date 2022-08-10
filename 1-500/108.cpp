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
    TreeNode* fun(vector<int> &nums,int lo,int hi){
        if(lo>hi) return NULL;
     int   mi=(lo+hi)/2;
//Get the middle element and make it root 
        TreeNode* nod= new TreeNode(nums[mi]);
//Recursively construct the left subtree and make it left child of root 
        nod->left=fun(nums,lo,mi-1);
//Recursively construct the right subtree and make it right child of root 
        nod->right=fun(nums,mi+1,hi);
        return nod;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
       return fun(nums,0,n-1);
    }
};
