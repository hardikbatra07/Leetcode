/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
       Node* temp=head;
       while(temp!=NULL){
        if(temp->child!=NULL){
            Node* nextnode=temp->next;
            temp->next=flatten(temp->child);
            temp->child->prev=temp;
            temp->child=NULL;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            if(nextnode){
            temp->next=nextnode;
            nextnode->prev=temp;
            }
        }
        else temp=temp->next;
       }
        return head;    
    }
};