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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL, *temp = head;
        int cnt = 1;
        while(temp && cnt < left) {
            prev = temp;
            temp = temp -> next;
            cnt++;
        }

        ListNode *temp2 = temp;
        while(temp && cnt < right) {
            temp = temp -> next;
            cnt++;
        } 

        ListNode* front = temp -> next;
        temp -> next = NULL;
        if(prev) prev -> next = reverseList(temp2);
        else head = reverseList(temp2);
        temp2 -> next = front;
        return head;
    }
};