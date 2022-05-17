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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head;
        ListNode fuckyou(0);
        fuckyou.next = head;
        ListNode *back = &fuckyou;
        for (int i = 0; i < n; i++) {
            front = front->next;
        }
        while (front) {
            front = front->next;
            back = back->next;
        }
        ListNode *tmp = back->next;
        back->next = back->next->next;
        delete tmp;
        return fuckyou.next;
    }
};