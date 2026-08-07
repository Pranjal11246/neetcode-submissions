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
        if(root==nullptr || root->left==nullptr || root->right ==nullptr )return true;
        int leftheight = dfs(root->left);
        int rightheight = dfs(root->right);
        if(abs(leftheight-rightheight)>1)return false;
        return true;
    }

    int dfs(TreeNode* root){
        if(!root)return 0;
        int leftmax = dfs(root->left);
        int rightmax = dfs(root->right);

        return 1+max(leftmax,rightmax);
    }
};
