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
    ListNode* reverseH(ListNode* head)
    {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL)
        {
            ListNode* nextNode=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=nextNode;
        }
        return prevNode;
    }
    ListNode* getKth(ListNode* temp,int k)
    {
        while(temp!=NULL)
        {
            k--;
            if(k==0)
            {
                return temp;
                break;
            }
            temp=temp->next;
        }
        return NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL)
        {
            ListNode* kNode=getKth(temp,k);
            if(kNode==NULL)
            {
               if(prevNode) prevNode->next=temp;
               break;
            }
            else
            {
                ListNode* nextNode=kNode->next;
                kNode->next=NULL;
                reverseH(temp);
                if(head==temp)
                {
                    head=kNode;
                }
                else
                {
                    prevNode->next=kNode;
                }
                 prevNode=temp;
            temp=nextNode;
            }
           
        }
        return head;
    }
};