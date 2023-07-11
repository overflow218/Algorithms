/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <queue>
 using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target -> val};
        TreeNode* parents[501] = {0};
        bool isVisited[501] = {false};
        vector<int> ans;

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                TreeNode * tmp = q.front();
                q.pop();
                if(tmp == NULL) continue;
                if(tmp -> left != NULL)
                {
                    parents[tmp -> left -> val] = tmp;
                    q.push(tmp -> left);
                }
                if(tmp -> right != NULL)
                {
                    parents[tmp -> right -> val] = tmp;
                    q.push(tmp -> right);
                }
            }
        }

        q.push(target);
        for(int j = 0; j <= k; j++)
        {
            if(q.empty()) break;
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                TreeNode * tmp = q.front();
                q.pop();
                if(tmp == NULL || isVisited[tmp -> val]) continue;
                isVisited[tmp -> val] = true;
                printf("dist: %d, val; %d\n", j, tmp -> val);
                if(j == k) ans.push_back(tmp -> val);
                q.push(tmp -> left);
                q.push(tmp -> right);
                if(parents[tmp -> val]) q.push(parents[tmp -> val]);
            }
        }
        return ans;
    }
};