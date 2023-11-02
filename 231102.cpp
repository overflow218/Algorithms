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

#include <vector>
using namespace std;

# leetcode 2265번 문제
class Solution {
public:
    int cnt = 0;
    // (개수, sum)
    pair<int, int> visit(TreeNode* node)
    {
        if(node == NULL) return make_pair(0, 0);
        pair<int, int> left = visit(node -> left);
        pair<int, int> right = visit(node -> right);
        pair<int, int> tmp = make_pair(left.first + right.first + 1, left.second + right.second + node -> val);
        if(tmp.second / tmp.first == node -> val) cnt++;
        return tmp;
    }
    int averageOfSubtree(TreeNode* root) {
        visit(root);
        return cnt;
    }
};
