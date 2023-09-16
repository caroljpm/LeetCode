// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

    int calcDepth(TreeNode *node) {
        if(node == nullptr) {
            return 0;
        }

        int left = calcDepth(node->left);
        int right = calcDepth(node->right);

        return max(left, right) + 1;
    }

    int maxDepth(TreeNode* root) {
        return calcDepth(root);
    }
};
