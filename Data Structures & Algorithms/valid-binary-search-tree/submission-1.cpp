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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        bool leftval = isValidBST(root->left);
        bool rightval = isValidBST(root->right);
        bool rootval = true;
        if( root->left && root->val <= root->left->val){
            rootval = false;
        }
        if(root->right && root->val >= root->right->val){
            rootval = false;
        }
        return leftval && rightval && rootval;
    }
};
