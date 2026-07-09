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
    bool res = false;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root ^ !subRoot)return false;
        if(!root && !subRoot)return true;
        if(isSame(root,subRoot)){
            return true;
        }
        res = isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        return res;
    }

    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root ^ !subRoot)return false;
        if(!root && !subRoot)return true;
        bool sameVal = root->val == subRoot->val;
        bool leftres = isSame(root->left,subRoot->left);
        bool rightres = isSame(root->right,subRoot->right);
        return sameVal && leftres && rightres;
    }
};
