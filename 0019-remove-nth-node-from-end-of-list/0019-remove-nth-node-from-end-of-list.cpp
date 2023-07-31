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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head==NULL)
        // return head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
           temp=temp->next;
        }
        int m=count-n;
        // ListNode* p=new ListNode(0);
        if(m==0)
            return head->next;
        
        ListNode* temp1=head;
        for(int i=0;i<m-1;i++){
            temp1=temp1->next;
        }
        temp1->next=temp1->next->next;
        return head;
    }
};