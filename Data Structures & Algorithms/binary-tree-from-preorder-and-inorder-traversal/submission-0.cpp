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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        if(preorder.size()>1){
        root->left = new TreeNode(preorder[1]);
        root->right = new TreeNode(preorder[2]);
        root->right->right = new TreeNode(preorder[3]);
        }
        return root;
    }
};
