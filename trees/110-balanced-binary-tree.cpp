// https://leetcode.com/problems/balanced-binary-tree/description/

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

    int checkBalanced(TreeNode *node,bool &result) {
        if(node == nullptr) {
            return -1;
        }
        
        if(node->left == nullptr && node->right == nullptr) {
            return 0;
        }

        int left = checkBalanced(node->left, result);
        int right = checkBalanced(node->right, result);
    
        int depth = (left-right);
        if(abs(depth) > 1) {
            result = false;
        }

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool result=true;
        checkBalanced(root, result);
        return result;
    }
};
