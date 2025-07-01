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
    ListNode* merge(ListNode* list1,ListNode* list2){
         ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummyNode->next;
    }
    ListNode* findmid(ListNode* temp){
        ListNode* slow=temp;
        ListNode* fast=temp;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* midnode=findmid(temp);
        ListNode* leftnode=head;
        ListNode* rightnode=midnode->next;
        midnode->next=NULL;
        leftnode=sortList(leftnode);
        rightnode=sortList(rightnode);
        return merge(leftnode,rightnode);
    }
};