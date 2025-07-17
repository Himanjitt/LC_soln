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

1 4 3 2 5 2

small
          s
-1->1->2->2

large
          l 
-1->4->3->5

*/
class Solution {
public:
    //two separate linked list for large and small 
    //connect them and return the small
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* smallHead = small;
        ListNode* largeHead= large;

        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val < x){
                small->next = curr;
                small = small->next;
            } 
            else{
                large->next = curr;
                large = large->next;
            }
            curr= curr->next;
        }
        large->next = NULL;
        small->next = largeHead->next;

        return smallHead->next;
        
    }
};