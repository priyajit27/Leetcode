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
        // ListNode* p=head;
        // ListNode* q=NULL;ListNode* r=NULL;
        // if(head==NULL)return NULL;
        // while(p){
        //     r=q;
        //     q=p;
        //     p=p->next;
        //     q->next=r;
        // }
        // return q;
        
         ListNode* front=head;
        ListNode* temp=NULL;ListNode* prev=NULL;
        if(head==NULL)return NULL;
        while( front){
            prev=temp;
            temp= front;
             front= front->next;
            temp->next= prev;
        }
        return temp;
    }
};