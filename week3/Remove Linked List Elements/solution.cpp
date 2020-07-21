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
    ListNode* removeElements(ListNode* head, int val) {
        if( head == NULL ) return head;
        ListNode *cur = head;
        while( cur->next != NULL ) {
            if( cur->next->val == val ) {
                ListNode *temp = cur->next->next;
                delete(cur->next);
                cur->next = temp;
            }
            else cur = cur->next;
        }
        if( head->val == val ) {
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        return head;
    }
};