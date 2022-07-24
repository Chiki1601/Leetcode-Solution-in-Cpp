class Solution {
public:
    int acc = 0;
    void inOrder(TreeNode* node){
        //in-order traversal, from right to left
        
        //visit right child
        if(node->right) inOrder(node->right);
        
        //visit itself
        node->val += acc;
        //acc becomes old node->val + acc
        acc = node->val;
        
        //visit left child
        if(node->left) inOrder(node->left);
    };
    
    TreeNode* bstToGst(TreeNode* root) {
        if(root) inOrder(root);
        return root;
    }
};
