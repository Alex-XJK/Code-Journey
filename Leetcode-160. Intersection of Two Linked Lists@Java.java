/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // Get length
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        // Jump to same position
        if (lenA > lenB) {
            headA = jumpN(headA, lenA - lenB);
        } else {
            headB = jumpN(headB, lenB - lenA);
        }
        
        // Compare elements
        while (headA != null && headB != null && headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        
        // Final check whether intersect exist
        ListNode result = (headA != null && headB != null) ? headA : null;
        return result;
    }
    
    private ListNode jumpN(ListNode target, int N) {
        for (int j = 0; j < N; j++) {
            target = target.next;
        }
        return target;
    }
    
    private int getLength(ListNode lit) {
        int cnt = 0;
        while (lit != null) {
            cnt += 1;
            lit = lit.next;
        }
        return cnt;
    }
}