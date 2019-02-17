/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *cur = head;
        for(int i=0; i<k; ++i){
            if(!cur) return head;
            cur = cur->next;
        }
        
        ListNode *newHead = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return newHead;
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        
        while(head != tail){
            ListNode* t = head->next;
            head->next = prev;
            prev = head;
            head = t;
        }
        return prev;
    }
};