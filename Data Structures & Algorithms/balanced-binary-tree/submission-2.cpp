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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        bool leftres = isBalanced(root->left);
        bool rightres = isBalanced(root->right);

        int leftheight = dfs(root->left);
        int rightheight = dfs(root->right);
        if(abs(leftheight-rightheight)<=1 && leftres && rightres)return true;
        return false;
    }

    int dfs(TreeNode* root){
        if(!root)return 0;
        int leftmax = dfs(root->left);
        int rightmax = dfs(root->right);

        return 1+max(leftmax,rightmax);
    }
};
