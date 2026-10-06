/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertbw(Node* head)
    {
        Node*temp=head;
        Node* nextElement=temp->next;
        while(temp!=NULL)
        {
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=copyNode->next;
        }

    }
    void randomptr(Node* head)
    {
        Node* temp=head;
        
        while(temp!=NULL)
        {
            Node* copyNode=temp->next;
            if(temp->random)
            {
                copyNode->random=temp->random->next;
            }
            else
            {
                copyNode->random=NULL;
            }
            temp=temp->next->next;
        }
    }
    Node* nextptr(Node* head)
    {
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        Node* temp=head;
        while(temp!=NULL)
        {
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        insertbw(head);
        
        randomptr(head);
         return nextptr(head);    
         
    }
};