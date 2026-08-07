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
private:
    int maxsum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)return maxsum;
        int leftgain = getMax(root->left);
        int rightgain = getMax(root->right);
        maxsum = max(maxsum,root->val + leftgain+rightgain);
        maxPathSum(root->left);
        maxPathSum(root->right);
        return maxsum;
    }

    int getMax(TreeNode* root){
        if(!root)return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + left + right;
        return max(0,path);    
    }
};
