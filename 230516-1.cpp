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
    vector<int> vec;
    void find(TreeNode* root) {
        if(root == NULL) return;
        find(root -> left);
        vec.push_back(root -> val);
        find(root -> right);
    }
    int kthSmallest(TreeNode* root, int k) {
        find(root);
        return vec[k - 1];
    }
};