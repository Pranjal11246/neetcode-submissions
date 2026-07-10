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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* smaller  = (p->val <=q->val)?p:q;
        TreeNode* larger  = (p->val >=q->val)?p:q;
        if(smaller->val <= root->val && root->val <=larger->val){
            return root;
        }else if(smaller->val<root->val && larger->val <root->val){
            return lowestCommonAncestor(root->left,p,q);
        }else{
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }

};
