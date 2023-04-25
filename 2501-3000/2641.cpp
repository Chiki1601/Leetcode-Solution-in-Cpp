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
    #define ll long long
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<ll,ll>m;
        map<pair<ll,TreeNode*>,ll>p;
        queue<pair<TreeNode*,TreeNode*>>q,z;
        q.push({root,NULL});
        int d=0;
        while(q.size()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto x=q.front();
                TreeNode* par=x.second;
                TreeNode* act=x.first;
                q.pop();
                int t=0;
                if(par!=NULL)t=par->val;
                p[{d,par}]+=act->val;
                m[d]+=act->val;
                if(act->right!=NULL)q.push({act->right,act});
                 if(act->left!=NULL)q.push({act->left,act});
            }
            d++;
        }
        d=0;

        z.push({root,NULL});
        while(z.size()){
        int k=z.size();
        for(int i=0;i<k;i++)
        {
            auto x=z.front().first;
            auto par=z.front().second;
            z.pop();
            x->val=m[d]-p[{d,par}];
             if(x->right!=NULL)z.push({x->right,x});
                 if(x->left!=NULL)z.push({x->left,x});
        }
            d++;
        }
        return root;
    }
};
