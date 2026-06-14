/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* new_head=nullptr;
    ListNode* final_head=nullptr;
    ListNode* reverse(ListNode* head,int k,ListNode*& next_group)
    {
        if(k==1||head->next==nullptr)
        {
            new_head=head;
            next_group=head->next;
            return head;
        }
        ListNode* temp=reverse(head->next,k-1,next_group);
        temp->next=head;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // so what my approach is i will take the function of reverse linked list...then i will only be reversing till the count becomes k ...and i will remember the last pointer..then i will be again reversing and as my reverse function returns list node...it will be returning fresh reversed list everytime...once i reach n/k groups...i will just stick the next nodes as it is
        ListNode* check=head;
        int count=0;
        while(check!=nullptr&&count<k)
        {
            check=check->next;
            count++;
        }
        if(count<k){
            if(final_head==nullptr)
            {
                final_head=head;
            }
            return head;
        }
        ListNode* next_group=nullptr;
        ListNode* last_node=reverse(head,k,next_group);
        ListNode* current_reversed_head=new_head;
        if(final_head==nullptr)
        {
            final_head=current_reversed_head;
        }
        last_node->next=reverseKGroup(next_group,k);
        return current_reversed_head;
    }
};