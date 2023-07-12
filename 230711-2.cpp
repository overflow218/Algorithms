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
 #include<queue>
 using namespace std;
class Solution {
public:
    TreeNode* parents[100001] = {0};
    bool isVisited[100001] = {false};
    queue<TreeNode *> q;
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target;
        q.push(root);
        while(!q.empty())
        {
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(!tmp) continue;
                if(tmp -> val == start) target = tmp;
                if(tmp -> left)
                {
                    q.push(tmp -> left);
                    parents[tmp -> left -> val] = tmp;
                }
                if(tmp -> right)
                {
                    q.push(tmp -> right);
                    parents[tmp -> right -> val] = tmp;
                }
            }
        }

        q.push(target);
        int dist = 0;
        int ans = 0;
        while(!q.empty())
        {
            int limit = q.size();
            for(int i = 0; i < limit; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp == NULL || isVisited[tmp -> val]) continue;
                isVisited[tmp -> val] = true;
                ans = max(ans, dist);
                if(tmp -> left) q.push(tmp -> left);
                if(tmp -> right) q.push(tmp -> right);
                if(parents[tmp -> val]) q.push(parents[tmp -> val]);
            }
            dist++;
        }
        return ans;
    }
};