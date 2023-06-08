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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> vec;
        ListNode* iter = head;
        while(iter)
        {
            vec.push_back(iter -> val);
            iter = iter -> next;
        }

        iter = head;
        int cnt = 1;
        while(iter)
        {
            if(cnt == k) iter -> val = vec[vec.size() - k];
            if(cnt == vec.size() - k + 1) iter -> val = vec[k - 1];
            iter = iter -> next;
            cnt++;
        }
        return head;
    }
};