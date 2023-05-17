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
    int pairSum(ListNode* head) {
       ListNode* root=head;
        vector<int>v;
        int ans=0;
        int n=0;
        while(root){
            v.push_back(root->val);
            root=root->next;
            n++;
        }
        int m=n/2-1;
        int i=0;
        int val=0;
        while(i<=m){
            val=v[i]+v[n-i-1];
            ans=max(ans,val);
            i++;
        }
        return ans;
    }
};