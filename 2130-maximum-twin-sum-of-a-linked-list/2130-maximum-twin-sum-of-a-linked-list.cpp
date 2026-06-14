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
    int pairSum(ListNode* head) {
        vector<int> vec;
        while(head) {
            vec.push_back(head -> val);
            head = head -> next;
        }
        int maxSum = 0;
        int n = vec.size();
        for(int i = 0; i < n; i++) {
            maxSum = max(maxSum, vec[i] + vec[n - i -1]);
        }
        return maxSum;
    }
};