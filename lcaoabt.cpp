/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isExist(TreeNode* root, int target) {
        // 본인이 최상단인 경우
        if(root == NULL) return false;
        if(root -> val == target) return true;
        return isExist(root -> left, target) || isExist(root -> right, target);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 본인이 최상단인 경우
        if(root -> val == p -> val || root -> val == q -> val) return root;
        bool pOnLeft = isExist(root -> left, p -> val);
        bool qOnLeft = isExist(root -> left, q -> val);

        // 둘다 왼쪽 서브트리에 있음
        if(pOnLeft && qOnLeft) return lowestCommonAncestor(root -> left, p, q);
        // 둘다 오른쪽 서브트리에 있음
        if(!pOnLeft && !qOnLeft) return lowestCommonAncestor(root -> right, p, q);
        // root 사이에 있음
        return root;

    }
};