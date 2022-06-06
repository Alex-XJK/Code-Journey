# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        def getLength(node: ListNode) -> int:
            count = 0
            while node:
                count += 1
                node = node.next
            return count
        
        def jumpN(target: ListNode, N: int) -> ListNode:
            for _ in range(N):
                target = target.next
            return target
        
        len1 = getLength(headA)
        len2 = getLength(headB)
            
        if len1 < len2:
            headB = jumpN(headB, len2 - len1)
        else:
            headA = jumpN(headA, len1 - len2)
            
        while headA and headB and headA != headB:
            headA = headA.next
            headB = headB.next
            
        return headA