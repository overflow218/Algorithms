# leetcode no.515
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int limit = q.size();
            int localMax;
            bool isFirst = true;
            for(int i = 0; i < limit; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp == NULL) continue;
                if(isFirst || localMax < tmp -> val)
                {
                    isFirst = false;
                    localMax = tmp -> val;
                }
                q.push(tmp -> left);
                q.push(tmp -> right);
            }
            if(!isFirst) ans.push_back(localMax);
        }

        return ans;
    }
};

/*
이게 바깥에서부터 자르면서 들어와야함. 
왼쪽 시작 ... 오른쪽 시작 
했을때 왼쪽 == 오른쪽이 되는 지점을 기준으로 오케이 2개 + 다시 반복 ... 이렇게 해서 
DP로 해결하면 될듯?
총 1000글자니까 1000 * 1000 하면 메모리도 충분쓰
*/
// leetcode #516
#include <cstring>
class Solution {
public:

    int cache[1000][1000];
    int cut(int start, int end, string &s)
    {
        if(start > end) return 0;
        if(start == end) return 1;
        int &ret = cache[start][end];
        if(ret != -1) return ret;
        if(s[start] == s[end]) return ret = 2 + cut(start + 1, end - 1, s);
        return ret = max(cut(start + 1, end, s), cut(start, end - 1, s));
    }

    int longestPalindromeSubseq(string s) {
        memset(cache, -1, sizeof(cache));
        return cut(0, s.size() - 1, s);
    }
};
