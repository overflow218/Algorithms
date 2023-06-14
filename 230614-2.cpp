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
    vector<int> vec;
    void visit(TreeNode* root)
    {
        if(!root) return;
        vec.push_back(root -> val);
        visit(root -> right);
        visit(root -> left);
    }
    int getMinimumDifference(TreeNode* root) {
        visit(root);
        sort(vec.begin(), vec.end());
        int ans = 987654321;
        for(int i = 1; i < vec.size(); i++)
        {
            ans = min(ans, vec[i] - vec[i - 1]);
        }
        return ans;
    }
};