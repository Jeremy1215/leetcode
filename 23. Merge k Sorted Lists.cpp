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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0 ; i < lists.size(); i++) {
            ListNode* head = lists[i];
            while (head != NULL) {
                pq.push(head->val);
                head = head->next;
            }
        }

        if (pq.empty()) return NULL;
        int val = pq.top();
        pq.pop();
        ListNode* cur = new ListNode(val);
        ListNode* head = cur;
        ListNode* pre = cur;
        while (!pq.empty()) {
            val = pq.top();
            pq.pop();

            cur = new ListNode(val);
            pre->next = cur;
            pre = cur;
        }

        return head;
    }
};
