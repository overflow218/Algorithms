# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    ans = None
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # if(head is None): 
        #     return head
        # tmpHead = ListNode(head.val)
        # head = head.next
        # while(head):
        #     ho = head.next
        #     head.next = tmpHead
        #     tmpHead = head
        #     head = ho
        # return tmpHead

        def reverse(head: Optional[ListNode]):
            if(head is None or head.next is None): 
                self.ans = head
                return head
            nextHead = reverse(head.next)
            head.next = None
            nextHead.next = head
            return head
        reverse(head)
        return self.ans