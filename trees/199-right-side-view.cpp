// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {

        if(root == nullptr) {
            return {};
        }

        vector<int> result;
        list<TreeNode*> nodeList;
        nodeList.push_back(root);

        while(!nodeList.empty()) {
            int size = nodeList.size();
            result.emplace_back(nodeList.back()->val);
            
            for(int i=0; i<size; i++) {
                auto n = nodeList.front();
                if(n->left) {
                    nodeList.push_back(n->left);
                }

                if(n->right) {
                    nodeList.push_back(n->right);
                }

                nodeList.pop_front();
            }
        }

        return result;
    }
};
