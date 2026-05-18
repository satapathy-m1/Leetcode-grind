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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* reversedHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return reversedHead;
    }
    ListNode* addHelper(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = new ListNode(-1);
        ListNode* temp = ansHead;
        int carry = 0;
        while(l1 && l2) {
            int val1 = l1 -> val, val2 = l2 -> val;
            int sum = val1 + val2 + carry;
            ListNode* currNode = new ListNode(sum%10);
            temp -> next = currNode;
            temp = temp -> next;
            carry = sum / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        } 
        while(l1) {
            int val1 = l1 -> val;
            int sum = val1 + carry;
            ListNode* currNode = new ListNode(sum%10);
            temp -> next = currNode;
            temp = temp -> next;
            carry = sum / 10;
            l1 = l1 -> next;
        }
        while(l2) {
            int val2 = l2 -> val;
            int sum = val2 + carry;
            ListNode* currNode = new ListNode(sum % 10);
            temp -> next = currNode;
            temp = temp -> next;
            carry = sum / 10;
            l2 = l2 -> next;
        }
        if(carry) {
            temp -> next = new ListNode(carry);
        }
        return ansHead -> next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* addedLL = addHelper(l1, l2);
        return reverseList(addedLL);
    }
};