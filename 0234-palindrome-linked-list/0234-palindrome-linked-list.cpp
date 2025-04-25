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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
       ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp!=NULL){
        ListNode* hee=temp->next;
        temp->next=prev;
        prev=temp;
        temp=hee;
       }
       return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
          }
        ListNode* l2=reverse(slow);
        ListNode* l1=head;
        while(l2!=NULL && l1!=NULL){
            if(l1->val!=l2->val) return false;
            l1=l1->next;
            l2=l2->next;
        }
     return true;
    }
};