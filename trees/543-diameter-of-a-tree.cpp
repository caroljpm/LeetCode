// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int findDepth(TreeNode *node, int &diameter) {
        if(node == nullptr) {
            return -1;
        }

        if(node->left == nullptr && node->right == nullptr) {
            return 0;
        }

        int left = findDepth(node->left, diameter);
        int right = findDepth(node->right, diameter);
        diameter = max(diameter, (left + right + 2)); 
        
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDepth(root, diameter);

        return diameter;
    }
};
