/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node *cur = head; cur; cur = cur->next) {
            if( cur->child ) {
                Node *next = cur->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                Node *p = cur->next;
                while( p->next ) p = p->next;
                p->next = next;
                if( next ) next->prev = p;
            }
        } 
        return head;
    }
};