/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* dummyNode, linkedlist god */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddNode(1);
        ListNode evenNode(2);
        
        ListNode* iter1 = &oddNode;
        ListNode* iter2 = &evenNode;
        
        int i = 1;
        while(head){
            if(i++ % 2){
                iter1->next = head;
                iter1 = iter1->next;
            }else{
                iter2->next = head;
                iter2 = iter2->next;
            }
            head = head->next;
        }
        
        iter1->next = evenNode.next;
        iter2->next = NULL;
        return oddNode.next;
    }
};