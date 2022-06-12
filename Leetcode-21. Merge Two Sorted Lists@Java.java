/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // Check special cases
        if (list1 == null && list2 == null) {
            return null;
        }
        else if (list1 == null) {
            return list2;
        } 
        else if (list2 == null) {
            return list1;
        }
        
        // Determine result
        ListNode result = null;
        if (list1.val <= list2.val) {
            result = list1;
            list1 = list1.next;
        }
        else {
            result = list2;
            list2 = list2.next;
        }
        
        // Merge
        ListNode merged = result;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                merged.next = list1;
                merged = merged.next;
                list1 = list1.next;
            }
            else {
                merged.next = list2;
                merged = merged.next;
                list2 = list2.next;
            }
        }
        
        // Append remainings
        if (list1 == null) {
            merged.next = list2;
        }
        else {
            merged.next = list1;
        }
        
        // Return result node
        return result;
    }
}