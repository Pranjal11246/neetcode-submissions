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
        if(root->left && root->right){
            int sum = root->left->val + root->val + root->right->val;
            maxsum = max(maxsum,sum);
        }
        maxsum = max(maxsum,maxPathSum(root->left));
        maxsum = max(maxsum,maxPathSum(root->right));
        return maxsum;
    }
};
