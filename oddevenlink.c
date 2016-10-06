/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode *p = head;
    struct ListNode *odd = head;
    if (!head->next)
        return head;
    struct ListNode *even = head->next;
    struct ListNode *evenhead = even;
    p = p->next->next; 
    while (p) {
        odd->next = p;
        odd = odd->next;
        p = p->next;
        if (!p)
            break;
        even->next = p;
        even = even->next;
        p = p->next;
    }
    odd->next = evenhead;
    even->next = NULL;
    return head;
}