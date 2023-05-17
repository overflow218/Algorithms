/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        while(head)
        {
            vec.push_back(head -> val);
            head = head -> next;
        }
        int ans = 0;
        int limit = vec.size();
        for(int i = 0; i < limit / 2; i++)
        {
            ans = max(ans, vec[i] + vec[limit - 1 - i]);
        }
        return ans;        
    }
};