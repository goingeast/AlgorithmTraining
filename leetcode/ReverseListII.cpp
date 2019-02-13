// Reverse a linked list from position m to n.
// 1 <= m <= n <= N

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        if(head == NULL) return NULL;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* prev = &dummyNode;
        
        for(int i = 0; i < m -1; ++i){
            prev = prev->next;
        }
        
        ListNode* cur = prev->next;
        // reverse m - n -1 times
        for(int i = m; i < n; ++i){
            ListNode* temp = cur->next;
            cur->next =  temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummyNode.next;
    }
};