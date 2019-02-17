/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
                                                                                                                                                                                                                         
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* iter = head;
        while(iter) {
            if(mp.count(iter) == 0)
                mp[iter] = new RandomListNode(iter->label);
            
            if(iter->next) {
                if(mp.count(iter->next) == 0)
                    mp[iter->next] = new RandomListNode(iter->next->label);
                
                mp[iter]->next = mp[iter->next];
            }
            
            if(iter->random){
                if(mp.count(iter->random) == 0)
                    mp[iter->random] = new RandomListNode(iter->random->label);
                mp[iter]->random = mp[iter->random];
            }
            
            iter = iter->next;
        }
        return mp[head];
    }
};