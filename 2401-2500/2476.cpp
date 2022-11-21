/*
Approach is to get the sorted list by traversing each node using inorder-traversal.
Then take lower bound and upper bound of each querries to get min and max.

Note: 
There are few conditions that need to be taken care while taking lower and upper bound:
1. when the lower bound index is more than array size -> just take the index of last element
2. when lower bound value is not present in the array -> take just previous value.
3. when upper bound value is evaluated and may be previous value is equal with query -> check and if require take previous index value.
 
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums){
        if(root){
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        inorder(root, nums);
        
        for(auto q: queries){
            int mn = -1, mx = -1;
            if( nums[0] <= q ) mn = (lower_bound(nums.begin(), nums.end(), q)) - nums.begin();
            if( q <= nums.back() ) mx = (upper_bound(nums.begin(), nums.end(), q))-nums.begin();
            
            if(mn > 0 && mn >= nums.size()) mn--;   //when q is larger than nums.back()
            if(mn >= 0 && nums[mn] > q) mn--;         //when q is not present in the nums array
            if(mx > 0 && nums[mx - 1] == q) mx--;    //when q is present in nums, upper bound refer to next element
            
            if(mn != -1) mn = nums[mn];      //get value at index mn
            if(mx != -1) mx = nums[mx];      //get value at index mx
            ans.push_back({mn, mx});
        }
        return ans;
    }
};
