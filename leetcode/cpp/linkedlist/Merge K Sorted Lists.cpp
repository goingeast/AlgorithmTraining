/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class cmp {
    public:
    bool operator()(const ListNode* l, const ListNode* r){
        return l->val > r->val;  
    }	
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(!pq.empty()){
            ListNode* temp = pq.top(); pq.pop();
            if(head == NULL){
                head = temp;
            } else {
                prev->next = temp;	
            }
            prev = temp;
            if(temp->next) {
                pq.push(temp->next);
            }
        }
        return head;

    }
};