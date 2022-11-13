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
    int countSwap(vector<int>& t){
        int count = 0;
        map<int,int> mp;
        vector<int> u;
        for(int i = 0; i < t.size(); ++i){
            mp[t[i]] = i;
            u.push_back(t[i]);
        }
        sort(u.begin(), u.end());
        for(int i = 0; i < t.size(); ++i){
            if(t[i] != u[i] ){  // if not at correct place update the values in map and t array
                t[mp[u[i]]] = t[i];
                mp[t[i]] = mp[u[i]];
                mp[u[i]] = i;
                t[i] = u[i];
                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            while(n--){
                TreeNode* node = q.front();
                t.push_back(node->val);
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            for(auto c: t) cout<<c<<" "; cout<<endl;
            ans += countSwap(t);
        }
        return ans;
    }
};
