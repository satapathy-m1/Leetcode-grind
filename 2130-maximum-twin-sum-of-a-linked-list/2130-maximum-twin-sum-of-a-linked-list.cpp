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

        ListNode* reversedHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return reversedHead;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* fH = head, *sH = NULL, *slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        sH = reverseList(slow);
        int maxi = 0;
        while(fH && sH) {
            maxi = max(maxi, (fH -> val + sH -> val));
            sH = sH -> next;
            fH = fH -> next;
        }
        return maxi;
    }
};