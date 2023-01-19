# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def check(self, prev: Optional[ListNode], cur: Optional[ListNode], n: int):
        if(not cur): 
            return 0
        cnt = self.check(cur, cur.next, n) + 1
        if(cnt == n):
            prev.next = cur.next
        return cnt

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        tmp = ListNode(0)
        tmp.next = head
        self.check(tmp, head, n)
        return tmp.next