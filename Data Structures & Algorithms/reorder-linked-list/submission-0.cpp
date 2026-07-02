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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast->next){
            fast  = fast->next->next;
            slow = slow->next;
        }

        ListNode *curr=slow->next, *prev = slow->next = nullptr;
        while(curr !=nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode *start = head;
        curr = prev;
        while(curr){
            ListNode* temp1 = start->next;
            ListNode* temp2 = curr->next;
            start->next = curr;
            curr->next = temp1;
            start = temp1;
            curr = temp2;
        }
        
    }
};
