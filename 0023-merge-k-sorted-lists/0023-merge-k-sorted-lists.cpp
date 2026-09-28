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
        if(!l1 && !l2) return NULL;
        else if(!l1) return l2;
        else if(!l2) return l1;
        else {
            ListNode* t = NULL, *head = NULL;
            if(l1 -> val <= l2 -> val) {
                head = l1;
                t = l1;
                l1 = l1 -> next;
            }
            else {
                head = l2;
                t = l2;
                l2 = l2 -> next;
            }
            while(l1 && l2) {
                if(l1 -> val <= l2 -> val) {
                    t -> next = l1;
                    l1 = l1 -> next;
                }
                else {
                    t -> next = l2;
                    l2 = l2 -> next;
                }
                t = t -> next;
            }
            if(l1) t -> next = l1;
            else t -> next = l2;
            return head;
        }
        return NULL;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            ListNode* mergedHead = merge2Lists(head, lists[i]);
            head = mergedHead;
        }
        return head;
    }
};