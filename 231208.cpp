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

// leetcode 606번
class Solution {
public:
    string ans = "";

    void visit(TreeNode* root)
    {
        if(root == NULL) return;
        ans += to_string(root -> val);

        if(root -> left)
        {
            ans += "(";
            visit(root -> left);
            ans += ")";
        }
        if(root -> right)
        {
            if(!(root -> left)) ans += "()";
            ans += "(";
            visit(root -> right);
            ans += ")";
        }
    }
    string tree2str(TreeNode* root) {
        visit(root);
        return ans;
    }
};
