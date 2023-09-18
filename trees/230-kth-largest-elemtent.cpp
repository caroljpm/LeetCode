// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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

    void findKthSmallest(TreeNode *node, int index, int k, vector<int> &result) {
        if(node == nullptr) {
            return;
        }
        
        findKthSmallest(node->left, index, k, result);
        result.emplace_back(node->val);
        findKthSmallest(node->right, index, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        findKthSmallest(root, 0, k, result);
        return result[k-1];
    }
};
