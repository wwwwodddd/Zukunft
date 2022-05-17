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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        int s = l1->val + l2->val;
        ListNode* next = addTwoNumbers(l1->next, l2->next);
        if (s >= 10) {
            s -= 10;
            ListNode* c = new ListNode(1);
            next = addTwoNumbers(next, c);
        }
        
        ListNode* re = new ListNode(s);
        re->next = next;
        return re;
    }
};