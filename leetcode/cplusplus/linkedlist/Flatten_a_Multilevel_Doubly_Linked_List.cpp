/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

/*
    1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
    Iterative mean: merge first layer, then other layer afterward.

    1---2---7---8---9---10---3---4---5---6--NULL
                |
                11--12--NULL
         
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        
        while(cur){
            if(cur->child != NULL){
                Node* next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                Node* last = cur->child;
                cur->child = NULL;
                
                while(last&&last->next){
                    last = last->next;
                }
                
                last->next = next;
                if(next) next->prev = last;
                
            }
            cur = cur->next;
        }
        
        return head;
    }
};