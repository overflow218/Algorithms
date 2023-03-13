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
 #include <queue>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty())
        {
            int limit = q.size();
            bool isFound = false;
            for(int i = 0; i < limit; i++)
            {
                TreeNode * cur = q.front();
                q.pop();
                if(cur == NULL) continue;
                if(!isFound)
                {
                    isFound = true;
                    ans.push_back(cur -> val);
                }
                q.push(cur -> right);
                q.push(cur -> left);
            }
        }
        return ans;
    }
};