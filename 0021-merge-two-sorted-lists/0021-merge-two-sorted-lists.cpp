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
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
          ListNode* head=new ListNode(0);
          ListNode* temp3=head;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
             temp3->next=temp1;
               temp1= temp1->next;
            }
             else{
                temp3->next=temp2;
                temp2= temp2->next;
            }
            temp3=temp3->next;
        }
        while(temp1){
            temp3->next=temp1;
            temp1=temp1->next;
            temp3=temp3->next;
        }
         while(temp2){
            temp3->next=temp2;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        return head->next;
    }
};