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
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* find(ListNode* temp,int k){
        while(temp!=NULL && k>1){
            temp=temp->next;
            k--;
        }
        if(k>1) return NULL;
        else return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head;
        ListNode* prevnode=NULL;
        ListNode* nextnode=NULL;
        while(temp!=NULL){
            ListNode* kthnode=find(temp,k);
            if(kthnode==NULL){
                if(prevnode){
                    prevnode->next=temp;
                    break;
                }
            }
            nextnode=kthnode->next;
            kthnode->next=NULL;
            ListNode* newhead=reverse(temp);
            if(temp==head) head=newhead;
            if(prevnode){
                prevnode->next=newhead;
            }
                prevnode=temp;
                temp=nextnode;
        }
        return head;
    }
};