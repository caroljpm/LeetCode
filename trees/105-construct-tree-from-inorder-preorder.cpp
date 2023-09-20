// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    unordered_map<int, int> inOrderMap;
    int preIndex;

    TreeNode *treeBuilder(vector<int>& preorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }

        int nodeValue = preorder[preIndex++];
        TreeNode *node = new TreeNode(nodeValue);
        int pivotIndex = inOrderMap[nodeValue];

        //std::cout << "Value :" << nodeValue << ", left :" << left << ", right :" << pivotIndex << std::endl;
        node->left = treeBuilder(preorder, left, pivotIndex-1);
        node->right = treeBuilder(preorder, pivotIndex+1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        for(int i=0; i<inorder.size(); i++) {
            inOrderMap[inorder[i]] = i;
        }

        return treeBuilder(preorder, 0, preorder.size()-1);
    }
};
