/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {

        head = reverse(head);

        ListNode* t = head;
        int carry = 0;

        while(t) {

            int val = (t->val * 2) + carry;

            t->val = val % 10;
            carry = val / 10;

            if(!t->next) break;

            t = t->next;
        }
        if(carry) {
            t -> next = new ListNode(carry);
            carry = 0;
        }

        return reverse(head);
    }
};