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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count =0;

        ListNode* curr= head;

        while(count < k){
            if(curr == NULL){
                return head;
            }
            curr = curr->next;
            count++;
        }

        ListNode* newNext = reverseKGroup(curr, k);

        count =0;
        curr = head;
        ListNode* fut = head;

        while(count < k){
            fut = curr->next;
            curr->next = newNext;

            newNext= curr;
            curr = fut;
            count++;
        }

        return newNext;

    }
};