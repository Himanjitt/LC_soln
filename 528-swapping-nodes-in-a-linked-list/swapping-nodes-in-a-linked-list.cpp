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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstNode = head;
        ListNode* secondNode = head;
        ListNode* temp = head;

        int size=0;
        while(temp){
            temp = temp->next;
            size++;
        }

        for(int i=0;i<k-1;i++){
            firstNode= firstNode->next;
        }

        for(int i=0;i<size-k; i++){
            secondNode = secondNode->next;
        }


        swap(firstNode->val,secondNode->val);

        return head;
    }
};