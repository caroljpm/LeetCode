// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
        if(root == nullptr) {
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;

        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            int size = nodeQueue.size();

            vector<int> levelRow(size, 0);
            for(int i=0; i<size; i++) {
                auto c = nodeQueue.front();
                if(c->left) {
                    nodeQueue.push(c->left);
                }
                if(c->right) {
                    nodeQueue.push(c->right);
                }
              
                levelRow[i] = c->val;
                nodeQueue.pop();
            }

            if(levelRow.size()) {
                result.emplace_back(levelRow);
            }
        }

        return result;
    }
};
