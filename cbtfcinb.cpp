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
 
 #include <algorithm>

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1)
        {
            return root;
        }
        int idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> l1(preorder.begin() + 1, preorder.begin() + idx + 1);
        vector<int> l2(inorder.begin(), inorder.begin() + idx);        
        vector<int> r1(preorder.begin() + idx + 1, preorder.end());        
        vector<int> r2(inorder.begin() + idx + 1, inorder.end());

        TreeNode *left = buildTree(l1, l2);
        TreeNode *right = buildTree(r1, r2);
        root -> left = left;
        root -> right = right;
        return root;
    }
};