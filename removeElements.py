# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        new_head = ListNode(0)
        tmp = new_head
        while(head):
            if(head.val != val):
                new_head.next = ListNode(head.val)
                new_head = new_head.next
            head = head.next
        return tmp.next