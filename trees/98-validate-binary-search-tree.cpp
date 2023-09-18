// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool findValidBST(TreeNode *node, int64_t lower, int64_t upper) {
        if(node == nullptr) {
            return true;
        }

        bool inRange = node->val > lower && node->val < upper;
        if(!inRange) {
            return false;
        }

        bool left = findValidBST(node->left, lower, node->val);
        bool right = findValidBST(node->right, node->val, upper);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return findValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
