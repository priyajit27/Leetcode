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
       // if(head==NULL || head->next ==NULL)
       //     return head;
       //  ListNode* newnode=reverseList(head->next);
       //  head->next->next=head;
       //  head->next=NULL;
       //  return newnode;
        
        //   ListNode *p,*q,*r;
        // p=head;
        // q=NULL;
        // r=NULL;
        // if(head==NULL)
        //     return NULL;
        // while(p!=0){
        //     r=q;
        //     q=p;
        //     p=p->next;
        //     q->next=r;
        // }
        // // head =q;
        // return q;
        
        
        // Recursive
        if(head==NULL || head->next ==NULL)
            return head;
        
        ListNode* newnode=NULL;
        
        while(head){
           ListNode* next=head->next;
            head->next=newnode;
            newnode=head;
            head=next;
        }
        return newnode;;
    }
};