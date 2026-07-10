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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        queue<TreeNode *> nodequeue;
        nodequeue.push(root);
        while(nodequeue.size()>0){
            vector<int> level;
            int qlen = nodequeue.size();
            for(int i=0;i<qlen;i++){
                TreeNode *node = nodequeue.front();
                nodequeue.pop();
                if(node){
                    level.push_back(node->val);
                    nodequeue.push(node->left);
                    nodequeue.push(node->right);
                }

            }

            if(level.size()>0){
                res.push_back(level);
            }

        }

        return res;
    }
};
