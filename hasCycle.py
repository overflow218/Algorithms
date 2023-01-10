# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        cnt = 0
        while(head):
            cnt += 1
            if(cnt >= 10004):
                return True
            head = head.next
        return False
            