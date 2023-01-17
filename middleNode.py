# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp_head = head
        cnt = 0
        while(tmp_head):
            tmp_head = tmp_head.next
            cnt += 1
        for _ in range(cnt//2):
            head = head.next
        return head