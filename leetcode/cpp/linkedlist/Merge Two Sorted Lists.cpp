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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tempHead = ListNode(-1);
        ListNode* iter = &tempHead;
        
        while(l1 && l2){
            if(l1->val > l2->val){
                iter->next = l2;
                l2 = l2->next;
            }else{
                iter->next = l1;
                l1 = l1->next;
            }
            iter = iter->next;
        }
        
        if(l1){
            iter->next = l1;
        } else {
            iter->next = l2;
        }
        
        return tempHead.next;
    }
};