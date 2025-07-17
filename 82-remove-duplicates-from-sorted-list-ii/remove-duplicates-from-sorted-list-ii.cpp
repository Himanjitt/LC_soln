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

 /*
   p c 
d [1,2,3,3,4,4,5]

 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL){
            
            //case 1 if duplicate
            if(curr->next != NULL && curr->val == curr->next->val){

                while(curr->next != NULL && curr->val == curr->next->val){
                    curr= curr->next;
                }

                curr = curr->next;
                prev->next = curr;
            }
            else{ // no duplicate
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};