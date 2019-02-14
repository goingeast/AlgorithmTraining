/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Use stack to reverse linkedlist, while loop is template*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode dummyNode(0);
        ListNode* iter = &dummyNode;
        
        while(!s1.empty() || !s2.empty() || sum){
            int num1 = 0;
            int num2 = 0;
            if(!s1.empty()){
                num1 = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                num2 = s2.top();
                s2.pop();
            }
            
            sum += num1 + num2;
            ListNode* t = iter->next;
            iter->next = new ListNode(sum%10);
            iter->next->next = t;
            sum /= 10;
        }
        
        return dummyNode.next;
    }
};