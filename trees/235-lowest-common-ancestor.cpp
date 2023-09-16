// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* findLowestAncestor(TreeNode *node, TreeNode *p, TreeNode* q) {
        if(node->val > p->val && node->val > q->val) {
            return findLowestAncestor(node->left, p, q);
        } else if(node->val < p->val && node->val < q->val) {
            return findLowestAncestor(node->right, p, q);
        } else {
            return node;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLowestAncestor(root, p, q);
    }
};
