// https://leetcode.com/problems/invert-binary-tree/description/

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

    TreeNode* invert(TreeNode *node) {
        if(node == nullptr) {
            return nullptr;
        }

        swap(node->left, node->right);
        invert(node->left);
        invert(node->right);

        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);   
    }
};
