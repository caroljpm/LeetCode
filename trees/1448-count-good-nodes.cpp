// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    void getGoodNodes(TreeNode *node, int maxValue, int &result) {
        if(node == nullptr) {
            return;
        }

        if(node->val >= maxValue) {
            result++;
        }

        getGoodNodes(node->left, max(node->val, maxValue), result);
        getGoodNodes(node->right, max(node->val, maxValue), result);
    }
    int goodNodes(TreeNode* root) {
        int result = 0;
        int maxValue = INT_MIN;

        getGoodNodes(root, maxValue, result);
        return result;
    }
};
