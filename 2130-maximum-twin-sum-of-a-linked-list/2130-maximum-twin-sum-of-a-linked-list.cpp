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
    ListNode* reverseLL(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* last = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return last;
    }
    int pairSum(ListNode* head) {
        ListNode* lh = head, *rh = NULL, *slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow = reverseLL(slow);
        int maxSum = 0;
        while(slow) {
            maxSum = max(maxSum, (lh -> val + slow -> val));
            lh = lh -> next;
            slow = slow -> next;
        }
        return maxSum;
    }
};