# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp = head
        while(head):
            next_node = head.next
            while(next_node and head.val == next_node.val):
                next_node = next_node.next
            head.next = next_node
            head = head.next
        return tmp
            