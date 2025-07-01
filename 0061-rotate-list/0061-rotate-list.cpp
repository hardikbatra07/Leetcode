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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
          temp=temp->next;
          len++;
        }
        k=k%len;
        if(k==0) return head;
        int dist=len-k;
        temp=head;
        while(dist>1){
          temp=temp->next;
          dist--;
        }
        ListNode* newhead=temp->next;
        ListNode* temp1=newhead;
        temp->next=NULL;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=head;
        return newhead;
    }
};