# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0, None)
        current = head
        while(list1 or list2):
            if(not list2 or (list1 and list1.val < list2.val)):
                new_node = ListNode(list1.val)
                current.next = new_node
                current = new_node
                list1 = list1.next
            else:
                new_node = ListNode(list2.val)
                current.next = new_node
                current = new_node
                list2 = list2.next
        return head.next