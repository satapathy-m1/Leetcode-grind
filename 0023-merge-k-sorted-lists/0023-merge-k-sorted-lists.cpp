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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *temp = NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1 -> val <= l2 -> val) {
            head = l1;
            l1 = l1 -> next;
        }
        else {
            head = l2;
            l2 = l2 -> next;
        }
        temp = head;
        
        ListNode* t1 = l1, *t2 = l2;

        while(t1 && t2) {
            if(t1 -> val <= t2 -> val) {
                temp -> next = t1;
                t1 = t1 -> next;
            }
            else {
                temp -> next = t2;
                t2 = t2 -> next;
            }
            temp = temp -> next;
        }
        if(t1) temp -> next = t1;
        else if(t2) temp -> next = t2;

        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        for(int i = n - 2; i >= 0; i--) {
            lists[i] = merge2Lists(lists[i], lists[i + 1]);
        }
        return lists[0];
    }
};