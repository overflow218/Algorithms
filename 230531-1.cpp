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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int tmp = 0;
            if(l1 != NULL)
            {
                tmp += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL)
            {
                tmp += l2 -> val;
                l2 = l2 -> next;
            }
            cur -> val = (carry + tmp) % 10;
            carry = (carry + tmp) / 10;
            if(l1 == NULL && l2 == NULL)
            {
                if(carry != 0) cur -> next = new ListNode(carry);
                break;
            }
            cur -> next = new ListNode();
            cur = cur -> next;
        }
        return head;
    }
};