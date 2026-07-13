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
    int kthSmallest(TreeNode* root, int k) {
        int n=0;
        stack<TreeNode*> stk;
        TreeNode *temp = root;
        while(temp || !stk.empty()){
            while(temp){
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            n+=1;
            if(n==k){
                return temp->val;
            }
            temp = temp->right;
        }
        return root->val;
    }
};
