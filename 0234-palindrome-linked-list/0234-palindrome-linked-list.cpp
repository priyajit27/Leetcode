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
     ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* newhead=reverseList(head->next);
         ListNode* front=head->next;
          front->next=head;
        head->next=NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
         ListNode* slow=head;
         ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
ListNode* head1=reverseList(slow);
        while(head1){
            if(head1->val!=head->val)return false;
            head1=head1->next;
            head=head->next;
        }
        return true;
    }
};