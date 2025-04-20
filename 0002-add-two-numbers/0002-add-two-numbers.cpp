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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL){
            int x=0,y=0;
            if(l1!=NULL) x=l1->val;
            if(l2!=NULL) y=l2->val;
            sum=x+y+carry;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            carry=sum/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry!=0){
            temp->next=new ListNode(carry);
            temp=temp->next;
        }
        return dummy->next;
    }
};