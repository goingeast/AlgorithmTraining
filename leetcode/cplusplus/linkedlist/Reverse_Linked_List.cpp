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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newHead = swapPairs(head->next->next);
        
        ListNode* next = head->next;
        
        head->next = newHead;
        next->next = head;
        
        
        return next;
    }
};