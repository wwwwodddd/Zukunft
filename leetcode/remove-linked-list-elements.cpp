// https://leetcode.com/problems/remove-linked-list-elements

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
        ListNode* tmp;
        tmp -> next = head;
        head = tmp;
        while (head -> next != NULL) {
            if (head -> next -> val == val) {
                head -> next = head -> next -> next;
            } else {
                head = head -> next;
            }
        }   
        return tmp -> next;
    }
};