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
private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;
        
        ListNode* last = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return last;
    }
public:

    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* h1 = head;
        ListNode* h2 = slow -> next;
        slow -> next = NULL;
        h2 = reverseList(h2);
        while(h1 && h2) {
            ListNode* t1 = h1 -> next;
            ListNode* t2 = h2 -> next;
            h1 -> next = h2;
            h2 -> next = t1;
            h1 = t1;
            h2 = t2;
        }
    }
};