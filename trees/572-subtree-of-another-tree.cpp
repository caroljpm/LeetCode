// https://leetcode.com/problems/subtree-of-another-tree/description/

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
    bool checkSubRoot(TreeNode *p, TreeNode *q) {
        if(p == nullptr || q == nullptr) {
            return p==q;
        }

        bool left = checkSubRoot(p->left, q->left);
        bool right = checkSubRoot(p->right, q->right);

        return left && right && p->val==q->val;
    }

    bool traverse(TreeNode *p, TreeNode *q) {
        if(p == nullptr) {
             return false;
        }

        if(p->val == q->val && checkSubRoot(p, q)) {
            return true;
        }

        bool left = traverse(p->left, q);
        bool right = traverse(p->right, q);

        return left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root == nullptr || subRoot == nullptr) {
             return root==subRoot;
         }

         return traverse(root, subRoot);
    }
};
