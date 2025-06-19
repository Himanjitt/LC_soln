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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr=head, *fut = head->next;

        while(fut && fut->next){
            int a = curr ->val;
            curr->val = fut->val;
            fut->val = a;
            curr = curr->next->next;
            fut = fut->next->next;
        }
        if(fut){
            int a = curr ->val;
            curr->val = fut->val;
            fut->val = a;
        }

        return head;


    }
};